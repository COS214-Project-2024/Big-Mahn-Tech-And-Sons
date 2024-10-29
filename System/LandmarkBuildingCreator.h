// Class defintion of Factory Method - ConcreteCreator

/**
 * @file LandmarkBuildingCreator.h
 * @brief Declaration of the LandmarkBuildingCreator class for landmark building creation.
 */

#ifndef LANDMARKBUILDINGCREATOR_H
#define LANDMARKBUILDINGCREATOR_H

#include <memory>      // For std::shared_ptr
#include <stdexcept>   // For std::invalid_argument
#include <string>      // For std::string

#include "BuildingCreator.h"
#include "Park.h"
#include "Monument.h"
#include "Museum.h"

/**
 * @class LandmarkBuildingCreator
 * @brief Concrete creator for landmark buildings.
 * 
 * This class implements the factory method to create landmark buildings
 * such as parks, monuments, and museums.
 */
class LandmarkBuildingCreator : public BuildingCreator {
public:
    /**
     * @brief Creates a landmark building of a specific type.
     * 
     * Depending on the provided type string, this method creates and returns
     * a shared pointer to the corresponding landmark building.
     * 
     * @param type Type of the landmark building to create (e.g., "Park", "Monument").
     * @return std::shared_ptr<Building> A shared pointer to the created landmark building.
     * @throws std::invalid_argument If the provided type is not recognized.
     */
    std::shared_ptr<Building> createBuilding(const std::string& type) const override;
};

#endif // LANDMARKBUILDINGCREATOR_H
