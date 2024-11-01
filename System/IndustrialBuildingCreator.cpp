// Class implementation of Factory Method - ConcreteCreator participant

/**
 * @file IndustrialBuildingCreator.cpp
 * @brief Implements the IndustrialBuildingCreator class.
 */

#include "IndustrialBuildingCreator.h"

/**
 * @brief Creates an industrial building of the specified type.
 * 
 * Based on the type parameter, this method generates and returns a pointer 
 * to a new instance of the specified industrial building (Factory, Warehouse, Airport, or TrainStation).
 * If the type is unrecognized, it logs an error and returns `nullptr`.
 * 
 * @param type The type of industrial building to create (e.g., "Factory", "Warehouse", "Airport", "TrainStation").
 * @return Building* Pointer to the created building instance or `nullptr` if the type is invalid.
 */
Building* IndustrialBuildingCreator::createBuilding(const std::string &type) const {
    if (type == "Factory") {
        return new Factory();
    } else if (type == "Warehouse") {
        return new Warehouse();
    } else if (type == "Airport") {
        return new Airport();
    } else if (type == "TrainStation") {
        return new TrainStation();
    } else {
        // Display error message if building type is not recognized
        std::cerr << "Error: Unknown industrial building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}
