#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <queue>

// class City
// {
//   public:
//     City();
//     void setPop(int pop);
//     int getPop();
//     double distanceFrom(City c);
//     void addDistanceFrom();
//     int getNumFlightPaths();
//     void addFlight();
//   private:
//     int numFlightPaths;
//     int pop;
//     std::vector<std::string> airports;
//     std::vector<int> flightDists;
//     std::vector<City> connectedCities;
// };

struct City
{
  std::string Population;
  std::string iata; 
  std::string ISO; 
  std::string name; 
  std::vector<City*> c_cities;      
  
  double infection_rate;    

  friend bool operator< (const City &left, const City &right);
};

int bfs(const City& c); 
