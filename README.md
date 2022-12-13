# CS225-Fa22-Final-Project
**Video Link**
https://youtu.be/90ZGbjKktXU

## **Leading Question**: 
 Our dataset analysis program aims to simulate a virgin-soil environmental epidemic spread through multiarray infection vectors. The data will include the node values as the population of major cities of the world and feature a graph structure using flight data representing the edges. We will use a public csv file from Openflights and consider the adjacent nodes as direct flights from one city to another. We aim to simulate how long it takes for a city’s infection to reach another city (BFS). 
 
 A representation of developed immunity will be accomplished through the use of Heirholzer’s algorithm, where the detection of repeat visits to a node will factor into the node’s resistance towards infection. Dijkstra’s algorithm offers us a shortest path to each connected node from any one node, providing optimal paths for the infection to travel from any one starting node if minimizing infection is the goal. This can subsequently be outputted as a vector of visited nodes. 
 
## **Running Instructions:**
Git pull or git copy this project from https://github.com/owenshi2/CS225-Fa22-Final-Project into your preferred IDE using its terminal. Navigate to the terminal and run the command 'make'. To run tests, input ./test. To run our intended user interface, run ./main. If running the user interface in the keliFin branch, you will be prompted to input arguments into the terminal. Do so knowing that our implementation is CASE SENSITIVE. The branch features data set corrections that aim to minimize the problem descibed below.

NOTE: One algorithm (Dijkstra) is dependent on connections between specific, modern airports. Our cities-data CSV opts to assign either heliports or deprecated airports to those CSVs rather than well known airports and can conflict with our flight-paths CSV. The flight-paths CSV is additionally missing some notable locations (e.g. Berlin). Consequently, some expected city relationships may be identified as nonexistent when in reality that isn't the case.

Some recommended locations for input (using the keliFin code) are:
Accra, Bogota, Chicago, New York, Beijing, Brindisi, New Delhi, Shanghai, Bergen, Stockholm, Palanga, Cape Town, Baltimore, Kumasi, Sunyani, Columbia, Campo Grande, Guarapuava, Souda, Treviso, Memmingen, Shannon, Porto Seguro, Lisbon, Campinas, Pisa, Port Louis, Newark, Souda, Weeze, Riga, Calgary, Huangshan, Yichun, Kimberley, Pietermaritzburg, Kunming, Phuket, St. Petersburg, Zurich, Valletta, Yellowknife, Edmonton

The catch2 framework could not be implemented and the usage of <cassert> / "assert.h" were similarly problematic. As a result, the testing will output print statements corresponding to the success or failure of different tests.

## **Organization**:
The Makefile and Project Proposal are attached to the root directory of this project. A link to the project presentation exists at the top of this README. Underneath that are the instructions for running this project. The algorithms required for the project are all located in the algorithms.hpp file within the source (src) folder. Any class dependencies, such as "minheap.h" are also stored in the source folder and are included in the algorithms.hpp file. Our datasets are stored in the source directory. The written report can be found in the results.md file in the source directory.


## **Input Datasets**:
Our project is reliant on two data sets: flight data from major airports and population data from major cities. Both are stored as CSVs, with the former formatted as “Airport ID, Name, City, Country, IATA Code, ICAO code, Latitude, Longitude, Altitude, Timezone, DST, Tz database time zone, Type, Source” and the latter formatted as “city, city_ascii, latitude, longitude, country, 2 letter country abbreviation, 3 letter country abbreviation, admin_name, admin_code, capital, population, population density”. The population data set contains  approximately 43,000 entries, and we are only concerned with the subset of data dealing with the name of each city, so we can name corresponding vertices, and the populations, so we can have corresponding populations to modify as our hypothetical disease spreads.


## **Data Correction**:
since city names are provided in ascii format (free from accents and other linguistic nuances), we can search for pairs of airport locations and cities within each data set and disregard instances where either we do not have the population data for a certain city which exists in the airport data set or we do not have the flight data for a particular city. This can be done with a map of locations to booleans representing whether or not pairs are present and the CSVs themselves can be parsed line by line.

