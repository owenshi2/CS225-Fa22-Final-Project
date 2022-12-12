#include <catch2/catch_test_macros.hpp>

TEST_CASE("Parser not empty", "[weight=1]")
{
    
}

TEST_CASE("Dijkstra test 1", "[weight=1]")
{
    
}

TEST_CASE("Dijsktra test 2", "[weight=1]")
{
    
}

TEST_CASE("Dijsktra unconnected cities", "[weight=1]")
{
    
}

TEST_CASE("Hierhozer Algorithm Pass", "[weight=1") {
    std::map<std::string, City> eulertest;
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
    eulertest.insert({d.name, d});
    eulertest.insert({e.name, e});
    eulertest.insert({f.name, f});
    eulertest.insert({g.name, g});
    Circuit euler;
    euler.findCircuit(eulertest);
    
}

TEST_CASE("Hierhozer non-Eulerian graph check", "[weight=1]")
{
    
}