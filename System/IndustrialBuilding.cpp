// Class defintion of Factory Method - ConcreteProduct (classification)

/**
 * @file IndustrialBuilding.cpp
 * @brief Implements the IndustrialBuilding class.
 */

#include "IndustrialBuilding.h"
#include <iostream>

/**
 * @brief Default constructor for IndustrialBuilding.
 */
IndustrialBuilding::IndustrialBuilding()
    : Building() {}

/**
 * @brief Displays statistics specific to industrial buildings.
 */
void IndustrialBuilding::displayStats() const {
    Building::displayStats();  // Call base class method for any common stats
}