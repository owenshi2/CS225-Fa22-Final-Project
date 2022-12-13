#include "catch2/catch_test_macros.hpp"
#include "src/minheap.h"
#include "src/parser.h"
#include "src/path.hpp"
#include "src/cities.h"
#include "src/algorithms.hpp"

TEST_CASE("Parser not empty", "[weight=1]")
{
    auto cityIata = CreateGraph("src/cities-data.csv", "src/flight-paths.csv");
    REQUIRE(cityIata.size() > 0);
}

TEST_CASE("Parser creates nodes", "[weight=1]")
{
    auto cityIata = CreateGraph("src/cities-data.csv", "src/flight-paths.csv");
    REQUIRE(cityIata["ORD"].name == "Chicago");
}

TEST_CASE("Parser creates edges", "[weight=1]")
{
    auto cityIata = CreateGraph("src/cities-data.csv", "src/flight-paths.csv");
    REQUIRE(cityIata["ORD"].c_cities.size() > 0);
}

std::map<std::string, City*> NameToCity(std::map<std::string, City> cityIata) {
    std::map<std::string, City*> names;
    for (auto &s : cityIata) {
    names[s.second.name] = &s.second;
    return names;
  }
}

TEST_CASE("Dijkstra test 1", "[weight=1]")
{
    auto names = NameToCity(std::map<std::string, City> cityIata);
    std::vector<std::string> uT = unnoticedTravel("Chicago", "New York", names);
    // Cities are 1 apart, so will have both their names adding to two elements
    REQUIRE(uT.size() == 2);
}

TEST_CASE("Dijsktra test 2", "[weight=1]")
{
    auto names = NameToCity(std::map<std::string, City> cityIata);
    std::vector<std::string> uT = unnoticedTravel("Sunyasi", "Brindisi", names);
    // Cities should be 4 apart, so 5 total including
    REQUIRE(uT.size() == 5);
}

TEST_CASE("Dijsktra unconnected cities or non-cities", "[weight=1]")
{
    auto names = NameToCity(std::map<std::string, City> cityIata);
    std::vector<std::string> uT = unnoticedTravel("Chicago", "Berlin", names);
    REQUIRE(uT.size() == 1);
    std::vector<std::string> uT2 = unnoticedTravel("New York", "Tomato Town", names);
    REQUIRE(uT2.size() == 1);
}

TEST_CASE("Hierhozer non-Eulerian graph check", "[weight=1]")
{
    auto names = NameToCity(std::map<std::string, City> cityIata);
    REQUIRE(hierholzer(nameToCity) == "This graph is not a Eulerian graph, Hierholzer could not be applied");
}

TEST_CASE("Hierhozer Algorithm Pass", "[weight=1") {
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
    REQUIRE(str.size() > 0);
}

TEST_CASE("bfs affects correct number of cities", "[weight=1]")
{
    auto names = NameToCity(std::map<std::string, City> cityIata);
    REQUIRE(bfs(names["Chicago"]) == 1379);
}

TEST_CASE("bfs changes infection rate of nearby cities", "[weight=1]")
{
    auto names = NameToCity(std::map<std::string, City> cityIata);
    REQUIRE(names["New York"]->infection_rate = 0.9);
}