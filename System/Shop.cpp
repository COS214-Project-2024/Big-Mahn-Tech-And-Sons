// Class implementation of Factory Method - COncreteProduct (subtype)

#include "Shop.h"
#include <iostream>

/**
 * @brief Constructor for Shop.
 * @param name Name of the shop.
 * @param maxCapacity Maximum capacity of the shop.
 */
Shop::Shop()
    : CommercialBuilding(name, maxCapacity), availableJobs(maxCapacity) {
    name = "Checkers";
    maxCapacity = 100;
    availableJobs = 
    width = 10;
    length = 15; 
    electricityMeterBox = 100.0;
    waterMeterBox = 200.0;
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 100000.0; // Setting price tag for Shop
    netWorth = 80000.0;
}

/**
 * @brief Displays the stats specific to the shop.
 */
void Shop::displayStats() const {
    CommercialBuilding::displayStats();  // Call base class method
    std::cout << "Available Jobs: " << availableJobs << std::endl;
}

/**
 * @brief Checks the availability of jobs in the shop.
 * @return True if jobs are available, otherwise false.
 */
bool Shop::checkAvailability() const {
    return availableJobs > 0;  // Jobs are available if any exist
}

/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Shop::accept(TaxManager* visitor) {
    visitor->visitCommercialBuilding(this);
}


Building* Shop::clone() const  {
    return new Shop(*this);  // Clone this School
}