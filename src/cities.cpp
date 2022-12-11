#include "cities.h"


#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <queue>

//need this for using a set in bfs 
bool operator<(const City &left, const City &right)
{
    return left.Population < right.Population;
}


//traverse the entire to infect population 
int bfs(City& c) {
    //initilize variables  
    std::set<std::string> visited;        
    std::queue<City*> neighbors;   
    //add the city to visted nodes
    visited.insert(c.name);  
    //add neighbors to the vistied queue 
    for (unsigned i = 0; i < c.c_cities.size(); i++) {
        neighbors.push(c.c_cities[i]);     
    } 
    //use queue to traverse the entire graph  
    int total = 0;   
    unsigned new_cities = 0; 
    while (!neighbors.empty())  
    {
        City curr = *neighbors.front();  
        neighbors.front() -> infection_rate = 0; //(float)rand()/RAND_MAX;  //infection rate is not updated correctly 
        visited.insert(curr.name);      
        std::cout << "name: " << curr.name << std::endl; 
        neighbors.pop();                       
        total++;    
        for (unsigned i = 0; i < curr.c_cities.size(); i++) {
            if (visited.find(curr.c_cities[i]->name) == visited.end()) { //see if the ciies are visited or not by checking their names
                neighbors.push(curr.c_cities[i]);  
                new_cities++;            
            }    
        } 
           
        //find the ratio of infected cities:  
        // double ratio;
        // if (curr.c_cities.size() == 0) { 
        //     ratio = 0;  
        // } else {
        //     ratio = 1 - (new_cities / curr.c_cities.size()); 
        // }  
        //curr.infection_rate = ratio;  
          

        //infect the city
        // if (ratio < 0.25) {
        //     curr.infected = int(0.2 * curr.Population);   
        // } else if (ratio >= 0.25 && ratio < 0.5) {
        //     curr.infected = int(0.5 * curr.Population); 
        // } else if (ratio >= 0.5 && ratio < 0.75) {
        //     curr.infected = int(0.75 * curr.Population); 
        // } else {
        //     curr.infected = int(0.95 * curr.Population);
        // } 
        //new_cities = 0; 
    }
    return total;   
    
}

