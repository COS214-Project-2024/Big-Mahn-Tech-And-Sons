// Class implementation of Factory Method - ConcreteProduct participant (subtype)

#include "Shop.h"
#include "TaxManager.h"
#include <iostream>


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


void Shop::displayStats() const {
    CommercialBuilding::displayStats();  // Call base class method
    std::cout << "Available Jobs: " << availableJobs << std::endl;
}


bool Shop::checkAvailability() const {
    return availableJobs > 0;  // Jobs are available if any exist
}


void Shop::accept(TaxManager* visitor) {
    visitor->visitBuildingForBuilding(this);
    visitor->visitBuildingForCitizen(this);
}


Building* Shop::repairClone() const {
    std::cout << "Prototype: Cloning a Shop building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing commercial building (Shop): " << getName() << "\n";
    return new Shop(*this);  // Return a new cloned instance of Shop
}