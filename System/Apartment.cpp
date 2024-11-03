// Class implementation of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file Apartment.cpp
 * @brief Implementation of the Apartment class.
 */

#include "Apartment.h"
#include <iostream>

/**
 * @brief Constructs an Apartment with default values specific to urban apartments.
 */
Apartment::Apartment()
    : ResidentialBuilding() {
    name = "Urban Apartment";
    maxCapacity = 50;
    width = 30;
    length = 50;
    electricityMeterBox = 200.0;
    waterMeterBox = 500.0;
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 150000.0;
    type = "Apartment";
}

/**
 * @brief Displays the statistics of the apartment, including inherited and specific attributes.
 */
void Apartment::displayStats() const {
    ResidentialBuilding::displayStats();  // Display general stats for residential buildings
}

/**
 * @brief Accepts a TaxManager visitor for performing tax-related operations.
 * @param visitor A pointer to the TaxManager visitor.
 */
void Apartment::accept(TaxManager* visitor) {
    visitor->visitResidentialBuilding(this);
}

/**
 * @brief Clones the Apartment for repair, supporting restoration after damage.
 * @return Building* A pointer to the newly cloned Apartment instance.
 */
Building* Apartment::repairClone() const {
    std::cout << "Repairing residential building (Apartment): " << getName() << "\n";
    return new Apartment(*this);
}

