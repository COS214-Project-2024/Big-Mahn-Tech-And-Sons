// Class implementation of Factory Method - ConcreteCreator

/**
 * @file CommercialBuildingCreator.cpp
 * @brief Implementation of the CommercialBuildingCreator class.
 */

#include "CommercialBuildingCreator.h"

std::shared_ptr<Building> CommercialBuildingCreator::createBuilding(const std::string& type) const {
    if (type == "Shop") {
        return std::make_shared<Shop>(type, 100);
    } else if (type == "Office") {
        return std::make_shared<Office>(type, 100);
    } else if (type == "School") {
        return std::make_shared<School>(type, 100);
    } else if (type == "Hospital") {
        return std::make_shared<Hospital>(type, 100);
    } else {
        throw std::invalid_argument("Unknown commercial building type: " + type);
    }
}
