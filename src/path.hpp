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
    void findCircuit(std::map<std::string, City> start)
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
      for(unsigned i = 0; i < circuit.size(); i++)
      {
        std::cout << circuit.at(i).name;
        if(i != circuit.size() - 1)
        {
          std::cout << " -> ";
        }
      }
    }
};