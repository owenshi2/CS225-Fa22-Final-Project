// NOTE: THIS TEST SUITE IS A REPLICA OF TEST.CPP EXCEPT WITHOUT USING CATCH2 AS MANY TEAM MEMBERS
// ARE UNABLE TO USE CATCH2 AND NECESSARY ASSISTANCE WAS NOT ABLE TO FIX THIS ISSUE FOR AFFECTED
// MEMBERS.

#include "parser.h"
#include "cities.h"
#include "algorithms.hpp"

std::map<std::string, City*> NameToCity(std::map<std::string, City> cityIata) {
    std::map<std::string, City*> names;
    for (auto &s : cityIata) {
        names[s.second.name] = &s.second;
    }
  return names;
}

int main(int argc, char* argv[])
{
// Parser not empty
    auto cityIata = CreateGraph("src/cities-data.csv", "src/flight-paths.csv");
    if (cityIata.size() > 0) {
        std::cout << "Test #1 Passed: Parser not empty" << std::endl;
    } else {
        std::cout << "Test #1 Failed: CityIata size should be a large number but you got 0" << std::endl;
    }

// Parser creates nodes
    if (cityIata["ORD"].name == "Chicago") {
        std::cout << "Test #2 Passed: Parser creates nodes" << std::endl;
    } else {
        std::cout << "Test #2 Failed: Parser did not correctly create and map city nodes" << std::endl;
    }

// Parser creates edges
    if (cityIata["ORD"].c_cities.size() > 0) {
        std::cout << "Test #3 Passed: Parser creates edges" << std::endl;
    } else {
        std:: cout << "Test #3 Failed: Parser creates edges" << std::endl;
    }

// Dijkstra test 1
    std::map<std::string, City*> names;
    for (auto &s : cityIata) {
        names[s.second.name] = &s.second;
    }
    std::vector<std::string> uT1 = unnoticedTravel("Chicago", "New York", names);
    // Cities are 1 apart, so will have both their names adding to two elements
    if (uT1.size() == 2) {
        std::cout << "Test #4 Passed: Dijkstra test 1" << std::endl;
    } else {
        std::cout << "Test #4 Failed: Dijkstra test 1" << std::endl;
    }

// Dijsktra unconnected cities or non-cities
    // names = NameToCity(cityIata);
    std::vector<std::string> uT3 = unnoticedTravel("Chicago", "Berlin", names);
    std::vector<std::string> uT4 = unnoticedTravel("New York", "Tomato Town", names);
    if (uT3.size() == 1 && uT4.size() == 1){
        std::cout << "Test #5 Passed: Dijsktra unconnected cities or non-cities" << std::endl;
    } else {
        std::cout << "Test #5 Failed: Dijsktra unconnected cities or non-cities" << std::endl;
    }

// Hierhozer non-Eulerian graph check
    // names = NameToCity(cityIata);
    if (hierholzer(names) == "This graph is not a Eulerian graph, Hierholzer could not be applied") {
        std::cout << "Test #6 Passed: Hierhozer non-Eulerian graph check" << std::endl;
    } else {
        std::cout << "Test #6 Failed: Hierhozer non-Eulerian graph check" << std::endl;
    }

// Hierhozer Algorithm Pass
    std::map<std::string, City*> eulertest;
    City d;
    d.name = "Albany";
    City e;
    e.name = "Chicago";
    e.c_cities.push_back(&d);
    d.c_cities.push_back(&e);
    City f;
    f.name = "Trenton";
    f.c_cities.push_back(&e);
    e.c_cities.push_back(&f);
    City g;
    g.name = "Dubai";
    g.c_cities.push_back(&f);
    f.c_cities.push_back(&g);
    eulertest.insert({d.name, &d});
    eulertest.insert({e.name, &e});
    eulertest.insert({f.name, &f});
    eulertest.insert({g.name, &g});
    Circuit euler;
    auto str = euler.findCircuit(eulertest);
    std::cout << str <<std::endl;
    if (str.size() > 0) {
        std::cout << "Test #7 Passed: Hierhozer Algorithm on Eulerian Graph" << std::endl;
    } else {
        std::cout << "Test #7 Failed: Hierhozer Algorithm on Eulerian Graph" << std::endl;
    }

// bfs affects correct number of cities
    // names = NameToCity(cityIata);
    if (bfs(names["Chicago"]) == 1405) {
        std::cout << "Test #8 Passed: bfs affects correct number of cities" << std::endl;
    } else {
        std::cout << "Test #8 Failed: bfs affects correct number of cities" << std::endl;
    }

// bfs changes infection rate of nearby cities
    // names = NameToCity(cityIata);
    if (names["New York"]->infection_rate == 0.5) {
        std::cout << "Test #9 Passed: bfs changes infection rate of nearby cities" << std::endl;
    } else {
        std::cout << "Test #9 Failed: bfs changes infection rate of nearby cities" << std::endl;
    }
}