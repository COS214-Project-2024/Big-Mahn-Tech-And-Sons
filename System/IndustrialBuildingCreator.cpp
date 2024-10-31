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
        return new Factory();
    }
    else if (type == "Warehouse")
    {
        return new Warehouse();
    }
    else if (type == "Airport")
    {
        return new Airport();
    }
    else if (type == "TrainStation")
    {
        return new TrainStation();
    }
    else
    {
        throw std::invalid_argument("Unknown industrial building type: " + type);
    }
}