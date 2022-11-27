#include "parser.h"
#include "cities.h"
#include <iostream>
#include <fstream>
#include <ios>

int main(int argc, char* argv[])
{
  std::cout << "Make Keli." << std::endl;
  std::fstream f("src/cities-data.csv");
  if(!f.is_open()) throw std::runtime_error("Could not open file");
  std::string buffer, stupid, crazy;
  std::vector<std::string> lines;
  while (f >> buffer)
  {
    std::getline(f, stupid);
    std::stringstream s(stupid);
    while (std::getline(s, crazy, ','))
    {
      std::cout << "Crazy: " << crazy << std::endl;
      lines.push_back(crazy);
    }
  }
  // std::cout << lines.size() << std::endl;
  // for (unsigned i = 0; i < lines.size(); i++)
  // {
  //   std::cout << lines[i];
  // }
  std::vector<City> cities;
  for(unsigned i = 0; i < lines.size(); i++)
  {
    int mod4 = i % 4;
    City cTemp;
    if(mod4 == 0)
    {
      cTemp.ISO = lines[i];//iso
    } else if(mod4 == 1)
    {
      cTemp.iata = lines[i];//iata
    } else if(mod4 == 2)
    {
      cTemp.name = lines[i];//name
    } else
    {
      cTemp.Population = stoi(lines[i]);//population
    }
    if(mod4 == 2)
    {
      std::cout << "City parse: " << cTemp.name << "; Pop: " << cTemp.Population << std::endl;
    }
  }
  std::cout << "Work" << std::endl;

  return -1;
}