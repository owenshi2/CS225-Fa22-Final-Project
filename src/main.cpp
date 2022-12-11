#include "parser.h"
#include "cities.h"
#include "minheap.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <map>
#include <assert.h>


/*GOAL: how to get from one location to another while minimizing infection, conceptually evading detection*/

std::map<std::string, std::string> dijkstra(const City& start, const std::vector<City>& cities,
                                            std::map<std::string, City>& nameToCity) {
  std::map<std::string, std::string> predecessors; //each node has a predecessor, initiallized null

  std::map<std::string, bool> visited; /*each location can only be visited once*/
  std::map<std::string, unsigned> dis; /*each node has an associated cost to reach*/

  for (unsigned i = 0; i < cities.size(); ++i) {
    visited[cities.at(i).name] = false;
    dis[cities.at(i).name] = (unsigned)-1; /*infinite cost to get to each node initially*/
  }
 
  dis[start.name] = 0; /*cost to get to first node from first node is 0*/

  std::vector<std::string> steps;

  Heap pq; /*every city except start conceptually initialized with infinite distance*/
  pq.insert(0, start.name);

  while (!pq.empty()) {
    /*highest priority elem is the one with the lowest cost to reach*/
    std::pair<unsigned, std::string> top = pq.pop();
    std::cout << "top: " << top.second << std::endl;
  
    visited[top.second] = true;

    City topcity = nameToCity[top.second];
    std::cout << "topcity name: " << topcity.name << std::endl;
    std::cout << "adj cities size: " << topcity.c_cities.size() << std::endl;
    

    for (auto k : topcity.c_cities) {
      std::cout << "adjacent city: " << k->name << std::endl;
      if (visited[k->name]) continue; /*ignore if already visited*/
      double weight = std::stod(k->Population); /*weighting based off of population*/
      if ((unsigned)weight + top.first < dis[k->name]) {
        dis[k->name] = (unsigned) weight + top.first;
        predecessors[k->name] = top.second;
        pq.insert(dis[k->name], k->name);
      }
    }
  }
  std::cout << "predecessors size: " << predecessors.size() << std::endl;
  return predecessors;
}

std::vector<std::string> unnoticedTravel(const std::string& start, const std::string& destination,
                                        std::map<std::string, City>& nameToCity, std::vector<City> cities) {
  std::map<std::string, std::string> pred = dijkstra(nameToCity[start], cities, nameToCity);
  std::string tracker = destination;
  std::vector<std::string> locations;

  while (tracker != start) {
    locations.push_back(tracker);
    tracker = pred[tracker];
  }
  std::reverse(locations.begin(), locations.end()); //put the steps in order since we were backtracking

  return locations;
}

int main(int argc, char* argv[])
{
  std::map<std::string, City> cityIata;
  std::map<std::string, City> nameToCity;
  std::vector<std::string> lines;
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
          //std::cout << cell << std::endl;
      }
  }
  data.close();
    
    // return result;
  //std::cout << lines.size() << std::endl;
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
   // std::cout << "City parse: " << cTemp.name << "; Pop: " << cTemp.Population << "; iata: " << cTemp.iata << "; iso: " << cTemp.ISO << std::endl;
    cityIata[cTemp.iata] = cTemp;
    nameToCity[cTemp.name] = cTemp;
    cities.push_back(cTemp);
    assert(!cities.empty());
  }
  //std::cout << "Works, number of cities is: " << cities.size() << std::endl;
  lines.clear();


  //airlines
  // std::vector<std::string> edges;
  std::ifstream  flights("src/flight-paths.csv");

    std::string path;
    while(std::getline(flights,path))
    {
        std::stringstream  lineStream(path);
        std::string        value;
        int ind = 0;
        std::string prev;
        while(std::getline(lineStream,value,','))
        {
            // You have a cell!!!!
            if (ind == 1) {
              prev = value;
            }
            if (ind == 2) {
              cityIata[prev].c_cities.push_back(&(cityIata[value]));
            }
            ind++;
            // std::cout << value << std::endl;
        }
    }  

    //std::cout<< cityIata["AER"].c_cities.size()<<std::endl;
  std::vector<std::string> uT = unnoticedTravel("Chicago", "New York", nameToCity, cities);
  for (auto el : uT) {
    std::cout << el << std::endl;
  }

  return -1;
}