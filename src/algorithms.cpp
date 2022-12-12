#include <vector>
#include <string>
#include <map>
#include "cities.h"
#include "minheap.h"
#include <ios>
#include <utility>
#include <iostream>
#include <algorithm>


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
        //std::cout << "pred of " << k->name << ": " << predecessors[k->name] << std::endl;
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