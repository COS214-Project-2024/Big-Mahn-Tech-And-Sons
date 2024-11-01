// Class implementation of Factory Method - ConcreteCreator participant

/**
 * @file CommercialBuildingCreator.cpp
 * @brief Implements the CommercialBuildingCreator class.
 */

#include "CommercialBuildingCreator.h"

/**
 * @brief Creates a commercial building of the specified type.
 * 
 * Based on the type parameter, this method generates and returns a pointer 
 * to a new instance of the specified commercial building (Shop, Office, School, or Hospital).
 * If the type is unrecognized, it logs an error and returns `nullptr`.
 * 
 * @param type The type of commercial building to create (e.g., "Shop", "Office", "School", "Hospital").
 * @return Building* Pointer to the created building instance or `nullptr` if the type is invalid.
 */
Building* CommercialBuildingCreator::createBuilding(const std::string &type) const {
    if (type == "Shop") {
        return new Shop();
    } else if (type == "Office") {
        return new Office();
    } else if (type == "School") {
        return new School();
    } else if (type == "Hospital") {
        return new Hospital();
    } else {
        // Display error message if building type is not recognized
        std::cerr << "Error: Unknown commercial building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}