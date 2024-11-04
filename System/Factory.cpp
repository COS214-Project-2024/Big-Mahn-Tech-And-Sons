// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Factory.h"
#include <iostream>

Factory::Factory()
    : IndustrialBuilding()
{
    name = "Evergreen Supply Depot";
    maxCapacity = 1000;
    width = 20;
    length = 40;
    electricityMeterBox = 150.0; // Initial electricity meter reading
    waterMeterBox = 250.0;       // Initial water meter reading
    electricityUsage = 0.0;      // Initial electricity usage
    waterUsage = 0.0;            // Initial water usage
    wasteProduction = 0.0;       // Initial waste production
    priceTag = 500000.0;         // Default price tag for a factory
    type = "Factory";
}

void Factory::displayStats() const
{
    IndustrialBuilding::displayStats(); // Call base class method
}

Building *Factory::repairClone() const
{
    std::cout << "Prototype: Cloning a Factory building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing industrial building (Factory): " << getName() << "\n";
    return new Factory(*this);
}

void Factory::accept(TaxManager *visitor)
{
    std::cout << "No tax applied to factory: " << getName()
              << ". Factories are non-taxable." << std::endl;
}

double Factory::calculateTax() const
{
    return 0.0;
}
