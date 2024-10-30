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
    bool addRoad(int,int,int,string,string);
    
};

#endif /* DeptOfTransportation_h */
