// Class implementation of Factory Method - ConcreteProduct participant (subtype)

#include "Apartment.h"
#include <iostream>


Apartment::Apartment()
    : ResidentialBuilding() {
    name = "Urban Apartment";
    maxCapacity = 50;
    width = 30;
    length = 50;
    electricityMeterBox = 200.0;
    waterMeterBox = 500.0;
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 150000.0;
    type = "Apartment";
}


void Apartment::displayStats() const {
    ResidentialBuilding::displayStats();  // Display general stats for residential buildings
}


void Apartment::accept(TaxManager* visitor) {
    visitor->visitBuildingForBuilding(this);
    visitor->visitBuildingForCitizen(this);
}


Building* Apartment::repairClone() const {
    std::cout << "Prototype: Cloning an Apartment building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing residential building (Apartment): " << getName() << "\n";
    return new Apartment(*this);
}