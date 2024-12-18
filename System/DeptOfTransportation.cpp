#include "DeptOfTransportation.h"
#include "Building.h"
DeptOfTransportation *DeptOfTransportation::instance = nullptr;

DeptOfTransportation::DeptOfTransportation()
{
    cityGrid = new CityGrid(30, 30);
}

DeptOfTransportation::~DeptOfTransportation()
{
    delete cityGrid;
}

DeptOfTransportation *DeptOfTransportation::getInstance()
{
    if (!instance)
    {
        instance = new DeptOfTransportation();
    }
    return instance;
}

bool DeptOfTransportation::add_Road(int start_row, int start_col, int street_Length, string direction, string street_name)
{
    if (cityGrid->addRoad(start_row, start_col, street_Length, direction, street_name))
    {
        return true;
    }
    return false;
}

void DeptOfTransportation::printCityGrid()
{
    cityGrid->printCityGrid();
}

void DeptOfTransportation::printRoadNetwork()
{
    cityGrid->printCityRoadNetwork();
}

void DeptOfTransportation::printCityCardinalPoints()
{
    cityGrid->printCityCardinal();
}

void DeptOfTransportation::printCityStreets()
{
    cityGrid->printCityStreets();
}

bool DeptOfTransportation::remove_Road(string streetName)
{
    if (cityGrid->removeRoad(streetName))
    {

        return true;
    }

    return false;
}

bool DeptOfTransportation::remove_Road(int start_row, int start_col, int road_length, string direction)
{
    if (cityGrid->removeRoad(start_row, start_col, road_length, direction))
    {

        return true;
    }

    return false;
}

const vector<pair<int, int>> DeptOfTransportation::add_Building(int length, int width, Building *building)
{
    vector<pair<int, int>> error = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
    vector<pair<int, int>> result = cityGrid->addBuilding(length, width, building);
    if (result == error)
    {

        building->setCoordinates(result);
        return result;
    }

    return result;
}

bool DeptOfTransportation::remove_Building(vector<pair<int, int>> buidling)
{
    if (cityGrid->removeBuilding(buidling))
    {

        return true;
    }

    return true;
}

int DeptOfTransportation::get_distance(Building *citizen_current_building, Building *citizen_destination_building)
{
    return 1 + cityGrid->getDistance(citizen_current_building, citizen_destination_building); // added 1 , because of the off by 1 error.
}