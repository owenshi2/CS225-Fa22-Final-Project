#include "parser.h"
#include "cities.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <map>
#include <assert.h>

// int main(int argc, char* argv[]) 
// {
//   std::map<std::string, City> cityIata;
//   std::vector<std::string> lines;
//   std::ifstream  data("src/cities-data.csv");

//   std::string line;
//   while(std::getline(data,line))
//   {
//       std::stringstream  lineStream(line);
//       std::string        cell;
//       while(std::getline(lineStream,cell,','))
//       {
//           // You have a cell!!!!
//           lines.push_back(cell);
//           std::cout << cell << std::endl;
//       }
//   }
//   data.close();
    
//     // return result;
//   std::cout << lines.size() << std::endl;
//   // for (unsigned i = 0; i < lines.size(); i++)
//   // {
//   //   std::cout << lines[i]; 
//   // }
//   std::vector<City> cities;
//   for(unsigned i = 4; i < lines.size(); i+=4)
//   {
//     City cTemp;
//     cTemp.ISO = lines[i];//iso
//     cTemp.iata = lines[i+1];//iata
//     cTemp.name = lines[i+2];//name
//     //cTemp.Population = lines[i+3];
//     //population
//     cTemp.Population = std::stoi(lines[i+3]);//population
//     std::cout << "City parse: " << cTemp.name << "; Pop: " << cTemp.Population << "; iata: " << cTemp.iata << "; iso: " << cTemp.ISO << std::endl;
//     cityIata[cTemp.iata] = cTemp;
//     cities.push_back(cTemp);
//     assert(!cities.empty());
//   }
//   std::cout << "Works, number of cities is: " << cities.size() << std::endl;
//   lines.clear();


//   //airlines
//   // std::vector<std::string> edges;
//   std::ifstream  flights("src/flight-paths.csv");

//   std::string path;
//   while(std::getline(flights,path))
//   {
//       std::stringstream  lineStream(path);
//       std::string        value;
//       int ind = 0;
//       std::string prev;
//       while(std::getline(lineStream,value,','))
//       {
//           // You have a cell!!!!
//           if (ind == 1) {
//             prev = value;
//           }
//           if (ind == 2) {
//             cityIata[prev].c_cities.push_back(&(cityIata[value]));
//           }
//           ind++;
//           // std::cout << value << std::endl;
//       }
//   }  

//   cities.clear();
//   for (const auto &s : cityIata)
//     cities.push_back(s.second);
//   // for (int i = 0; i < cities.size(); i++) {
//   //   std::cout<< cities.at(i).c_cities.size()<< " ";
//   // }
  
//   //test output 
//   // for (unsigned i = 0; i < cities.size(); i++) {
//   //   std::cout << "name: " << cities[i].name << " "; 
//   //   std::cout << "iata: " << cities[i].iata << " "; 
//   //   std::cout << "ISO: " << cities[i].ISO << " "; 
//   //   //std::cout << "infected: " << cities[i].infected << " "; 
//   //   std::cout << "population: " << cities[i].Population << " "; 
//   //   std::cout << std::endl;
//   // }
  

//  //drop cities with no airports, no neighbors. Drop empty neighbors too.   
//   std::cout << "original size: " << cities.size() << std::endl; 
//   std::vector<City> cities_new;
//   for (unsigned i = 0; i < cities.size(); i++) { 
//     if (cities[i].name.size() != 0 && cities[i].c_cities.size() != 0) { //check if the size is not zero
//       std::vector<City*> c_cities_temp;
//       for (unsigned j = 0; j < cities[i].c_cities.size(); j++) {
//         if (cities[i].c_cities[j]->name.size() != 0 ) { //check for non empty neighbors
//           c_cities_temp.push_back(cities[i].c_cities[j]); 
//         } 
//       } 
//       cities[i].c_cities = c_cities_temp; 
//       cities_new.push_back(cities[i]); 
//     } 
//   }

  
// std::cout << "updated size: " << cities_new.size() << std::endl;   

// //check infected 
// for (unsigned i = 0; i < cities_new.size(); i++) {
//     std::cout << "name: " << cities_new[i].name << " ";  
//     std::cout << "iata: " << cities_new[i].iata << " "; 
//     std::cout << "ISO: " << cities_new[i].ISO << " "; 
//     //std::cout << "infected: " << cities_new[i].infected << " "; 
//     std::cout << "population: " << cities_new[i].Population << " "; 
//     std::cout << std::endl;    
//   }

  

// std::cout << "run bfs:" << bfs(cities_new[0]) << std::endl; 

// // for (unsigned i = 0; i < cities_new.size(); i++) {
// //     std::cout << "population: " << cities_new[i].Population << " ";  
// //     std::cout << "infected: " << cities_new[i].infected << " "; 
// //     std::cout << std::endl;    
// // }
// return -1;   
// }


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

  cities.clear();
  for (const auto &s : cityIata)
    cities.push_back(s.second);
  // for (int i = 0; i < cities.size(); i++) {
  //   std::cout<< cities.at(i).c_cities.size()<< " ";
  // }
  

  // for (unsigned i = 0; i < cities.size(); i++) {
  //   std::cout << "name: " << cities[i].name << " "; 
  //   std::cout << "iata: " << cities[i].iata << " "; 
  //   std::cout << "ISO: " << cities[i].ISO << " "; 
  //   std::cout << "population: " << cities[i].Population << " "; 
  //   std::cout << std::endl;
  // }
  
//test 
 //drop cities with no airports, no neighbors. Drop empty neighbors too.   
  std::cout << "original size: " << cities.size() << std::endl; 
  std::vector<City> cities_new;
  for (unsigned i = 0; i < cities.size(); i++) {
    if (cities[i].name.size() != 0 && cities[i].c_cities.size() != 0) {
      std::vector<City*> c_cities_temp;
      for (unsigned j = 0; j < cities[i].c_cities.size(); j++) {
        if (cities[i].c_cities[j]->name.size() != 0 ) {
          c_cities_temp.push_back(cities[i].c_cities[j]);
        } 
        //cities[i].c_cities = c_cities_temp;          
      }
      cities[i].c_cities = c_cities_temp;  
      cities_new.push_back(cities[i]);
    }
    
  }

  
std::cout << "updated size: " << cities_new.size() << std::endl; 

// for (unsigned i = 0; i < cities_new.size(); i++) {
//   for (unsigned j = 0; j < cities_new[i].c_cities.size(); j++) {
//     std::cout << "neighbor check: " << cities_new[i].c_cities[j]->name; 
//   }
//    std::cout << "next" << std::endl; 
// }
  

  std::cout << "run bfs:" << bfs(cities_new[0]) << std::endl;
  for (unsigned i = 0; i < cities_new.size(); i++) {
    std::cout << "name: " << cities_new[i].name << " ";  
    std::cout << "iata: " << cities_new[i].iata << " "; 
    std::cout << "ISO: " << cities_new[i].ISO << " "; 
    std::cout << "infected: " << cities_new[i].infection_rate << " "; 
    std::cout << "population: " << cities_new[i].Population << " "; 
    std::cout << std::endl;    
  }
  return -1;   
}