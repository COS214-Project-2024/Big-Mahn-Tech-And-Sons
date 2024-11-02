
#include "DeptOfTransportation.h"
#include "CityGrid.h"

DeptOfTransportation *DeptOfTransportation::instance = nullptr;

DeptOfTransportation::DeptOfTransportation()
{
    cityGrid = new CityGrid(20, 20);
}

DeptOfTransportation::~DeptOfTransportation()
{
    delete cityGrid;
}

const vector<Building *> &DeptOfTransportation::getAllBuildings() const
{
    return buildings;
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
        cout << "\nRoad added ~ DeptTrans\n";
        return true;
    }
    cout << "\nRoad not added ~ DeptTrans\n";
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

void DeptOfTransportation::printCityBuildings() const
{
     cout << "All Buildings in the City:\n";
    for (const auto& building : buildings) {
        cout << "Type: " << building->getType() 
             << ", Name: " << building->getName()
             << ", Coordinates: ";
        for (const auto& coord : building->getGridCoordinates()) {
            cout << "(" << coord.first << "," << coord.second << ") ";
        }
        cout << endl;
    }
}

bool DeptOfTransportation::remove_Road(string streetName)
{
    if (cityGrid->removeRoad(streetName))
    {
        cout << "\nRoad removed ~ DeptTrans\n";
        return true;
    }

    cout << "\nRoad not removed ~ DeptTrans\n";
    return false;
}

bool DeptOfTransportation::remove_Road(int start_row, int start_col, int road_length, string direction)
{
    if (cityGrid->removeRoad(start_row, start_col, road_length, direction))
    {
        cout << "\nRoad removed ~ DeptTrans\n";
        return true;
    }

    cout << "\nRoad not removed ~ DeptTrans\n";
    return false;
}

const vector<pair<int, int>> DeptOfTransportation::add_Building(int length, int width, string building_type)
{
    vector<pair<int, int>> error = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
    Building *building = nullptr;

    string building_type_lower = building_type;
    building_type_lower[0] = toupper(building_type_lower[0]);
    for (int i = 1; i < building_type_lower.length(); i++)
    {
        building_type_lower[i] = tolower(building_type_lower[i]);
    }
    
    try
    {
       
        if (building_type == "Estate" || building_type == "Apartment" || building_type == "House")
        {
            ResidentialBuildingCreator residentialCreator;
            building = residentialCreator.createBuilding(building_type);
        }
        else if (building_type == "Shop" || building_type == "Office" ||
                 building_type == "School" || building_type == "Hospital")
        {
            CommercialBuildingCreator commercialCreator;
            building = commercialCreator.createBuilding(building_type);
        }
        else if (building_type == "Factory" || building_type == "Warehouse" ||
                 building_type == "Airport" || building_type == "TrainStation")
        {
            IndustrialBuildingCreator industrialCreator;
            building = industrialCreator.createBuilding(building_type);
        }
        else if (building_type == "Park" || building_type == "Monument" ||
                 building_type == "Museum")
        {
            LandmarkBuildingCreator landmarkCreator;
            building = landmarkCreator.createBuilding(building_type);
        }
        else
        {
            throw std::invalid_argument("Unknown building type: " + building_type);
        }


        vector<pair<int, int>> result = cityGrid->addBuilding(length, width, building_type);

        if (result == error)
        {
            cout << "\nBuilding not added to grid ~DeptTrans.\n";
            delete building;
            return result;
        }
        else
        {
            cout << "\nBuilding added to grid ~ DeptTrans.\n";
            building->setCoordinates(result);
            buildings.push_back(building);
         }
         
          return result;

    } 
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
        delete building;
        return error;
    }
}




bool DeptOfTransportation::remove_Building(vector<pair<int,int>>& buidling)
{
    if(cityGrid->removeBuilding(buidling))
    {
        cout<<"\nBuilding removed from grid ~DeptTrans.\n";
        return true;
    }

    cout<<"\nBuilding not removed from grid ~DeptTrans.\n";
        return true;
}