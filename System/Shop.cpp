// Class implementation of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file Shop.cpp
 * @brief Implements the Shop class.
 */

#include "Shop.h"
#include <iostream>

/**
 * @brief Default constructor for Shop.
 */
Shop::Shop()
    : CommercialBuilding() {
    name = "SuperMart";        // Default name for the shop
    maxCapacity = 50;          // Set max capacity for shop
    availableJobs = maxCapacity;  // Initialize available jobs to max capacity
    width = 10;                // Default width for shops
    length = 15;               // Default length for shops
    electricityMeterBox = 100.0;
    waterMeterBox = 200.0;
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 100000.0;       // Default price tag for Shop
    netWorth = 80000.0;
    type = "Shop";
    annualRevenue = 50000.0;   // Default annual revenue for Shop
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

/**
 * @brief Clones the shop for repair purposes.
 * @return Pointer to the cloned shop object.
 */
Building* Shop::repairClone() const {
    std::cout << "Prototype: Cloning a Shop building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing commercial building (Shop): " << getName() << "\n";
    return new Shop(*this);  // Return a new cloned instance of Shop
}
