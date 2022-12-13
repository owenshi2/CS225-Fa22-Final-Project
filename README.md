# CS225-Fa22-Final-Project
**Video Link**
https://mediaspace.illinois.edu/edit/1_ofn1oq5t

**Leading Question**: 
 Our dataset analysis program aims to simulate a virgin-soil environmental epidemic spread through multiarray infection vectors. The data will include the node values as the population of major cities of the world and feature a graph structure using flight data representing the edges. We will use a public csv file from Openflights and consider the adjacent nodes as direct flights from one city to another. We aim to simulate how long it takes for a city’s infection to reach another city (BFS). 
 
 A representation of developed immunity will be accomplished through the use of Heirholzer’s algorithm, where the detection of repeat visits to a node will factor into the node’s resistance towards infection. Prim’s algorithm offers us a minimum spanning tree of our graph, providing optimal paths for the infection to travel from any one starting node. This can subsequently be outputted as a vector of visited nodes. 
 

**Input Datasets**: Our project is reliant on two data sets: flight data from major airports and population data from major cities. Both are stored as CSVs, with the former formatted as “Airport ID, Name, City, Country, IATA Code, ICAO code, Latitude, Longitude, Altitude, Timezone, DST, Tz database time zone, Type, Source” and the latter formatted as “city, city_ascii, latitude, longitude, country, 2 letter country abbreviation, 3 letter country abbreviation, admin_name, admin_code, capital, population, population density”. The population data set contains  approximately 43,000 entries, and we are only concerned with the subset of data dealing with the name of each city, so we can name corresponding vertices, and the populations, so we can have corresponding populations to modify as our hypothetical disease spreads.


**Data Correction**: since city names are provided in ascii format (free from accents and other linguistic nuances), we can search for pairs of airport locations and cities within each data set and disregard instances where either we do not have the population data for a certain city which exists in the airport data set or we do not have the flight data for a particular city. This can be done with a map of locations to booleans representing whether or not pairs are present and the CSVs themselves can be parsed line by line.

**Data Storage:**

Map: O(m) where m represents the maximum number of cities between the two data sets (43,000).


**Algorithms**
There will be three algorithms that we’ll cover with our program. To start, for all three algorithms the expected inputs for the graph include the major cities in the world and the distances as flight paths between them. The cities will be converted to nodes and the distance in between them as weighted edges. We will be doing a BFS traversal, where an infection rate for each city node in the graph will be included in addition to updating other important information about the node from the default values.


The expected output of the graph under BFS includes the infection rates of each city and the shortest distance to infect adjacent cities. The time complexity of this BFS will be every edge and node (O(e + v)) and though it may take longer as the first visitation to each vertice requires the data to be updated from default values, the other visitations will remain the same. We will expect the output to be a few print statements signifying the visitation and updating of the graph structure. 


To parse the edge data even further, we’ll be running Prim’s algorithm to develop a minimum spanning tree, which will give a mapping of shortest roads to take according to the specifications of BFS. Prim’s algorithm has a time complexity of O(v^2), with the v representing the vertices. For this algorithm, there may be complications in our implementation but we expect to reach the goal of O(v^2) in our implementation given that we’re restricting the data to be just the edges and vertices. The expected output of Prim’s algorithm will be a minimum spanning tree, returning the struct of a graph under the specifications of a tree.


Finally, we’ll narrow down the graph under the specification of airlines shutting down after one flight to form an Euler’s Path problem. To find the Euler circuit, we’ll first have an algorithm that removes edges of nodes to make an even degree (if a node has a degree one, we’ll disregard the node and deem the country unreachable). Afterwards, we’ll then run Hierholzer’s algorithm to calculate an Euler Circuit across the globe. With the respective time complexity, adjusting the edges would be expected as O(v) with v as the vertices as we just need to visit each vertice and remove a node if need be; as for the time complexity of Hierholzer’s algorithm, visiting each remaining edge once would result in a time complexity of O(e) with e being the edges. We aim to be precise with the Euler Circuit algorithm as a full traversal is necessary. For the expected output of the Euler Circuit algorithm, we’ll have a graph data set that is representative as the Euler Circuit.

**Function runtime efficiency:** 
E: edge, V: vertex/nodes 
BFS for infection rates: O(V + E)  
Covered: Prim’s based on distance weights. O(V2)
Uncovered: Euler’s: O(E) using Heirholzer’s algorithm or O(E2) using Fleury’s. We intend on using Heirholzer’s, where we consider double visitation to be the condition for a location developing a vaccine/immunity.

##Timeline

**Week 1**: Acquire and process data
Owen will focus on finding the necessary datasets while Sai, Keli, and Larry focus on preparing the csv data and ensure that all the data is accessible and usable to put into C++ data structures. We are also working on the proposal regrade and changing the project as needed.


**Week 2:** Link graph

Keli and Owen will be focused on creating the nodes (will be structs) necessary to hold the data we pull from the dataset, meanwhile Sai and Larry will work to put together the nodes created into the data structures we want to use, primarily being a graph. This is not expected to take the whole week, and most everyone will begin on next week's tasks towards the end of this week.

**Week 3:** Algorithms
Keli will use Prims to understand the distances between cities in the graph and how they relate Larry will use BFS to understand how the infection will spread within and to different cities. Owen will use Heirholz’s algorithm to get an understanding of the conditions where a vaccine will be created. Sai will use the data produced and work with each individual to get outputs to prepare for data visualization.

**Week 4:** Data visualization
Sai will be primarily responsible for getting outputs in a clean and understandable format, primarily in visual graphs if possible. Keli, Larry, and Owen will also be responsible for getting their outputs from their various tasks to be in usable fashion for Sai to implement a graph visualization of the data.

We’ll be adding and dividing these tasks into subtasks as we go.
