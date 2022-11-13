#include <iostream>
#include <vector>
#include <string>

class City
{
  public:
    City();
    void setPop(int pop);
    int getPop();
    double distanceFrom(City c);
    void addDistanceFrom();
    int getNumFlightPaths();
    void addFlight();
  private:
    int numFlightPaths;
    int pop;
    std::vector<City> connectedCities;
};