// Class defintion of Factory Method - ConcreteCreator

/**
 * @file CommercialBuildingCreator.h
 * @brief Declaration of the CommercialBuildingCreator class for commercial building creation.
 */

#ifndef COMMERCIALBUILDINGCREATOR_H
#define COMMERCIALBUILDINGCREATOR_H

#include <memory>      // For std::shared_ptr
#include <stdexcept>   // For std::invalid_argument
#include <string>      // For std::string

#include "BuildingCreator.h"
#include "Shop.h"
#include "Office.h"
#include "School.h"
#include "Hospital.h"

/**
 * @class CommercialBuildingCreator
 * @brief Concrete creator for commercial buildings.
 * 
 * This class implements the factory method to create commercial buildings
 * such as shops, offices, schools, and hospitals.
 */
class CommercialBuildingCreator : public BuildingCreator {
public:
    /**
     * @brief Creates a commercial building of a specific type.
     * 
     * Depending on the provided type string, this method creates and returns
     * a shared pointer to the corresponding commercial building.
     * 
     * @param type Type of the commercial building to create (e.g., "Shop", "Office").
     * @return std::shared_ptr<Building> A shared pointer to the created commercial building.
     * @throws std::invalid_argument If the provided type is not recognized.
     */
    std::shared_ptr<Building> createBuilding(const std::string& type) const override;
};

#endif // COMMERCIALBUILDINGCREATOR_H
