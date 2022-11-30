#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// class City
// {
//   public:
//     City();
//     void setPop(int pop);
//     int getPop();
//     double distanceFrom(City c);
//     void addDistanceFrom();
//     int getNumFlightPaths();
//     void addFlight();
//   private:
//     int numFlightPaths;
//     int pop;
//     std::vector<std::string> airports;
//     std::vector<int> flightDists;
//     std::vector<City> connectedCities;
// };

  struct City {
    unsigned population;
    std::string iata;
    std::string ISO;
    std::string name;
    bool operator==(const City& c) const {
      return (iata == c.iata && ISO == c.ISO && name == c.name);
    }
  };
  
  namespace std {
    template <>
    struct hash<City> {
        size_t operator()( const City& c ) const {
            size_t res = 17;
            res = res * 31 + hash<string>()( c.iata );
            res = res * 31 + hash<string>()( c.ISO );
            res = res * 31 + hash<string>()( c.name );
            return res;
        }
    };
  }

  City makeCity(std::string IATA, std::unordered_map<std::string, std::tuple<std::string, std::string, unsigned>>& IATAtoCity);

  



// class HashFn {
//   public:
//   size_t operator()(const Cities::City& c) {
//     return c.population;
//   }
// };