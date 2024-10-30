#ifndef DEPTOFTRANSPORTATION_H
#define DEPTOFTRANSPORTATION_H

#include "CityGrid.h"
 

class DeptOfTransportation
{
private:
    CityGrid* cityGrid;     // pointer to the city grid object
    static DeptOfTransportation* instance;  // Singleton instance
    DeptOfTransportation();
    
public:
    static DeptOfTransportation* getInstance();
    ~DeptOfTransportation();  //destructs the department object
    void printCityGrid();   //prints the city grid, roads and buildings included
    void printRoadGrid();   //prints the road grid, roads only
    const vector<vector<Cell>> getRoadGrid();   //returns a constant road grid vector , roads
    const vector<vector<Cell>> getCityGrid();   //returns a constant city grid vector , roads and buildings
    bool addRoad(int,int,int,string,string);
    
};

#endif /* DeptOfTransportation_h */
