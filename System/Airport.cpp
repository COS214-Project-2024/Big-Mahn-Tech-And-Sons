// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Airport.h"
#include <iostream>

Airport::Airport()
    : IndustrialBuilding()
{
    name = "OR Tambo International Airport";
    maxCapacity = 1000;
    width = 100;                  ///< Example width of the airport.
    length = 300;                 ///< Example length of the airport.
    electricityMeterBox = 1000.0; ///< Initial electricity meter reading.
    waterMeterBox = 500.0;        ///< Initial water meter reading.
    electricityUsage = 0.0;       ///< Initial electricity usage.
    waterUsage = 0.0;             ///< Initial water usage.
    wasteProduction = 0.0;        ///< Initial waste production.
    priceTag = 1000000.0;         ///< Default price tag for an airport.
    type = "Airport";
}

void Airport::displayStats() const
{
    IndustrialBuilding::displayStats(); // Call base class method.
}

void Airport::accept(TaxManager *visitor)
{
    std::cout << "No tax applied to airport: " << getName()
              << ". Airports are non-taxable." << std::endl;
}

Building *Airport::repairClone() const
{
    std::cout << "Prototype: Cloning an Airport building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing industrial building (Airport): " << getName() << "\n";
    return new Airport(*this);
}

double Airport::calculateTax() const
{
    return 0.0;
}
