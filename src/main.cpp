#include "parser.h"
#include "cities.h"
#include <iostream>
#include <fstream>
#include <ios>

int main(int argc, char* argv[])
{
  // std::cout << "Make Keli." << std::endl;
  // std::fstream f("src/cities-data.csv");
  // if(!f.is_open()) throw std::runtime_error("Could not open file");
  // std::string buffer, stream, values;
  std::vector<std::string> lines;
  // while (f >> buffer)
  // {
  //   std::getline(f, stream);
  //   std::stringstream s(stream);
  //   while (std::getline(s, values, ','))
  //   {
  //     std::cout << "Values: " << values << std::endl;
  //     lines.push_back(values);
  //   }
  // }
    std::ifstream  data("src/cities-data.csv");

    std::string line;
    while(std::getline(data,line))
    {
        std::stringstream  lineStream(line);
        std::string        cell;
        while(std::getline(lineStream,cell,','))
        {
            // You have a cell!!!!
            lines.push_back(cell);
            std::cout << cell << std::endl;
        }
    }
    
    // return result;
  // std::cout << lines.size() << std::endl;
  // for (unsigned i = 0; i < lines.size(); i++)
  // {
  //   std::cout << lines[i];
  // }
  std::vector<City> cities;
  for(unsigned i = 4; i < lines.size(); i+=4)
  {
    City cTemp;
    cTemp.ISO = lines[i];//iso
    cTemp.iata = lines[i+1];//iata
    cTemp.name = lines[i+2];//name
    cTemp.Population = lines[i+3];//population
    std::cout << "City parse: " << cTemp.name << "; Pop: " << cTemp.Population << "; iata: " << cTemp.iata << "; iso: " << cTemp.ISO << std::endl;
    cities.push_back(cTemp);
  }
  std::cout << "Works, number of cities is: " << cities.size() << std::endl;

  return -1;
}