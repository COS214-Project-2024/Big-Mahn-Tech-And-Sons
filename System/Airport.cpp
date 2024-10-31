// Class implementation of Factory Method -ConcreteProduct (subtype)

#include "Airport.h"
#include <iostream>

/**
 * @brief Constructor for Airport.
 * @param name Name of the airport.
 * @param maxCapacity Maximum capacity of people at the airport.
 * @param maxProductionCapacity Maximum production capacity of the airport.
 * @param runwayCount Number of runways.
 * @param passengerCapacity Maximum passenger capacity per day.
 */
Airport::Airport()
    : IndustrialBuilding(){
    name = "OR Tambo Airport";
    maxCapacity = 1000;
    width = 100;                 ///< Example width of the airport.
    length = 300;                ///< Example length of the airport.
    electricityMeterBox = 1000.0; ///< Initial electricity meter reading.
    waterMeterBox = 500.0;       ///< Initial water meter reading.
    electricityUsage = 0.0;      ///< Initial electricity usage.
    waterUsage = 0.0;            ///< Initial water usage.
    wasteProduction = 0.0;                 ///< Initial waste production.
    priceTag = 1000000.0;        ///< Default price tag for an airport.
    type = "Airport";
}

/**
 * @brief Displays the stats specific to the airport.
 */
void Airport::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method.
}


/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Airport::accept(TaxManager* visitor) { // Yohali Stub!!!!!!!
    // visitor->visitCommercialBuilding(this);
}
