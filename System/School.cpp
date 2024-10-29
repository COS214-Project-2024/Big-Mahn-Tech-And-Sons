// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "School.h"
#include <iostream>

/**
 * @brief Constructor for School.
 * @param name Name of the school.
 * @param maxCapacity Maximum capacity of the school.
 */
School::School(const std::string& name, int maxCapacity)
    : CommercialBuilding(name, maxCapacity), availableKidsSpaces(maxCapacity) {
    width = 15;  // Set a unique width for school
    length = 30; // Set a unique length for school
    electricityMeterBox = 200.0; // Initial electricity meter reading
    waterMeterBox = 300.0;       // Initial water meter reading
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 300000.0; // Setting price tag for School
    netWorth = 1200000.0;
}

/**
 * @brief Displays the stats specific to the school.
 */
void School::displayStats() const {
    CommercialBuilding::displayStats();  // Call base class method
    std::cout << "Available Kids' Spaces: " << availableKidsSpaces << std::endl;
}

/**
 * @brief Checks the availability of kids' spaces in the school.
 * @return True if kids' spaces are available, otherwise false.
 */
bool School::checkAvailability() const {
    return availableKidsSpaces > 0;  // Kids' spaces are available if any exist
}

/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void School::accept(TaxManager* visitor) {
    visitor->visitCommercialBuilding(this);
}
