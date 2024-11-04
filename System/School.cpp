// Class implementation of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file School.cpp
 * @brief Implements the School class.
 */

#include "School.h"
#include <iostream>

/**
 * @brief Default constructor for School.
 */
School::School()
    : CommercialBuilding() {
    name = "Bright Future Academy";  // Default name for the school
    maxCapacity = 100;               // Set maximum capacity for the school
    availableKidsSpaces = maxCapacity; // Initialize available kids' spaces to max capacity
    width = 15;                      // Default width for schools
    length = 30;                     // Default length for schools
    electricityMeterBox = 200.0;    // Initial electricity meter reading
    waterMeterBox = 300.0;          // Initial water meter reading
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 300000.0;             // Default price tag for School
    netWorth = 1200000.0;
    type = "School";
    annualRevenue = 200000.0;       // Default annual revenue for School
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
     visitor->visitBuildingForBuilding(this);
    visitor->visitBuildingForCitizen(this);
}

/**
 * @brief Clones the school for repair purposes.
 * @return Pointer to the cloned school object.
 */
Building* School::repairClone() const {
    std::cout << "Prototype: Cloning a School building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing commercial building (School): " << getName() << "\n";
    return new School(*this);  // Return a new cloned instance of School
}
