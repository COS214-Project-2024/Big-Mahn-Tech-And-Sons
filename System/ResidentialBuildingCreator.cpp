// Class implementation of Factory Method - ConcreteCreator

/**
 * @file ResidentialBuildingCreator.cpp
 * @brief Implementation of the ResidentialBuildingCreator class.
 */

#include "ResidentialBuildingCreator.h"

std::shared_ptr<Building> ResidentialBuildingCreator::createBuilding(const std::string& type) const {
    if (type == "Estate") {
        return std::make_shared<Estate>();
    } else if (type == "Apartment") {
        return std::make_shared<Apartment>();
    } else if (type == "House") {
        return std::make_shared<House>();
    } else {
        throw std::invalid_argument("Unknown residential building type: " + type);
    }
}