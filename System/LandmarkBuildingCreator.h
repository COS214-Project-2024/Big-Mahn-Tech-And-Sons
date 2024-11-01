// Class definition of Factory Method - ConcreteCreator participant

/**
 * @file LandmarkBuildingCreator.h
 * @brief Defines the LandmarkBuildingCreator class for creating landmark buildings.
 */

#ifndef LANDMARKBUILDINGCREATOR_H
#define LANDMARKBUILDINGCREATOR_H

#include <string>  // For std::string
#include <iostream> // For error handling output

#include "BuildingCreator.h"
#include "Park.h"
#include "Monument.h"
#include "Museum.h"

/**
 * @class LandmarkBuildingCreator
 * @brief Concrete creator for generating landmark buildings.
 * 
 * Implements the factory method to create various types of landmark buildings 
 * such as parks, monuments, and museums.
 */
class LandmarkBuildingCreator : public BuildingCreator {

    public:
        /**
         * @brief Creates a landmark building of the specified type.
         * 
         * Based on the provided type string, this function returns a pointer 
         * to the corresponding landmark building.
         * 
         * @param type Type of the landmark building to create (e.g., "Park", "Monument", "Museum").
         * @return Building* Pointer to the created landmark building or `nullptr` if the type is unknown.
         */
        Building* createBuilding(const std::string& type) const override;
};

#endif // LANDMARKBUILDINGCREATOR_H
