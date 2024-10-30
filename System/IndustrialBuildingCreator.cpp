// Class implementation of Factory Method - ConcreteCreator

/**
 * @file IndustrialBuildingCreator.cpp
 * @brief Implementation of the IndustrialBuildingCreator class.
 */

#include "IndustrialBuildingCreator.h"

std::shared_ptr<Building> IndustrialBuildingCreator::createBuilding(const std::string& type) const {
    if (type == "Factory") {
        return std::make_shared<Factory>(type, 100, 100, 30);
    } else if (type == "Warehouse") {
        return std::make_shared<Warehouse>(type, 90, 90, 90);
    } else if (type == "Airport") {
        return std::make_shared<Airport>(type, 20, 20, 100, 90);
    } else if (type == "TrainStation") {
        return std::make_shared<TrainStation>(type, 40, 30, 50, 90);
    } else {
        throw std::invalid_argument("Unknown industrial building type: " + type);
    }
}
