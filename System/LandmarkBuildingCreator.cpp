// Class implementation of Factory Method - ConcreteCreator participant

/**
 * @file LandmarkBuildingCreator.cpp
 * @brief Implements the LandmarkBuildingCreator class.
 */

#include "LandmarkBuildingCreator.h"

Building* LandmarkBuildingCreator::createBuilding(const std::string& type) const {
    if (type == "Park") {
        return new Park();
    } else if (type == "Monument") {
        return new Monument();
    } else if (type == "Museum") {
        return new Museum();
    } else {
        // Display error message if building type is not recognized
        std::cerr << "Error: Unknown landmark building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}
