// Class implementation of Factory Method - ConcreteCreator

/**
 * @file CommercialBuildingCreator.cpp
 * @brief Implementation of the CommercialBuildingCreator class.
 */

#include "CommercialBuildingCreator.h"

Building *CommercialBuildingCreator::createBuilding(const std::string &type) const
{
    if (type == "Shop")
    {
        return new Shop(type, 100);
    }
    else if (type == "Office")
    {
        return new Office(type, 100);
    }
    else if (type == "School")
    {
        return new School(type, 100);
    }
    else if (type == "Hospital")
    {
        return new Hospital(type, 100);
    }
    else
    {
        throw std::invalid_argument("Unknown commercial building type: " + type);
    }
}
