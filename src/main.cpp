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
  std::cout << lines.size() << std::endl; 
  for (unsigned i = 0; i < lines.size(); i++)
  {
    std::cout << lines[i];
  }
  std::cout << "Work" << std::endl;

  return -1;
}