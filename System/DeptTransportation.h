#ifndef DEPTTRANSPORTATION_H
#define DEPTTRANSPORTATION_H

#include "CityGrid.h"

class DeptTransportation
{
private:
    CityGrid* cityGrid;     // pointer to the city grid object
    
public:
    DeptTransportation();   //constructs the department object
    ~DeptTransportation();  //destructs the department object
    void printCityGrid();   //prints the city grid, roads and buildings included
    void printRoadGrid();   //prints the road grid, roads only
    const vector<vector<Cell>> getRoadGrid();   //returns a constant road grid vector , roads
    const vector<vector<Cell>> getCityGrid();   //returns a constant city grid vector , roads and buildings
    int grid_num_rows();
    int grid_num_cols();
};

#endif /* DeptTransportation_h */
