#include "cities.h"
#include "parser.h"

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


std::string text;
ifstream read;
std::string Parser::file_to_string(const std::string& filename)
{
  std::ifstream text(filename);
  std::stringstream strStream;
  if (text.is_open())
  {
    strStream << text.rdbuf();
  }
  return strStream.str();  
}

int Parser::SplitString(const std::string & str1, char sep, std::vector<std::string> &fields)
{
  std::string str = str1;
  std::string::size_type pos;
  while((pos=str.find(sep)) != std::string::npos)
  {
    fields.push_back(str.substr(0,pos));
    str.erase(0,pos+1);   
  }
  fields.push_back(str);  
  return fields.size();
}