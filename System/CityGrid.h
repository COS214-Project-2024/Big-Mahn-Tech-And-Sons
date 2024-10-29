#ifndef CITYGRID_H
#define CITYGRID_H

#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>


#include "Building.h"

using namespace std;

class Cell
{
    public:
        Cell(int, int, string);  //creates a cell in the grid
        ~Cell();
        const char getAttribute(); //returns character whether its a road or building
        const string getCardinal_direction();
        void changeAttribute(char);  //changes attribute.
        const string getStreetName(); //gets the streetname only if the atttribute is R.
        void updateStreetName(string); //updates the streetName.
        int getRow() const;
        int getCols() const;




    private:
        char attribute; // R or B (road or building)
        int cell_row_value; //cell co-ord x
        int cell_col_value; //cell co-ord y
        string cardinal_direction; //cardinal point
        string street_name; // streetname




};

class CityGrid
{
private:
    static vector<vector<Cell>>* citygrid;  //a pointer to a 2D dynamic grid of cells
    // add vector of builings. pointer to vector of buildings.
    vector<Building*> buildings; //vector of buildings
    int grid_num_rows; //city rows
    int grid_num_cols; //city columns

     bool isValidRoad(int row, int col);
    std::vector<Cell> getNeighbors(const Cell& cell);

     std::unordered_map<std::string, Building*> buildingMap;
    

    double calculateDistance(const Cell& start, const Cell& end) {
        return std::abs(start.getRow() - end.getRow()) + 
               std::abs(start.getCols() - end.getCols());
    }
   
    

public:
    CityGrid(int,int); //only use even positive integers , so cardinal_points works as intended
    ~CityGrid(); // deletes the memory allocated for the grid
    bool addRoad(int,int,int,string,string); // adds a road with a streetname

     bool addBuilding(Building* building, int row, int col, int width, int height); // Add a building
     //remove building
     bool removeBuilding(int row, int col, int width, int height); // remove a building 

    Cell* CityGrid::findCell(Building* building);

    
       Building* findBuildingByName(const std::string& name) {
        auto it = buildingMap.find(name);
        return (it != buildingMap.end()) ? it->second : nullptr;
    }

     std::vector<Cell> travel(const Cell& start, const Cell& destination);

    bool removeRoad(int,int,int,string);  //standard remove road
    bool removeRoad(string);  //removes a road by streetName
    void printCityGrid();  //prints all buildings and roads
    void printCityCardinal(); //prints the cardinal points of each cell.
    void printCityStreets(); //prints the street names.
    void printCityRoads();
    // function to get shortest path from point a to point b
    int getNumRows();
    int getNumCols();
};

#endif /* GRID_H */
