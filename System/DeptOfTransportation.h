#ifndef DEPTOFTRANSPORTATION_H
#define DEPTOFTRANSPORTATION_H

#include "CityGrid.h"
#include  "ResidentialBuildingCreator.h"
#include "CommercialBuildingCreator.h"
#include "IndustrialBuildingCreator.h"
#include "LandmarkBuildingCreator.h"

#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
 
class DeptOfTransportation
{
private:
    CityGrid* cityGrid;     // pointer to the city grid object
    static DeptOfTransportation* instance;  // Singleton instance
    DeptOfTransportation();
    vector<Building*> buildings;
 
public:
    static DeptOfTransportation* getInstance();
    ~DeptOfTransportation();  //destructs the department object

    //.......Getter for Building......//
    const vector<Building*> & getAllBuildings() const;


    //....... PRINT FUNCTIONS ........//

    void printCityGrid();   //prints the city grid, roads and buildings included
    void printRoadNetwork();   //prints the road grid, roads only
    void printCityCardinalPoints();
    void printCityStreets();
    void printCityBuildings() const ;

    // ......... ROAD AND BUILDING FUNCTIONS .......... //


    bool add_Road(int,int,int,string,string);
    bool remove_Road(int,int,int,string);
    bool remove_Road(string);
    const vector<pair<int,int>> add_Building(int,int,string);
    bool remove_Building(vector<pair<int,int>>&);
    
};

#endif /* DeptOfTransportation_h */