# Complete Results

## Summary of Algorithm Full-Scale Run

### Breadth-First Search Traversal

#### Output

After parsing and cleaning the data, we used breadth-first search to populate each city on the graph with infection data. We give the first city an infection rate of 1 and set all of its neighbors with an infection of 0.5. Afterwards, every infection rate of a neighbor of the current city will be calculated by multiplying the current city’s infection rate by 0.5. This illustrates the effect of how the infection slows down over time. The return value of bfs will be how many different cities we have visited during the traversal given a starting node. We did by including a set that accounts for all the unique cities visited in a bfs traversal.               

#### Correctness        

As we intended to traverse the graph data set, it was straightforward to see that this algorithm was fully functional when each city connected was populated with external data. Also, the output of bfs shows that we are able to accomplish the traversal by visiting a certain number of cities. 

### Dijkstra's Algorithm

Our Dijkstra’s implementation is reliant on a minHeap implementation for its priority queue. This implementation consists of a vector with a root node indexed at 1 with support for heapify, push, peek, and pop operations. The vector contains pairs which attribute weights to cities which are represented by strings. 

Prior to the establishment of predecessors, each node is assigned an “infinite” weight of 999,999,999 (no cities have a population that large so it works in practice) and a false visitation (as we don’t want to repeatedly visit nodes). We initialize our heap, assign our starting node a weight of 0, and push it to the heap. 

While the heap is not empty:

Obtain the highest priority node, mark it as visited, and then find the corresponding City struct using the name of the city (string) with a mapping. 

Look through the cities adjacent to the node. If they have not been visited, initialize an additive cost (“weight”) which is the population of the neighboring city.  If this cost + the cost to reach the highest priority parent node is less than the current best cost to reach the node in question, initialize the highest priority node as the predecessor of the neighboring node.  Assign the cost of reaching the neighbor as this new best cost (neighboring city population + cost to reach the highest priority parent node). Insert this neighboring node and its associated cost into the priority queue.

Return the mapping of predecessors. 

#### Output

The output is a mapping for every city node to an adjacent city predecessor which is established by finding the shortest path to each node from an initial location provided by the user. This output is subsequently used by the unnoticedTravel function to backtrack from the destination node to the start node, populating a vector of strings which correlates to the locations visited in the path. The starting node is added to the vector as the last element and this output is reversed to put it in the correct order. Our interface prints out the contents of this vector once parameters have been provided by the user.

#### Correctness
If the destination node is reachable by BFS, we can expect that there will be a path of predecessors leading from the starting node to the destination. If the nodes are adjacent, we can expect an output of just the starting node and destination. If either node is not in the graph or the nodes are not connected, we can expect a vector of size 1 indicating that the nodes in question are not connected.  

### Hierholzer's Algorithm

#### Output

We implemented this algorithm since we wanted to know of a guaranteed path in the case of airlines shutting down by the assumption that airlines will shut down when an infected board. To account for this, we designed an algorithm that automatically searches for an Euler circuit given a graph to guarantee a path for infection to spread. This can be seen by the output of a vector containing the names of each city to visit as the path to take, and can also be seen by the print to console of each element of the vector.

#### Correctness

The algorithm works well under the constraints of the inputted graph having an Euler circuit; however, we have additionally included a short check before running the circuit finder that ensures the input contains the Euler path we’re looking for.

## Leading Question 

Our dataset analysis program aims to simulate a virgin-soil environmental epidemic spread through a connected graph. The data will include the node values as the population of major cities of the world and feature a graph structure using flight data representing the edges. We will use a public csv file from Openflights and consider the adjacent nodes as direct flights from one city to another. We aim to simulate how long it takes for a city’s infection to reach another city (BFS). 

### Discovery

A lot of airports are different from IATA codes.This is probably due to outdated datasets that cause mismatch between airports and IATA codes. We discovered this while running  Dijkstra's algorithms. 
There are many cities with no airports connecting them to neighboring cities. 
It was very important to do data cleaning before reading the actual datasets. Uncleaned datasets are hard to deal with and it will cause unexpected problems while running the three graph algorithms. For example, the bfs was traversal over empty values when the data was not cleaned. 
Using Hierholzer’s Algorithm, we were able to find that the original dataset was not able to support an Euler circuit due to a few odd edges for the cities.
