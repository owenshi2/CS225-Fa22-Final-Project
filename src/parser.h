#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>

class Parser
{
  public:
    std::string file_to_string(const std::string& filename);
    int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
  
};