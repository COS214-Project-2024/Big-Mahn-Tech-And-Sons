// Class implementation of Factory Method - ConcreteCreator

/**
 * @file IndustrialBuildingCreator.cpp
 * @brief Implementation of the IndustrialBuildingCreator class.
 */

#include "IndustrialBuildingCreator.h"

std::shared_ptr<Building> IndustrialBuildingCreator::createBuilding(const std::string& type) const {
    if (type == "Factory") {
        return std::make_shared<Factory>();
    } else if (type == "Warehouse") {
        return std::make_shared<Warehouse>();
    } else if (type == "Airport") {
        return std::make_shared<Airport>();
    } else if (type == "TrainStation") {
        return std::make_shared<TrainStation>();
    } else {
        throw std::invalid_argument("Unknown industrial building type: " + type);
    }
}
