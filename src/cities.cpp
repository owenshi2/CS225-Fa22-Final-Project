#include "cities.h"


#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <queue>

//need this for a set
bool operator<(const City &left, const City &right)
{
    return left.Population < right.Population;
}

int bfs(const City& c) {
    //initilize variables 
    std::set<std::string> visited; 
    std::queue<City> neighbors; 
    //add the city to visted nodes
    visited.insert(c.name);  
    //add neighbors to the vistied queue 
    for (unsigned i = 0; i < c.c_cities.size(); i++) {
        neighbors.push(*c.c_cities[i]);     
    }
    //use queue to traverse the entire graph 
    int total = 0; 
    while (!neighbors.empty())
    {
        City curr = neighbors.front(); 
        visited.insert(curr.name);
        std::cout << "name: " << curr.name << std::endl; 
        neighbors.pop(); 
        total++; 
        for (unsigned i = 0; i < curr.c_cities.size(); i++) {
            if (visited.find(curr.c_cities[i]->name) == visited.end()) {
                neighbors.push(*curr.c_cities[i]);
            }  
        }     

    }
    return total; 
    
}


