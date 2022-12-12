#include "parser.h"
#include "cities.h"
#include "minheap.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <map>
#include <assert.h>


/*GOAL: how to get from one location to another while minimizing infection, conceptually evading detection*/

std::map<std::string, std::string> dijkstra(const City& start, std::map<std::string, City>& nameToCity) {

  //std::cout << "nc mapping first node adj size: " << (*nameToCity.begin()).second.c_cities.size() << std::endl;
  std::map<std::string, std::string> predecessors; //each node has a predecessor, initiallized null

  std::map<std::string, bool> visited; /*each location can only be visited once*/
  std::map<std::string, size_t> dis; /*each node has an associated cost to reach*/

  for (auto it = nameToCity.begin(); it != nameToCity.end(); ++it) {
    visited[it->first] = false;
    dis[it->first] = 999999999; /*infinite cost to get to each node initially*/
  }
 
  dis[start.name] = 0; /*cost to get to first node from first node is 0*/

  Heap pq; /*every city except start conceptually initialized with infinite distance*/
  pq.insert(0, start.name);

  while (!pq.empty()) {
    /*highest priority elem is the one with the lowest cost to reach*/
    std::pair<unsigned, std::string> top = pq.pop();
    //std::cout << "top: " << top.second << std::endl;
  
    visited[top.second] = true;

    City topcity = nameToCity[top.second];
    //std::cout << "topcity name: " << topcity.name << std::endl;
    //std::cout << "adj cities size: " << topcity.c_cities.size() << std::endl;
    
    for (auto k : topcity.c_cities) {
      //std::cout << "adjacent city: " << k->name << std::endl;
      if (visited[k->name]) continue; /*ignore if already visited*/
      double weight = std::stod(k->Population); /*weighting based off of population*/
      if ((size_t)weight + top.first < dis[k->name]) { /*if there is a better path (smaller cost to get there), update*/
        dis[k->name] = (size_t) weight + top.first;
        predecessors[k->name] = top.second;
        std::cout << "pred of " << k->name << ": " << predecessors[k->name] << std::endl;
        pq.insert(dis[k->name], k->name);
      }
    }
  }
  return predecessors;
}

std::vector<std::string> unnoticedTravel(const std::string& start, const std::string& destination,
                                        std::map<std::string, City> nameToCity) {
  std::map<std::string, std::string> pred = dijkstra(nameToCity[start], nameToCity);
  std::string tracker = destination;
  std::vector<std::string> locations;
  std::vector<std::string> failure(1, "Your destination airport is not connected to the starting airport.");

  while (tracker != start) {
    locations.push_back(tracker);
    if (tracker != "") {
      std::cout << "tracker: " << tracker << std::endl;
      std::cout << "start: " << start << std::endl;
      std::cout << "predecessor: " << pred[tracker] << std::endl;
    }
    if (pred[tracker] == "") {
      return failure;
    }
    tracker = pred[tracker];
  }
  locations.push_back(start);
  std::reverse(locations.begin(), locations.end()); //put the steps in order since we were backtracking

  return locations;
}

int main(int argc, char* argv[])
{
  std::map<std::string, City> cityIata;
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

  cities.clear();
  for (const auto &s : cityIata)
    cities.push_back(s.second);
  std::map<std::string, City> nameToCity;
  std::vector<City> cities_new;
  for (unsigned i = 0; i < cities.size(); i++) {
    if (cities[i].name.size() != 0 && cities[i].c_cities.size() != 0) {
      std::vector<City*> c_cities_temp;
      /*initialize the city mapping*/
      nameToCity[cities[i].name] = cities[i];
      /*clear out the current c_cities so we can push in the cleaned up version*/
      nameToCity[cities[i].name].c_cities.clear();
      for (unsigned j = 0; j < cities[i].c_cities.size(); j++) {
        //std::cout << cities[i].c_cities.size() << std::endl;
        if (cities[i].c_cities[j]->name.size() != 0 ) {
          c_cities_temp.push_back(cities[i].c_cities[j]);
          //std::cout << cities[i].c_cities[j]->name;
          /*push in the cleaned up c_cities*/
          nameToCity[cities[i].name].c_cities.push_back(cities[i].c_cities[j]);
        }
        //cities[i].c_cities = c_cities_temp;          
      }
      cities[i].c_cities = c_cities_temp; 
      
      cities_new.push_back(cities[i]);
    }
  } 

    //std::cout<< cityIata["AER"].c_cities.size()<<std::endl;
  std::vector<std::string> uT = unnoticedTravel("Chicago", "New York", nameToCity);
  for (auto elem : uT) {
    std::cout << elem << std::endl;
  }
  // for (auto el : uT) {
  //   std::cout << el << std::endl;
  // }

  return -1;
}