// Class implementation of Factory Method - ConcreteCreator

/**
 * @file ResidentialBuildingCreator.cpp
 * @brief Implementation of the ResidentialBuildingCreator class.
 */

#include "ResidentialBuildingCreator.h"

Building *ResidentialBuildingCreator::createBuilding(const std::string &type) const
{
    if (type == "Estate")
    {
        return new Estate();
    }
    else if (type == "Apartment")
    {
        return new Apartment();
    }
    else if (type == "House")
    {
        return new House();
    }
    else
    {
        throw std::invalid_argument("Unknown residential building type: " + type);
    }
}