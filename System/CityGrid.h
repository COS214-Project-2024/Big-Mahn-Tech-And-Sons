#ifndef CITYGRID_H
#define CITYGRID_H

#include <vector>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Cell
{
    public:
        Cell(int, int, string);  //creates a cell in the grid
        ~Cell();
        const char getAttribute(); //returns character whether its a road or building
        const string getDetailed_Atttribute();
        void  updateDetailed_Attribute(string);
        const string getCardinal_direction();
        void changeAttribute(char);  //changes attribute.
        const string getStreetName(); //gets the streetname only if the atttribute is R.
        void updateStreetName(string); //updates the streetName.

    private:
        char attribute; // R-road, C-commercialBuilding, H-residentialBuilding, L-landmarkBuilding, I-industrialBuilding, .-available, #-unavailable
        string detailed_attribute; //detailed info about the attribute, string 
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
    int grid_num_rows; //city rows
    int grid_num_cols; //city columns

public:
    CityGrid(int,int); //only use even positive integers , so cardinal_points works as intended
    ~CityGrid(); // deletes the memory allocated for the grid
    bool addRoad(int,int,int,string,string); // adds a road with a streetname
    bool removeRoad(int,int,int,string);  //standard remove road
    bool removeRoad(string);  //removes a road by streetName
    bool placeBuilding(int,int,int,int,string);
    const char getAttribute_from_DetailedAttribute(string);
    bool isNextToRoad(int,int,int,int);
    void printCityGrid();  //prints all buildings and roads
    void printCityCardinal(); //prints the cardinal points of each cell.
    void printCityStreets(); //prints the street names.
    void printCityRoadNetwork(); //prints all roads on the grid. "." available, "#" used space
    vector<pair<int,int>> errorPair(); //used in addBuilding
    bool isEmptySpace(int,int,int,int);
    vector<pair<int,int>> addBuilding(int,int,string);  //returns vector of locations , length & width
    int getDistance(int,int,string);   //returns distance as int, x,y co-ord of citizen & string of detailed attribute.


    // function to get shortest path from point a to point b
};

#endif /* GRID_H */