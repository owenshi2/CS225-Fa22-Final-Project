#include "parser.h"
#include "cities.h"
#include <iostream>
#include <fstream>
#include <ios>

std::unordered_map<City, std::vector<City>> graphCreation(const std::string & citiesData, const std::string& flightPaths,
                                                        std::unordered_map<std::string, std::tuple<std::string, std::string, unsigned>>& IATAtoCity){
    // Your code here!
    std::unordered_map<City, std::vector<City>> graph;
    std::fstream c(citiesData);
    if(!c.is_open()) throw std::runtime_error("cities file not open");
    std::fstream fli(flightPaths);
    if(!fli.is_open()) throw std::runtime_error("flight file not open");
    std::string line, line2, entry, entry2;

    /* populate the mapping between an iata code and the relevant city data*/
    while (std::getline(c, line2)) {
        // std::cout << "cities line access" << std::endl;
        std::vector<std::string> inside;
        line.erase(remove_if(line2.begin(), line2.end(), isspace), line2.end());
        std::stringstream f(line2);
        while(getline(f, entry2, ',')) {
            inside.push_back(entry2);
        }
        std::tuple<std::string, std::string, int> IATATuple = std::make_tuple(inside.at(0), inside.at(2), (unsigned) std::stoi(inside.at(3)));
        IATAtoCity.insert(std::make_pair(inside.at(1), IATATuple));
    }

    /*take the data from the last mapping and use it to populate the graph*/
    while(std::getline(fli, line)) {
        std::vector<std::string> inside;
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
        std::stringstream s(line);
        while(getline(s, entry, ',')) {
            inside.push_back(entry);
        }
        //going to cross reference this with the cities-data csv to identify a city, add that city to the graph
        std::string IATA = inside.at(1);

        //city creation using the IATA map 
        City temp = makeCity(IATA, IATAtoCity);
        
        if (graph.count(temp) == 0) {
            std::vector<City> adjacent;
            graph.insert(std::make_pair(temp, adjacent));
        } else {
            (*graph.find(temp)).second.push_back(makeCity(inside.at(2), IATAtoCity));
        }
    }
    return graph;
}

int main(int argc, char* argv[])
{
  // std::cout << "Make Keli." << std::endl;
  // std::fstream f("src/cities-data.csv");
  // if(!f.is_open()) throw std::runtime_error("Could not open file");
  // std::string buffer, stupid, crazy;
  // std::vector<std::string> lines;
  // while (f >> buffer)
  // {
  //   std::getline(f, stupid);
  //   std::stringstream s(stupid);
  //   while (std::getline(s, crazy, ','))
  //   {
  //     std::cout << "Crazy: " << crazy << std::endl;
  //     lines.push_back(crazy);
  //   }
  // }
  // // std::cout << lines.size() << std::endl;
  // // for (unsigned i = 0; i < lines.size(); i++)
  // // {
  // //   std::cout << lines[i];
  // // }
  // std::vector<City> cities;
  // for(unsigned i = 0; i < lines.size(); i++)
  // {
  //   int mod4 = i % 4;
  //   City cTemp;
  //   if(mod4 == 0)
  //   {
  //     cTemp.ISO = lines[i];//iso
  //   } else if(mod4 == 1)
  //   {
  //     cTemp.iata = lines[i];//iata
  //   } else if(mod4 == 2)
  //   {
  //     cTemp.name = lines[i];//name
  //   } else
  //   {
  //     cTemp.Population = stoi(lines[i]);//population
  //   }
  //   if(mod4 == 2)
  //   {
  //     std::cout << "City parse: " << cTemp.name << "; Pop: " << cTemp.Population << std::endl;
  //   }
  // }
  // std::cout << "Work" << std::endl;


// maps IATA to ISO, City, Population. Tuple's first is ISO, second is city, third is population
  std::unordered_map<std::string, std::tuple<std::string, std::string, unsigned>> IATAtoCity;

  std::unordered_map<City, std::vector<City>> graph = graphCreation("src/cities-data.csv", "src/flight-paths.csv", IATAtoCity);

  std::cout << "graph size: " << graph.size() << std::endl;
  return -1;
}