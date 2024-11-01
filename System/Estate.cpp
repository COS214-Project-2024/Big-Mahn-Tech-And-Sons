// Class implementation of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file Estate.cpp
 * @brief Implementation of the Estate class.
 */

#include "Estate.h"
#include <iostream>

/**
 * @brief Constructs an Estate with default values for a luxury residential setting.
 */
Estate::Estate()
    : ResidentialBuilding() {
    name = "Luxury Estate";
    maxCapacity = 10;
    width = 40;
    length = 60;
    electricityMeterBox = 300.0;
    waterMeterBox = 800.0;
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 500000.0;
    type = "Estate";
}

/**
 * @brief Displays the estate's statistics, including inherited attributes.
 */
void Estate::displayStats() const {
    ResidentialBuilding::displayStats();  // Display general stats for residential buildings
}

/**
 * @brief Accepts a TaxManager visitor for processing estate-specific operations.
 * @param visitor A pointer to the TaxManager visitor.
 */
void Estate::accept(TaxManager* visitor) {
    visitor->visitResidentialBuilding(this);
}

/**
 * @brief Clones the Estate for restoration, supporting repair after damage.
 * @return Building* A pointer to the newly cloned Estate instance.
 */
Building* Estate::repairClone() const {
    std::cout << "Repairing residential building (Estate): " << getName() << "\n";
    return new Estate(*this);
}