#include "parser.h"

std::map<std::string, City> CreateGraph(const std::string& city, const std::string& flight)
{
  //City parser
  std::map<std::string, City> cityIata;
  std::vector<std::string> lines;
  std::ifstream  data(city);

  std::string line;
  while(std::getline(data,line))
  {
      std::stringstream  lineStream(line);
      std::string        cell;
      while(std::getline(lineStream,cell,','))
      {
          // You have a cell!!!!
          lines.push_back(cell);
      }
  }
  data.close();
    
  // Takes parsed city csv and converts to struct nodes
  std::vector<City> cities;
  for(unsigned i = 4; i < lines.size(); i+=4)
  {
    City cTemp;
    cTemp.ISO = lines[i];//iso
    cTemp.iata = lines[i+1];//iata
    cTemp.name = lines[i+2];//name
    cTemp.Population = std::stod(lines[i+3]);//population
    //std::cout << "City parse: " << cTemp.name << "; Pop: " << cTemp.Population << "; iata: " << cTemp.iata << "; iso: " << cTemp.ISO << std::endl;
    cityIata[cTemp.iata] = cTemp;
    cities.push_back(cTemp);
    assert(!cities.empty());
  }
  lines.clear(); 

  // Parse flight information and create 

  std::ifstream  flights(flight);

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

  return cityIata;  

}