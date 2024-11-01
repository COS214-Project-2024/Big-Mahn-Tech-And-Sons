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
        return new Shop();
    }
    else if (type == "Office")
    {
        return new Office();
    }
    else if (type == "School")
    {
        return new School();
    }
    else if (type == "Hospital")
    {
        return new Hospital();
    }
    else
    {
        throw std::invalid_argument("Unknown commercial building type: " + type);
    }
}