// Class definition of Factory Method - ConcreteCreator participant 

/**
 * @file ResidentialBuildingCreator.h
 * @brief Defines the ResidentialBuildingCreator class for creating residential buildings.
 */

#ifndef RESIDENTIALBUILDINGCREATOR_H
#define RESIDENTIALBUILDINGCREATOR_H

#include <string>  // For std::string
#include <iostream> // For error handling output

#include "BuildingCreator.h"
#include "House.h"
#include "Apartment.h"
#include "Estate.h"

/**
 * @class ResidentialBuildingCreator
 * @brief Concrete creator for generating residential buildings.
 * 
 * Implements the factory method to create various types of residential buildings 
 * such as estates, apartments, and houses.
 */
class ResidentialBuildingCreator : public BuildingCreator {
    
    public:
        /**
         * @brief Creates a residential building of the specified type.
         * 
         * Based on the provided type string, this function returns a pointer 
         * to the corresponding residential building.
         * 
         * @param type Type of the residential building to create (e.g., "Estate", "Apartment", "House").
         * @return Building* Pointer to the created residential building or `nullptr` if the type is unknown.
         */
        Building* createBuilding(const std::string& type) const override;
};

#endif // RESIDENTIALBUILDINGCREATOR_H
