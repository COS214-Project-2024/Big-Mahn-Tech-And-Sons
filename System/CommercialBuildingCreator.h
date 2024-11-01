// Class definition of Factory Method - ConcreteCreator participant 

/**
 * @file CommercialBuildingCreator.h
 * @brief Declaration of the CommercialBuildingCreator class for commercial building creation.
 */

#ifndef COMMERCIALBUILDINGCREATOR_H
#define COMMERCIALBUILDINGCREATOR_H

#include <string>      // For std::string
#include <iostream>    // For error handling output

#include "BuildingCreator.h"
#include "Shop.h"
#include "Office.h"
#include "School.h"
#include "Hospital.h"

/**
 * @class CommercialBuildingCreator
 * @brief Concrete creator for generating commercial buildings.
 * 
 * Implements the factory method to create various types of commercial buildings 
 * such as shops, offices, schools, and hospitals.
 */
class CommercialBuildingCreator : public BuildingCreator {
    
    public:
        /**
         * @brief Creates a commercial building of the specified type.
         * 
         * Based on the provided type string, this function returns a pointer 
         * to the corresponding commercial building.
         * 
         * @param type Type of the commercial building to create (e.g., "Shop", "Office", "School", "Hospital").
         * @return Building* Pointer to the created commercial building or `nullptr` if the type is unknown.
         */
        Building* createBuilding(const std::string& type) const override;
};

#endif // COMMERCIALBUILDINGCREATOR_H
