#include "cities.h"


#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>

using std::string;
// using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

ifstream words("entry/cities-data.csv");
std::vector<string> out; 

// if (words.is_open()) {   
//     std::istream_iterator<string> word_iter(words);
//     while (!words.eof()) {
//         out.push_back(remove_punct(*word_iter));
//         ++word_iter;  
//     }
// } 

// std::vector<std::string> getEmAndSplitEm(std::istream& str)
// {
//   std::vector<std::string> result;
//   std::string line;
//   std::getline(str,line);
//   std::stringstream lineStream(line);
//   std::string cell;
//   while(std::getline(lineStream,cell, ','))
//   {
//     result.push_back(cell);
//   }
//   if (!lineStream && cell.empty())
//   {
//     result.push_back("");
//   }
//   return result;
// }

class Parser
{
  
}