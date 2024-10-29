// Class defintion of Factory Method - ConcreteCreator

/**
 * @file IndustrialBuildingCreator.h
 * @brief Declaration of the IndustrialBuildingCreator class for industrial building creation.
 */

#ifndef INDUSTRIALBUILDINGCREATOR_H
#define INDUSTRIALBUILDINGCREATOR_H

#include <memory>      // For std::shared_ptr
#include <stdexcept>   // For std::invalid_argument
#include <string>      // For std::string

#include "BuildingCreator.h"
#include "Factory.h"
#include "Warehouse.h"
#include "Airport.h"
#include "TrainStation.h"

/**
 * @class IndustrialBuildingCreator
 * @brief Concrete creator for industrial buildings.
 * 
 * This class implements the factory method to create industrial buildings
 * such as factories, warehouses, airports, and train stations.
 */
class IndustrialBuildingCreator : public BuildingCreator {
public:
    /**
     * @brief Creates an industrial building of a specific type.
     * 
     * Depending on the provided type string, this method creates and returns
     * a shared pointer to the corresponding industrial building.
     * 
     * @param type Type of the industrial building to create (e.g., "Factory", "Airport").
     * @return std::shared_ptr<Building> A shared pointer to the created industrial building.
     * @throws std::invalid_argument If the provided type is not recognized.
     */
    std::shared_ptr<Building> createBuilding(const std::string& type) const override;
};

#endif // INDUSTRIALBUILDINGCREATOR_H