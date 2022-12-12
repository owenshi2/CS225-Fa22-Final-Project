// #include "parser.h"
#include "cities.h"
#include "path.hpp"
#include <iostream>
#include <fstream>
#include <ios>
#include <map>
#include <assert.h>

int main(int argc, char* argv[])
{
  std::map<std::string, City> cityIata;
  std::vector<std::string> lines;
  std::ifstream  data("src/cities-data.csv");

  std::string line;
  while(std::getline(data,line))
  {
      std::stringstream  lineStream(line);
      std::string        cell;
      while(std::getline(lineStream,cell,','))
      {
          // You have a cell!!!!
          lines.push_back(cell);
          std::cout << cell << std::endl;
      }
  }
  data.close();
    
    // return result;
  std::cout << lines.size() << std::endl;
  // for (unsigned i = 0; i < lines.size(); i++)
  // {
  //   std::cout << lines[i];
  // }
  std::vector<City> cities;
  for(unsigned i = 4; i < lines.size(); i+=4)
  {
    City cTemp;
    cTemp.ISO = lines[i];//iso
    cTemp.iata = lines[i+1];//iata
    cTemp.name = lines[i+2];//name
    cTemp.Population = lines[i+3];//population
    std::cout << "City parse: " << cTemp.name << "; Pop: " << cTemp.Population << "; iata: " << cTemp.iata << "; iso: " << cTemp.ISO << std::endl;
    cityIata[cTemp.iata] = cTemp;
    cities.push_back(cTemp);
    assert(!cities.empty());
  }
  std::cout << "Works, number of cities is: " << cities.size() << std::endl;
  lines.clear();

  std::cout << "original size: " << cities.size() << std::endl; 
  std::vector<City> cities_new;
  for (unsigned i = 0; i < cities.size(); i++) {
    if (cities[i].name.size() != 0 && cities[i].c_cities.size() != 0) {
      std::vector<City*> c_cities_temp;
      for (unsigned j = 0; j < cities[i].c_cities.size(); j++) {
        if (cities[i].c_cities[j]->name.size() != 0 ) {
          c_cities_temp.push_back(cities[i].c_cities[j]);
        }
        cities[i].c_cities = c_cities_temp;
      }
      cities_new.push_back(cities[i]);
    }
    
  }

  //airlines
  // std::vector<std::string> edges;
  std::ifstream  flights("src/flight-paths.csv");

    std::string path;
    while(std::getline(flights,path))
    {
        std::stringstream  lineStream(path);
        std::string        value;
        int ind = 0;
        std::string prev;
        while(std::getline(lineStream,value,','))
        {
            // You have a cell!!!!
            if (ind == 1) {
              prev = value;
            }
            if (ind == 2) {
              cityIata[prev].c_cities.push_back(&(cityIata[value]));
            }
            ind++;
            // std::cout << value << std::endl;
        }
    }  

    std::cout<< cityIata["AER"].c_cities.size()<<std::endl;
  std::vector<City> eulertest;
  City a;
  a.name = "Detroit";
  City b;
  b.name = "San Fran";
  a.c_cities.push_back(&b);
  b.c_cities.push_back(&a);
  City c;
  c.name = "Houston";
  c.c_cities.push_back(&b);
  b.c_cities.push_back(&c);
  City d;
  d.name = "Albany";
  d.c_cities.push_back(&c);
  c.c_cities.push_back(&d);
  City e;
  e.name = "Chicago";
  e.c_cities.push_back(&b);
  e.c_cities.push_back(&d);
  b.c_cities.push_back(&e);
  d.c_cities.push_back(&e);
  City f;
  f.name = "Trenton";
  f.c_cities.push_back(&e);
  e.c_cities.push_back(&f);
  City g;
  g.name = "Dubai";
  g.c_cities.push_back(&b);
  g.c_cities.push_back(&f);
  b.c_cities.push_back(&g);
  f.c_cities.push_back(&g);
  eulertest.push_back(a);
  eulertest.push_back(b);
  eulertest.push_back(c);
  eulertest.push_back(d);
  eulertest.push_back(e);
  eulertest.push_back(f);
  eulertest.push_back(g);
  Circuit euler;
  euler.findCircuit(eulertest);
  return -1;
}