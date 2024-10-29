// Class defintion of Factory Method - Creator participant

/**
 * @file BuildingCreator.h
 * @brief Declaration of the BuildingCreator interface for creating buildings.
 */

#ifndef BUILDINGCREATOR_H
#define BUILDINGCREATOR_H

#include <memory>  // For std::shared_ptr
#include <string>  // For std::string
#include "Building.h"  // Include Building class

/**
 * @class BuildingCreator
 * @brief Abstract factory interface for creating building objects.
 * 
 * The BuildingCreator defines an interface for creating buildings of different types.
 * Concrete creators (e.g., ResidentialBuildingCreator) will implement this interface 
 * to provide specific building types based on the given input.
 */
class BuildingCreator {
public:
    /**
     * @brief Creates a building object based on the provided type.
     * 
     * This method allows the creation of different building types (e.g., residential, 
     * commercial) depending on the input string. Each concrete subclass implements 
     * this method to handle specific building types.
     * 
     * @param type The type of building to create (e.g., "estate", "hospital").
     * @return std::shared_ptr<Building> A shared pointer to the created building object.
     * @throws std::invalid_argument If the provided building type is not recognized.
     */
    virtual std::shared_ptr<Building> createBuilding(const std::string& type) const = 0;

    /**
     * @brief Virtual destructor for the BuildingCreator interface.
     * 
     * Ensures proper cleanup of derived classes when deleting via a pointer to the base class.
     */
    virtual ~BuildingCreator() = default;
};

#endif // BUILDINGCREATOR_H