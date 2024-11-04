// Class implementation of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file Office.cpp
 * @brief Implements the Office class.
 */

#include "Office.h"
#include <iostream>

/**
 * @brief Default constructor for Office.
 */
Office::Office()
    : CommercialBuilding() {
    name = "Downtown Office Hub";      // Default name for the office
    maxCapacity = 50;                  // Set max capacity for office
    availableJobs = maxCapacity;       // Initialize available jobs to max capacity
    width = 12;                        // Default width for offices
    length = 20;                       // Default length for offices
    electricityMeterBox = 150.0;
    waterMeterBox = 250.0;
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 200000.0;               // Default price tag for Office
    netWorth = 500000.0;
    type = "Office";
    annualRevenue = 100000.0;          // Default annual revenue for Office
}

/**
 * @brief Displays the stats specific to the office.
 */
void Office::displayStats() const {
    CommercialBuilding::displayStats();  // Call base class method
}

/**
 * @brief Checks the availability of jobs in the office.
 * @return True if jobs are available, otherwise false.
 */
bool Office::checkAvailability() const {
    return availableJobs > 0;  // Jobs are available if any exist
}

/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Office::accept(TaxManager* visitor) {
    visitor->visitCommercialBuilding(this);
}

/**
 * @brief Clones the office for repair purposes.
 * @return Pointer to the cloned office object.
 */
Building* Office::repairClone() const {
    std::cout << "Prototype: Cloning an Office building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing commercial building (Office): " << getName() << "\n";
    return new Office(*this);  // Return a new cloned instance of Office
}
