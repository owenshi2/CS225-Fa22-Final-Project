#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <queue>


struct City
{
  std::string Population;
  std::string iata; 
  std::string ISO; 
  std::string name; 
  std::vector<City*> c_cities;      
  
  double infection_rate = (float)rand()/RAND_MAX;     

  friend bool operator< (const City &left, const City &right);
};

int bfs(City& c); 
