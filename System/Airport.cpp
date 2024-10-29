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
Airport::Airport(const std::string& name, int maxCapacity, int maxProductionCapacity, 
                 int runwayCount, double passengerCapacity)
    : IndustrialBuilding(name, maxCapacity, maxProductionCapacity),
      runwayCount(runwayCount), passengerCapacity(passengerCapacity), currentPassengers(0.0) {

    width = 100;                 ///< Example width of the airport.
    length = 300;                ///< Example length of the airport.
    electricityMeterBox = 1000.0; ///< Initial electricity meter reading.
    waterMeterBox = 500.0;       ///< Initial water meter reading.
    electricityUsage = 0.0;      ///< Initial electricity usage.
    waterUsage = 0.0;            ///< Initial water usage.
    waste = 0.0;                 ///< Initial waste production.
    priceTag = 1000000.0;        ///< Default price tag for an airport.
}

/**
 * @brief Displays the stats specific to the airport.
 */
void Airport::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method.
    std::cout << "Runway Count: " << runwayCount << std::endl;
    std::cout << "Passenger Capacity: " << passengerCapacity << " per day" << std::endl;
    std::cout << "Current Passengers: " << currentPassengers << std::endl;
}

/**
 * @brief Checks if the airport can handle more passengers.
 * @return True if there is capacity for more passengers, otherwise false.
 */
bool Airport::canHandleMorePassengers() const {
    return currentPassengers < passengerCapacity;
}

/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Airport::accept(TaxManager* visitor) {
    visitor->visit(this);
}
