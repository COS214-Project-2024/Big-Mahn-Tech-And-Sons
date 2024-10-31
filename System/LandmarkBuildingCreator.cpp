// Class implementation of Factory Method - ConcreteCreator

/**
 * @file LandmarkBuildingCreator.cpp
 * @brief Implementation of the LandmarkBuildingCreator class.
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
        throw std::invalid_argument("Unknown landmark building type: " + type);
    }
}

