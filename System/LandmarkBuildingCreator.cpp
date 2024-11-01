// Class implementation of Factory Method - ConcreteCreator participant

/**
 * @file LandmarkBuildingCreator.cpp
 * @brief Implements the LandmarkBuildingCreator class.
 */

#include "LandmarkBuildingCreator.h"

/**
 * @brief Creates a landmark building of the specified type.
 * 
 * Based on the type parameter, this method generates and returns a pointer 
 * to a new instance of the specified landmark building (Park, Monument, or Museum).
 * If the type is unrecognized, it logs an error and returns `nullptr`.
 * 
 * @param type The type of landmark building to create (e.g., "Park", "Monument", "Museum").
 * @return Building* Pointer to the created building instance or `nullptr` if the type is invalid.
 */
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
