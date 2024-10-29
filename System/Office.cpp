// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Office.h"
#include <iostream>

/**
 * @brief Constructor for Office.
 * @param name Name of the office.
 * @param maxCapacity Maximum capacity of the office.
 */
Office::Office(const std::string& name, int maxCapacity)
    : CommercialBuilding(name, maxCapacity), availableJobs(maxCapacity) {
    width = 12;
    length = 20; 
    electricityMeterBox = 150.0;
    waterMeterBox = 250.0;     
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 200000.0; // Setting price tag for Office
    netWorth = 500000.0;
}

/**
 * @brief Displays the stats specific to the office.
 */
void Office::displayStats() const {
    CommercialBuilding::displayStats();  // Call base class method
    std::cout << "Available Jobs: " << availableJobs << std::endl;
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
void Office::accept(TaxManager* visitor) { // Yohali stub
   // visitor->visit(this);
}
