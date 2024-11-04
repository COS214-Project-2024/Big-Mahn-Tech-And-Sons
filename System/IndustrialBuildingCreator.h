// Class definition of Factory Method - ConcreteCreator participant

/**
 * @file IndustrialBuildingCreator.h
 * @brief Defines the IndustrialBuildingCreator class for creating industrial buildings.
 */

#ifndef INDUSTRIALBUILDINGCREATOR_H
#define INDUSTRIALBUILDINGCREATOR_H

#include <string>   // For std::string
#include <iostream> // For error handling output

#include "BuildingCreator.h"
#include "Factory.h"
#include "Warehouse.h"
#include "Airport.h"
#include "TrainStation.h"

/**
 * @class IndustrialBuildingCreator
 * @brief Concrete creator for generating industrial buildings.
 *
 * Implements the factory method to create various types of industrial buildings
 * such as factories, warehouses, airports, and train stations.
 */
class IndustrialBuildingCreator : public BuildingCreator
{

public:
    /**
     * @brief Creates an industrial building of the specified type.
     *
     * Based on the provided type string, this function returns a pointer
     * to the corresponding industrial building.
     *
     * @param type Type of the industrial building to create (e.g., "Factory", "Warehouse", "Airport", "TrainStation").
     * @return Building* Pointer to the created industrial building or `nullptr` if the type is unknown.
     */
    Building *createBuilding(const std::string &type) const override;
};

#endif // INDUSTRIALBUILDINGCREATOR_H
