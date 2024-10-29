// Class implementation of Factory Method - ConcreteCreator

/**
 * @file LandmarkBuildingCreator.cpp
 * @brief Implementation of the LandmarkBuildingCreator class.
 */

#include "LandmarkBuildingCreator.h"

std::shared_ptr<Building> LandmarkBuildingCreator::createBuilding(const std::string& type) const {
    if (type == "Park") {
        return std::make_shared<Park>();
    } else if (type == "Monument") {
        return std::make_shared<Monument>();
    } else if (type == "Museum") {
        return std::make_shared<Museum>();
    } else {
        throw std::invalid_argument("Unknown landmark building type: " + type);
    }
}
