/**
 * @file CityGrid.h
 * @brief Declaration of the CityGrid class.
 */

#ifndef CITYGRID_H
#define CITYGRID_H

#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <utility>

class Building;
using namespace std;

/**
 * @class Cell
 * @brief Represents a cell in the city grid.
 *
 * This calls holds attributes of a cell in the grid that is used by CityGrid class
 * It's purpose is to represent what the cell is.
 */

class Cell
{
public:
    Cell(int row_value, int col_value, string cardinal_point);
    /**
     * @brief creates the cell and initializes the class member variables.
     *
     * @param row_value row co-ordinate.
     * @param col_value column co-ordinate.
     * @param cardinal_point cardinal point of cell
     */
    ~Cell();
    /**
     * @brief Destroys the cell
     * no dynamic memory allocation therefore this destructor does nothing.
     *
     */

    const char getAttribute();
    /**
     * @brief simple getter function
     *
     * @return char the attribute of the cell
     */

    bool set_Attribute(char);
    /**
     * @brief simple setter function
     *
     * @return boolean, true of false as to whether the set was successful
     */

    bool set_Detailed_Attribute(string);
    /**
     * @brief sets the detailed_attribute member variable
     *
     * @return boolean, true or false as to  whether the set was successful or not
     */

    const string getDetailed_Atttribute();
    /**
     * @brief gets the detailed attribute member variable
     *
     * @return const string, the detailed attribute
     */

    void updateDetailed_Attribute(string);
    /**
     * @brief update the detailed_attribute member variable
     *
     */

    const string getCardinal_direction();
    /**
     * @brief gets the cardinal direction of the cell
     */

    void changeAttribute(char);
    /**
     * @brief changes the attribute member variable
     */

    const string getStreetName();
    /**
     * @brief gets the street name only if the cell is a road
     *
     * @return constant string, string of the street name.
     */

    void updateStreetName(string);
    /**
     * @brief updates the street name
     *
     */

private:
    char attribute;            // R-road, C-commercialBuilding, H-residentialBuilding, L-landmarkBuilding, I-industrialBuilding, .-available, #-unavailable
    string detailed_attribute; // detailed info about the attribute, string
    int cell_row_value;        // cell co-ord x
    int cell_col_value;        // cell co-ord y
    string cardinal_direction; // cardinal point
    string street_name;        // streetname
};

/**
 * @class CityGrid
 * @brief CityGrid class
 *
 * Holds all the functionality of the city grid, like adding and removing roads and buildings.
 *
 */

class CityGrid
{
private:
    static vector<vector<Cell>> *citygrid; // a pointer to a 2D dynamic grid of cells
    int grid_num_rows;                     // city rows
    int grid_num_cols;                     // city columns

    string toUpper(string);
    /**
     * @brief makes the string all uppercase
     *
     * @return string, returns a string that is full uppercase
     */

    string toLower(string);
    /**
     * @brief makes the string all lowercase
     *
     * @return string, returns a string that is full lowercase
     */

    bool isNextToRoad(int, int, int, int);
    /**
     * @brief checks if a cell that is ready for building placement is next to a road
     *
     * @return boolean, true or false as to whether the cell is next to the road or not
     */

    bool placeBuilding(int, int, int, int, string);
    /**
     * @brief helper function that places the building on the grid
     *
     * @return boolean, true or false as to whether the building was place on the grid or not
     */

    bool isEmptySpace(int, int, int, int);
    /**
     * @brief helper function to check if there is space on the grid to add a building
     *
     * @return boolean, true or false as to whether there is space or not.
     */

    vector<pair<int, int>> getAdjacentRoadCells(int, int, int, int);
    /**
     * @brief helper function for get_distance
     *
     * @return vector of pair integers, vector pair of th building co-ordinates
     */

public:
    CityGrid(int, int);
    /**
     * @brief initialized the city grid
     * only use even positive integers , so cardinal_points works as intended
     */

    ~CityGrid();
    /**
     * @brief destructor for the city grid
     * deletes the pointer to  the grid and free that space.
     */

    bool addRoad(int, int, int, string, string); // adds a road with a streetname
    /**
     * @brief adds a road to the city grid
     *
     * @return boolean, returns true or false as to whether the road was added or not
     */

    bool removeRoad(int, int, int, string);
    /**
     * @brief removes a road from the city grid
     *
     * @return boolean, returns true or false as to whether the road was removed or not
     */

    bool removeRoad(string); // removes a road by streetName
    /**
     * @brief removes a road from the city grid
     *
     * @return boolean, returns true or false as to whether the road was removed or not
     */

    const char getAttribute_from_DetailedAttribute(string);
    /**
     * @brief converts the detailed attribute member variable to a char attribute
     *
     * @return constant char, returns a constant char that is the attribute
     */

    void printCityGrid();
    /**
     * @brief prints the city grid
     *
     */
    void printCityCardinal();
    /**
     * @brief prints all the cardinal directions of every cell in the grid
     */

    void printCityStreets();
    /**
     * @brief prints all streets in the city grid
     */

    void printCityRoadNetwork();
    /**
     * @brief prints all the roads in the city
     */

    vector<pair<int, int>> errorPair();
    /**
     * @brief a constant vector pair of 4 pairs of -1 integers
     *
     * @return vector<pair<int,int>> ,returns the vector pair
     */

    vector<pair<int, int>> addBuilding(int, int, Building *);
    /**
     * @brief adds a building to the city grid
     *
     * @return vector<pair<int,int>> , returns the building co-ordiantes. All 4 corner
     */

    bool removeBuilding(vector<pair<int, int>>);
    /**
     * @brief removes a building from the city grid
     *
     * @return boolean, returns true or false as to whether the building was removed or not
     */

    int getDistance(Building *, Building *);
    /**
     * @brief gets the distance between two buildings
     *
     * @return int, returns the distance between two buidlings
     */
};

#endif /* GRID_H */