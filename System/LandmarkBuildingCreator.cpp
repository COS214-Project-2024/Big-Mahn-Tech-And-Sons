// Class implementation of Factory Method - ConcreteCreator participant

/**
 * @file LandmarkBuildingCreator.cpp
 * @brief Implements the LandmarkBuildingCreator class.
 */

#include "LandmarkBuildingCreator.h"

Building* LandmarkBuildingCreator::createBuilding(const std::string& type) const {
    if (type == "Park") {
        std::cout << "Factory Method: Creating a Park building.\n"; // Output indicating Factory Method pattern
        return new Park();
    } else if (type == "Monument") {
        std::cout << "Factory Method: Creating a Monument building.\n"; // Output indicating Factory Method pattern
        return new Monument();
    } else if (type == "Museum") {
        std::cout << "Factory Method: Creating a Museum building.\n"; // Output indicating Factory Method pattern
        return new Museum();
    } else {
        // Display error message if building type is not recognized
        std::cout << "Error: Unknown landmark building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}
