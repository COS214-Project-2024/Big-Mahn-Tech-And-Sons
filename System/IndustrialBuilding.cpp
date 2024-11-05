// Class defintion of Factory Method - ConcreteProduct (classification)

/**
 * @file IndustrialBuilding.cpp
 * @brief Implements the IndustrialBuilding class.
 */

#include "IndustrialBuilding.h"
#include "TaxManager.h"
#include <iostream>

/**
 * @brief Default constructor for IndustrialBuilding.
 */
IndustrialBuilding::IndustrialBuilding()
    : Building() {}

/**
 * @brief Displays statistics specific to industrial buildings.
 */
void IndustrialBuilding::displayStats() const
{
    Building::displayStats(); // Call base class method for any common stats
}

void IndustrialBuilding::accept(TaxManager *visitor)
{
}

/**
 * @brief Calculates tax for an industrial building.
 * Since industrial buildings are exempt, this returns 0.0.
 *
 * @return Tax amount (0.0).
 */
Building *IndustrialBuilding::repairClone() const
{
    return nullptr;
}
double IndustrialBuilding::calculateTax() const
{
    return 0.0;
}
