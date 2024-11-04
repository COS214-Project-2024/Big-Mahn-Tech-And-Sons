#include "School.h"
#include <iostream>
#include "TaxManager.h"


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


void School::displayStats() const {
    CommercialBuilding::displayStats();  // Call base class method
    std::cout << "Available Kids' Spaces: " << availableKidsSpaces << std::endl;
}


bool School::checkAvailability() const {
    return availableKidsSpaces > 0;  // Kids' spaces are available if any exist
}


void School::accept(TaxManager* visitor) {
     visitor->visitBuildingForBuilding(this);
    visitor->visitBuildingForCitizen(this);
}


Building* School::repairClone() const {
    std::cout << "Prototype: Cloning a School building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing commercial building (School): " << getName() << "\n";
    return new School(*this);  // Return a new cloned instance of School
}