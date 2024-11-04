// Class implementation of Factory Method - ConcreteProduct participant (subtype)

#include "Estate.h"
#include <iostream>


Estate::Estate()
    : ResidentialBuilding() {
    name = "Luxury Estate";
    maxCapacity = 10;
    width = 40;
    length = 60;
    electricityMeterBox = 300.0;
    waterMeterBox = 800.0;
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 500000.0;
    type = "Estate";
}


void Estate::displayStats() const {
    ResidentialBuilding::displayStats();  // Display general stats for residential buildings
}


void Estate::accept(TaxManager* visitor) {
   // visitor->visitResidentialBuilding(this);
}


Building* Estate::repairClone() const {
    std::cout << "Prototype: Cloning an Estate building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing residential building (Estate): " << getName() << "\n";
    return new Estate(*this);
}