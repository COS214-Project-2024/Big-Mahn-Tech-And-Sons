// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Factory.h"
#include <iostream>

/**
 * @brief Constructor for Factory.
 * @param name Name of the factory.
 * @param maxCapacity Maximum capacity of the factory.
 * @param maxProductionCapacity Maximum production capacity of the factory.
 * @param operationalHours Operational hours per day.
 */
Factory::Factory(const std::string& name, int maxCapacity, int maxProductionCapacity, double operationalHours)
    : IndustrialBuilding(name, maxCapacity, maxProductionCapacity),
      operationalHours(operationalHours) {
    
    width = 20;                  
    length = 40;                 
    electricityMeterBox = 150.0; 
    waterMeterBox = 250.0;       // Initial water meter reading
    electricityUsage = 0.0;      // Initial electricity usage
    waterUsage = 0.0;            // Initial water usage
    wasteProduction = 0.0;                 // Initial waste production
    priceTag = 500000.0;         // Default price tag for a factory
}

/**
 * @brief Displays the stats specific to the factory.
 */
void Factory::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method
    std::cout << "Operational Hours: " << operationalHours << " hours/day" << std::endl;
}

/**
 * @brief Checks if the factory has available production capacity.
 * @return True if there is available capacity, otherwise false.
 */
bool Factory::checkProductionCapacity() const {
    return productionRate < maxProductionCapacity;
}

Building *Factory::clone() const
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
