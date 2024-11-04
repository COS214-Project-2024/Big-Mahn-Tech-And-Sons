// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Factory.h"
#include <iostream>

/**
 * @brief Default Constructor for Factory.
 * Initializes the factory with default attributes.
 */
Factory::Factory()
    : IndustrialBuilding() {
    name = "Evergreen Supply Depot";
    maxCapacity = 1000;
    width = 20;
    length = 40;
    electricityMeterBox = 150.0;  // Initial electricity meter reading
    waterMeterBox = 250.0;        // Initial water meter reading
    electricityUsage = 0.0;       // Initial electricity usage
    waterUsage = 0.0;             // Initial water usage
    wasteProduction = 0.0;        // Initial waste production
    priceTag = 500000.0;          // Default price tag for a factory
    type = "Factory";
}

/**
 * @brief Displays the stats specific to the factory.
 */
void Factory::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method
}

/**
 * @brief Clones the factory for repair purposes.
 * @return A pointer to the cloned Factory object.
 */
Building* Factory::repairClone() const {
    std::cout << "Prototype: Cloning a Factory building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing industrial building (Factory): " << getName() << "\n";
    return new Factory(*this);
}

/**
 * @brief Accepts a visitor for the Visitor pattern.
 * This function is currently stubbed for factories, which are non-taxable.
 * @param visitor A pointer to the visitor object.
 */
void Factory::accept(TaxManager* visitor) {
    std::cout << "No tax applied to factory: " << getName() 
              << ". Factories are non-taxable." << std::endl;
}