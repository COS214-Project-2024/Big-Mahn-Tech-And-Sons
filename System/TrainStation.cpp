// Class implementation of Factory Method -ConcreteProduct (subtype)

#include "TrainStation.h"
#include <iostream>

/**
 * @brief Constructor for TrainStation.
 * @param name Name of the train station.
 * @param maxCapacity Maximum capacity of people at the station.
 * @param maxProductionCapacity Maximum production capacity of the station.
 * @param platformCount Number of platforms.
 * @param dailyPassengerCapacity Maximum passenger capacity per day.
 */
TrainStation::TrainStation(const std::string& name, int maxCapacity, int maxProductionCapacity,
                           int platformCount, double dailyPassengerCapacity)
    : IndustrialBuilding(name, maxCapacity, maxProductionCapacity),
      platformCount(platformCount), dailyPassengerCapacity(dailyPassengerCapacity),
      currentPassengers(0.0) {

    width = 50;                  ///< Example width of the station.
    length = 150;                ///< Example length of the station.
    electricityMeterBox = 500.0; ///< Initial electricity meter reading.
    waterMeterBox = 300.0;       ///< Initial water meter reading.
    electricityUsage = 0.0;      ///< Initial electricity usage.
    waterUsage = 0.0;            ///< Initial water usage.
    wasteProduction = 0.0;                 ///< Initial waste production.
    priceTag = 750000.0;         ///< Default price tag for a train station.
}

/**
 * @brief Displays the stats specific to the train station.
 */
void TrainStation::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method.
    std::cout << "Platform Count: " << platformCount << std::endl;
    std::cout << "Daily Passenger Capacity: " << dailyPassengerCapacity << " per day" << std::endl;
    std::cout << "Current Passengers: " << currentPassengers << std::endl;
}

/**
 * @brief Checks if the station can handle more passengers.
 * @return True if there is capacity for more passengers, otherwise false.
 */
bool TrainStation::canHandleMorePassengers() const {
    return currentPassengers < dailyPassengerCapacity;
}

/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void TrainStation::accept(TaxManager* visitor) { // Yohali Stub!!!!!!!
    //visitor->visit(this);
}

bool TrainStation::checkProductionCapacity() const
{
   return false;
}
