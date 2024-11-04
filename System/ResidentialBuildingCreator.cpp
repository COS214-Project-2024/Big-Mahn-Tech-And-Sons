// Class implementation of Factory Method - ConcreteCreator participant

/**
 * @file ResidentialBuildingCreator.cpp
 * @brief Implements the ResidentialBuildingCreator class.
 */

#include "ResidentialBuildingCreator.h"

/**
 * @brief Creates a residential building of the specified type.
 * 
 * Based on the type parameter, this method generates and returns a pointer 
 * to a new instance of the specified residential building (Estate, Apartment, or House).
 * If the type is unrecognized, it logs an error and returns `nullptr`.
 * 
 * @param type The type of residential building to create (e.g., "Estate", "Apartment", "House").
 * @return Building* Pointer to the created building instance or `nullptr` if the type is invalid.
 */
Building* ResidentialBuildingCreator::createBuilding(const std::string &type) const {
    if (type == "Estate") {
        std::cout << "Factory Method: Creating an Estate building.\n"; // Output indicating Factory Method pattern
        return new Estate();
    } else if (type == "Apartment") {
        std::cout << "Factory Method: Creating an Apartment building.\n"; // Output indicating Factory Method pattern
        return new Apartment();
    } else if (type == "House") {
        std::cout << "Factory Method: Creating a House building.\n"; // Output indicating Factory Method pattern
        return new House();
    } else {
        // Display error message if building type is not recognized
        std::cout << "Error: Unknown residential building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}