**Data Storage:**

Vector: O(m) where m represents the maximum number of cities between the two data sets.
Map: O(m) where m represents the maximum number of cities between the two data sets.


## **Algorithms**
There will be three algorithms that we’ll cover with our program. To start, for all three algorithms the expected inputs for the graph include the major cities in the world and the distances as flight paths between them. The cities will be converted to nodes and the distance in between them as weighted edges. We will be doing a BFS traversal, where an infection rate for each city node in the graph will be included in addition to updating other important information about the node from the default values.


The expected output of the graph under BFS includes the infection rates of each city and the shortest distance to infect adjacent cities. The time complexity of this BFS will be every edge and node (O(e + v)) and though it may take longer as the first visitation to each vertice requires the data to be updated from default values, the other visitations will remain the same. We will expect the output to be a few print statements signifying the visitation and updating of the graph structure. 


To parse the edge data even further, we’ll be running Dijkstra’s algorithm to develop a mapping of , which will give a mapping of shortest roads to take according to the specifications of BFS. Dijkstra’s algorithm has a time complexity of O(ElogV + VlogV) in our implementation, where V represents Vertices and E represents edges. The expected output of Dijkstra's will be a mapping of each connected node in the graph to a designated predecessor. This predecessor mapping can then be used to backtrack to a user-defined starting location by a helper function "unnoticedTravel".


Finally, we’ll narrow down the graph under the specification of airlines shutting down after one flight to form an Euler’s Path problem. To find the Euler circuit, we’ll first have an algorithm that removes edges of nodes to make an even degree (if a node has a degree one, we’ll disregard the node and deem the country unreachable). Afterwards, we’ll then run Hierholzer’s algorithm to calculate an Euler Circuit across the globe. With the respective time complexity, adjusting the edges would be expected as O(v) with v as the vertices as we just need to visit each vertice and remove a node if need be; as for the time complexity of Hierholzer’s algorithm, visiting each remaining edge once would result in a time complexity of O(e) with e being the edges. We aim to be precise with the Euler Circuit algorithm as a full traversal is necessary. For the expected output of the Euler Circuit algorithm, we’ll have a graph data set that is representative as the Euler Circuit.

## **Function runtime efficiency:**

E: edge, V: vertex/nodes 
BFS for infection rates: O(V + E)  
Covered: Dijkstra's. O(Vlogv + ElogV)
Uncovered: Euler’s: O(E) using Heirholzer’s algorithm or O(E2) using Fleury’s. We intend on using Heirholzer’s, where we consider double visitation to be the condition for a location developing a vaccine/immunity.

## Timeline

**Week 1**: Acquire and process data
Owen will focus on finding the necessary datasets while Sai, Keli, and Larry focus on preparing the csv data and ensure that all the data is accessible and usable to put into C++ data structures. We are also working on the proposal regrade and changing the project as needed.


**Week 2:** Link graph

Keli and Owen will be focused on creating the nodes (will be structs) necessary to hold the data we pull from the dataset, meanwhile Sai and Larry will work to put together the nodes created into the data structures we want to use, primarily being a graph. This is not expected to take the whole week, and most everyone will begin on next week's tasks towards the end of this week.

**Week 3:** Algorithms
Keli will use Dijkstra's gauge how visitation between nodes in the graph can occur while minimizing the number of people infected while Larry will use BFS to spread the infection from city to city. Owen will use Heirholzer’s algorithm to get an understanding of the conditions where a vaccine will be created. Sai will use the data produced and work with each individual to get outputs to prepare for data visualization.

**Week 4:** Data visualization
Sai will be primarily responsible for getting outputs in a clean and understandable format, primarily in visual graphs if possible. Keli, Larry, and Owen will also be responsible for getting their outputs from their various tasks to be in usable fashion for Sai to implement a graph visualization of the data.

We’ll be adding and dividing these tasks into subtasks as we go.
