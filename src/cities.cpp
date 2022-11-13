#include "cities.h"


#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

ifstream words("worldcities.csv");
vector<string> out; 

// if (words.is_open()) {   
//     std::istream_iterator<string> word_iter(words);
//     while (!words.eof()) {
//         out.push_back(remove_punct(*word_iter));
//         ++word_iter;  
//     }
// }


