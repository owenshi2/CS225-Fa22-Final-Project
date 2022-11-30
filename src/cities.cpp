#include "cities.h"


#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <tuple>

City makeCity(std::string IATA, std::unordered_map<std::string, std::tuple<std::string, std::string, unsigned>>& IATAtoCity) {
    City ret;
    ret.iata = IATA;
    ret.ISO = std::get<0>(IATAtoCity[IATA]);
    ret.name = std::get<1>(IATAtoCity[IATA]);
    ret.population = std::get<2>(IATAtoCity[IATA]);
    return ret;
}


// void Cities::graphCreation(const std::string & citiesData, const std::string& flightPaths){
//     // Your code here!
//     std::fstream c(citiesData);
//     if(!c.is_open()) throw std::runtime_error("cities file not open");
//     std::fstream fli(flightPaths);
//     if(!fli.is_open()) throw std::runtime_error("flight file not open");
//     std::string line, line2, entry, entry2;

//     /* populate the mapping between an iata code and the relevant city data*/
//     while (std::getline(c, line2)) {
//         std::vector<std::string> inside;
//         line.erase(remove_if(line2.begin(), line2.end(), isspace), line2.end());
//         std::stringstream f(line2);
//         while(getline(f, entry2, ',')) {
//             inside.push_back(entry2);
//         }
//         std::tuple<std::string, std::string, int> IATATuple = std::make_tuple(inside.at(0), inside.at(2), std::stoi(inside.at(3)));
//         IATAtoCity.insert(inside.at(1), IATATuple);
//     }

//     /*take the data from the last mapping and use it to populate the graph*/
//     while(std::getline(fli, line)) {
//         std::vector<std::string> inside;
//         line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
//         std::stringstream s(line);
//         while(getline(s, entry, ',')) {
//             inside.push_back(entry);
//         }
//         //going to cross reference this with the cities-data csv to identify a city, add that city to the graph
//         std::string IATA = inside.at(1);

//         //city creation using the IATA map 
//         City temp = makeCity(IATA);
        
//         if (!graph.contains(temp)) {
//             std::vector<City> adjacent;
//             graph.insert(std::make_pair(temp, adjacent));
//         } else {
//             (*graph.find(temp)).second.push_back(makeCity(inside.at(2)));
//         }
//     }
// }


