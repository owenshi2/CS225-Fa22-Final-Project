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
      std::stack<City> curr;
      std::vector<City> circuit;
      curr.push(start.at(0));
      City curr_ver = start.at(0);
      while(!curr.empty())
      {
        if(edgecount.at(curr_ver.name) > 0)
        {
          auto it = std::find(start.begin(), start.end(), curr_ver);
          curr.push(*(*it).c_cities.at((*it).c_cities.size()-1));
          auto it2 = edgecount.find(curr_ver.name);
          if(it2 != edgecount.end())
          {
            it2->second -= 1;
          }
          curr_ver = curr.top();
        } else
        {
          circuit.push_back(curr.top());
          curr_ver = curr.top();
          curr.pop();
        }
      }
      for(unsigned i = circuit.size()-1; i >= 0; i--)
      {
        //System.out.println();
        std::cout << circuit.at(i).name << std::endl;
        if(i != 0)
        {
          std::cout << " -> ";
        }
      }
    }
};