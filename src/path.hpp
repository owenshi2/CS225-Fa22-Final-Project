#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include "cities.h"

class Circuit
{
  public:
    void findCircuit(std::vector<City> start)
    {
      std::map<std::string, int> edgecount;
      for (int i = 0; i < start.size(); i++)
      {
        edgecount.insert({start.at(i).name, start.at(i).c_cities.size()});
      }
      std::stack<std::string> curr;
      std::vector<std::string> circuit;
      curr.push(start.at(0).name);
      std::string curr_ver = start.at(0).name;
      while(!curr.empty())
      {
        if(edgecount.at(curr_ver) > 0)
        {
          auto it = std::find(start.begin(), start.end(), curr_ver);
          (*it).name;
          curr.push(start.at(curr_ver))
        }
      }
    }
};