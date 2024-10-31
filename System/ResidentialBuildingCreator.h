// Class defintion of Factory Method - ConcreteCreator participant

/**
 * @file ResidentialBuildingCreator.h
 * @brief Declaration of the ResidentialBuildingCreator class for residential building creation.
 */

#ifndef RESIDENTIALBUILDINGCREATOR_H
#define RESIDENTIALBUILDINGCREATOR_H

#include <memory>      // For std::shared_ptr
#include <stdexcept>   // For std::invalid_argument
#include <string>      // For std::string

#include "BuildingCreator.h"
#include "House.h"
#include "Apartment.h"
#include "Estate.h"

/**
 * @class ResidentialBuildingCreator
 * @brief Concrete creator for residential buildings.
 * 
 * This class implements the factory method to create residential buildings
 * such as estates, apartments, and houses.
 */
class ResidentialBuildingCreator : public BuildingCreator {
public:
    /**
     * @brief Creates a residential building of a specific type.
     * 
     * Depending on the provided type string, this method creates and returns
     * a shared pointer to the corresponding residential building.
     * 
     * @param type Type of the residential building to create (e.g., "Estate", "Apartment").
     * @return std::shared_ptr<Building> A shared pointer to the created residential building.
     * @throws std::invalid_argument If the provided type is not recognized.
     */
    Building* createBuilding(const std::string& type) const override;
};

#endif // RESIDENTIALBUILDINGCREATOR_H