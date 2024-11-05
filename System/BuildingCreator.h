// Class defintion of Factory Method - Creator participant

/**
 * @file BuildingCreator.h
 * @brief Defines the BuildingCreator interface for creating buildings.
 */

#ifndef BUILDINGCREATOR_H
#define BUILDINGCREATOR_H

#include <string>     // For std::string
#include "Building.h" // Building class

/**
 * @class BuildingCreator
 * @brief Interface for creating building objects of various types.
 *
 * BuildingCreator defines an interface for generating buildings.
 * Concrete creator classes (e.g., ResidentialBuildingCreator) implement
 * this interface to create specific types of buildings based on input.
 */
class BuildingCreator
{

public:
    /**
     * @brief Creates a building object based on the specified type.
     *
     * This function enables the creation of different building types
     * (e.g., residential, commercial) according to the provided type string.
     * Each subclass of BuildingCreator implements this method for particular
     * building types.
     *
     * @param type A string representing the building type (e.g., "estate", "hospital").
     * @return Building* A pointer to the newly created building object.
     * @throws std::invalid_argument if the building type is not recognized.
     */
    virtual Building *createBuilding(const std::string &type) const = 0;

    /**
     * @brief Virtual destructor for the BuildingCreator interface.
     *
     * Ensures derived classes are properly cleaned up when deleted via a base pointer.
     */
    virtual ~BuildingCreator() = default;
};

#endif // BUILDINGCREATOR_H
