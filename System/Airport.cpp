// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Airport.h"
#include <iostream>

/**
 * @brief Default Constructor for Airport.
 * Initializes the airport with specific default values.
 */
Airport::Airport()
    : IndustrialBuilding() {
    name = "OR Tambo International Airport";
    maxCapacity = 1000;
    width = 100;                   ///< Example width of the airport.
    length = 300;                  ///< Example length of the airport.
    electricityMeterBox = 1000.0;  ///< Initial electricity meter reading.
    waterMeterBox = 500.0;         ///< Initial water meter reading.
    electricityUsage = 0.0;        ///< Initial electricity usage.
    waterUsage = 0.0;              ///< Initial water usage.
    wasteProduction = 0.0;         ///< Initial waste production.
    priceTag = 1000000.0;          ///< Default price tag for an airport.
    type = "Airport";
}

/**
 * @brief Displays stats specific to the airport.
 */
void Airport::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method.
}

/**
 * @brief Accepts a visitor for applying the Visitor pattern.
 * @param visitor A pointer to the TaxManager object.
 * Displays that airports are non-taxable.
 */
void Airport::accept(TaxManager* visitor) {
    std::cout << "No tax applied to airport: " << getName() 
              << ". Airports are non-taxable." << std::endl;
}

/**
 * @brief Clones the airport for repair purposes.
 * @return A pointer to the cloned Airport object.
 */
Building* Airport::repairClone() const {
    std::cout << "Prototype: Cloning an Airport building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing industrial building (Airport): " << getName() << "\n";
    return new Airport(*this);
}