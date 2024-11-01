// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Factory.h"
#include <iostream>

/**
 * @brief Constructor for Factory.
 */
Factory::Factory()
    : IndustrialBuilding() {
    name = "BMW Car Factory";
    maxCapacity = 1000;
    width = 20;                  
    length = 40;                 
    electricityMeterBox = 150.0; 
    waterMeterBox = 250.0;       // Initial water meter reading
    electricityUsage = 0.0;      // Initial electricity usage
    waterUsage = 0.0;            // Initial water usage
    wasteProduction = 0.0;                 // Initial waste production
    priceTag = 500000.0;         // Default price tag for a factory
    type = "Factory";
}

/**
 * @brief Displays the stats specific to the factory.
 */
void Factory::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method
}



Building *Factory::repairClone() const
{
   return new Factory(*this);
}

/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Factory::accept(TaxManager* visitor) { // Yohali Stub!!!!!!!
    //visitor->visit(this);
}