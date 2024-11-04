// Class implementation of Factory Method - ConcreteProduct participant (subtype)

#include "House.h"
#include <iostream>


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


void House::displayStats() const {
    ResidentialBuilding::displayStats();  // Display general stats for residential buildings
}


void House::accept(TaxManager* visitor) {
    visitor->visitResidentialBuilding(this);
}


Building* House::repairClone() const {
    std::cout << "Prototype: Cloning a Shop building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing residential building (House): " << getName() << "\n";
    return new House(*this);
}