// Class implementation of Factory Method - ConcreteCreator

/**
 * @file LandmarkBuildingCreator.cpp
 * @brief Implementation of the LandmarkBuildingCreator class.
 */

#include "LandmarkBuildingCreator.h"

Building* LandmarkBuildingCreator::createBuilding(const std::string& type) const {
    if (type == "Park") {
       return new Park(type, 40, 30, 20, true);
    } else if (type == "Monument") {
        return new Monument(type, 30, 2004,true);
    } else if (type == "Museum") {
       return new Museum(type, 20, 40,13, true);
    } else {
        throw std::invalid_argument("Unknown landmark building type: " + type);
    }
}

