#include "parser.h"
#include "cities.h"
#include "algorithms.hpp"
#include <iostream>
#include <fstream>
#include <ios>
#include <map>

int main(int argc, char* argv[])
{
  
  auto cityIata = CreateGraph("src/cities-data.csv", "src/flight-paths.csv");
  std::map<std::string, City*> nameToCity;
  for (auto &s : cityIata) {
    nameToCity[s.second.name] = &s.second;
  }

  std::string startingLocation;
  std::string destination;
  std::getline(std::cin, startingLocation);
  std::cout << "Input your destination now: " << std::endl;
  std::getline(std::cin, destination);


  std::vector<std::string> uT = unnoticedTravel(startingLocation, destination, nameToCity);
  std::cout << "Your path of travel will be: " << std::endl;
  for (auto elem : uT) {
    std::cout << elem << std::endl;
  }
  std::cout << "Happy infecting!" << std::endl;

  std::cout << hierholzer(nameToCity) << std::endl;
  std::cout << bfs(nameToCity["Chicago"]) << std::endl;
  std::cout << nameToCity["Chicago"]->c_cities.size() <<std::endl;
  std::cout << "Chicago" <<std::endl;
  std::cout << nameToCity["Chicago"]->infection_rate << std::endl;
  std::cout << nameToCity["New York"]->infection_rate << std::endl;
  return -1;
}