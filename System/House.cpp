// Class implementation of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file House.cpp
 * @brief Implementation of the House class.
 */

#include "House.h"
#include <iostream>

/**
 * @brief Constructs a House with default values specific to a family home.
 */
House::House()
    : ResidentialBuilding() {
    name = "Family House";
    maxCapacity = 4;
    width = 15;
    length = 20;
    electricityMeterBox = 50.0;
    waterMeterBox = 100.0;
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 250000.0;
    type = "House";
}

/**
 * @brief Displays the statistics of the house, including inherited and specific attributes.
 */
void House::displayStats() const {
    ResidentialBuilding::displayStats();  // Display general stats for residential buildings
}

/**
 * @brief Accepts a TaxManager visitor for performing tax-related operations.
 * @param visitor A pointer to the TaxManager visitor.
 */
void House::accept(TaxManager* visitor) {
    visitor->visitResidentialBuilding(this);
}

/**
 * @brief Clones the House for repair, simulating repair action feedback.
 * @return Building* A pointer to the newly cloned House instance.
 */
Building* House::repairClone() const {
    std::cout << "Prototype: Cloning a Shop building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing residential building (House): " << getName() << "\n";
    return new House(*this);
}
