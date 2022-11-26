#include "parser.h"
#include "cities.h"
#include <iostream>
#include <string>



using std::string;
// using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;


int main(int argc, char* argv[])
{
  std::cout << "Make Keli." << std::endl;
  Parser p; 

  //std::string nodeString = p.file_to_string("flight-paths.csv");
  std::ifstream file("flight-paths.csv");
  std::string line;
  std::vector<std::string> lines;
  while (std::getline(file, line))
  {
    lines.push_back(line);  
  }
  std::cout << line.size() << std::endl; 
  for (unsigned i = 0; i < line.size(); i++) {
    std::cout << line[i]; 
  }  

  std::cout << "Work" << std::endl;

  return -1;
}