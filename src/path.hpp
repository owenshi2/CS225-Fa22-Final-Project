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
    bool circuitExists(std::map<std::string, City> start) {
      for (auto const& x : start)
      {
        if (x.second.c_cities.size() % 2 == 1) {
          return false;
        }
      }
      return true;
    }
    std::string findCircuit(std::map<std::string, City> start)
    {
      std::map<std::string, int> edgecount;
      for (auto const& x : start)
      {
        edgecount.insert({x.first, x.second.c_cities.size()});
      }
      std::stack<City> curr;
      std::vector<City> circuit;
      curr.push((*start.begin()).second);
      City curr_ver = (*start.begin()).second;
      while(!curr.empty())
      {
        if(edgecount.at(curr_ver.name))
        {
          curr.push(*(start[curr_ver.name]).c_cities.at(start[curr_ver.name].c_cities.size() - 1));
          edgecount[curr_ver.name]--;
          curr_ver = curr.top();
        } else
        {
          circuit.push_back(curr.top());
          curr_ver = curr.top();
          curr.pop();
        }
      }
      std::string ret;
      for(unsigned i = 0; i < circuit.size(); i++)
      {
        ret += circuit.at(i).name;
        if(i != circuit.size() - 1)
        {
          ret += " -> ";
        }
      }
      return ret;
    }
};