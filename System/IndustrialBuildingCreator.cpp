// Class implementation of Factory Method - ConcreteCreator

/**
 * @file IndustrialBuildingCreator.cpp
 * @brief Implementation of the IndustrialBuildingCreator class.
 */

#include "IndustrialBuildingCreator.h"

Building *IndustrialBuildingCreator::createBuilding(const std::string &type) const
{
    if (type == "Factory")
    {
        return new Factory(type, 100, 100, 30);
    }
    else if (type == "Warehouse")
    {
        return new Warehouse(type , 90 , 90 , 90);
    }
    else if (type == "Airport")
    {
        return new Airport(type, 20, 20, 100, 90);
    }
    else if (type == "TrainStation")
    {
        return new TrainStation(type, 40, 30, 50, 90);
    }
    else
    {
        throw std::invalid_argument("Unknown industrial building type: " + type);
    }
}