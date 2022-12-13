#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <ios>
#include <map>
#include "cities.h"

std::map<std::string, City> CreateGraph(const std::string& city, const std::string& flight);