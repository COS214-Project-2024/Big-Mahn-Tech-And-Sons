/**
 * @file DeptOfTransportation.h
 * @brief Declaration of the CityGrid class.
 */

#ifndef DEPTOFTRANSPORTATION_H
#define DEPTOFTRANSPORTATION_H

#include "CityGrid.h"
 class Building;

/**
 * @class DeptOfTransportation
 * @brief The Transportation department
 *
 */

class DeptOfTransportation
{
private:
    CityGrid* cityGrid;     // pointer to the city grid object
    static DeptOfTransportation* instance;  // Singleton instance
    DeptOfTransportation();
    /**
     * @brief the constructor of the Class object
     * private so that no class can create another instance of the class object
     */
    
public:
    static DeptOfTransportation* getInstance();
    /**
     * @brief gets the instance of the Transportation object
     * 
     * @return DeptOfTransportation*, returns the single instance of the DeptOfTransportation via a pointer.
     */

    ~DeptOfTransportation();
    /**
     * @brief the destructor to the DeptOfTransportation object
     * ?should it be private?
     */

    void printCityGrid();
    /**
     * @brief prints the citygrid which is the attributes only.
     */

    void printRoadNetwork();
    /**
     * @brief prints the road network of the city, which is the road and the used and blank spaces
     */

    void printCityCardinalPoints();
    /**
     * @brief prints the city cardinal points 
     */

    void printCityStreets();
    /**
     * @brief prints the city streets with the street name
     */

    bool add_Road(int,int,int,string,string);
    /**
     * @brief adds a road to the city grid
     * 
     * @return boolean, returns a true or false as to whether the road was added to the grid or not
     */

    bool remove_Road(int,int,int,string);
    /**
     * @brief removes a road from the city grid
     * 
     * @return boolean, returns true or false as to whether the road was added to the grid or not
     */

    bool remove_Road(string);
    /**
     * @brief removes a road from the city grid
     * overloaded function
     * @return boolean, returns true or false as to whether the road was added to the grid or not
     */

    const vector<pair<int,int>> add_Building(int,int,Building*);
    /**
     * @brief adds a building to the city grid
     * 
     * @return const vector<pair<int,int>> , returns the building co-ordinates
     */

    bool remove_Building(vector<pair<int,int>>&);
    /**
     * @brief removes a building from the city grid
     * 
     * @return boolean, returns true or false as to whether the building was added to the grid or not
     */

    int get_distance(Building*,Building*);
    /**
     * @brief gets the distance between 2 buildings.
     * used in travekl to function
     * @return int, returns the distance between the 2 buildings
     */
    
};

#endif /* DeptOfTransportation_h */