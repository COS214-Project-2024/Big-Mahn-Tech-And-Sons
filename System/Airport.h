// Class definition of Factory Method -ConcreteProduct (subtype)

#ifndef AIRPORT_H
#define AIRPORT_H

#include "IndustrialBuilding.h"
#include "TaxManager.h"

/**
 * @class Airport
 * @brief Represents an airport, a type of industrial building.
 */
class Airport : public IndustrialBuilding {
private:
    int runwayCount;        ///< Number of runways in the airport.
    double passengerCapacity; ///< Maximum passenger capacity per day.
    double currentPassengers; ///< Current number of passengers being handled.

public:
    /**
     * @brief Constructor for Airport.
     * @param name Name of the airport.
     * @param maxCapacity Maximum capacity of people at the airport.
     * @param maxProductionCapacity Maximum production capacity of the airport.
     * @param runwayCount Number of runways.
     * @param passengerCapacity Maximum passenger capacity per day.
     */
    Airport(const std::string& name, int maxCapacity, int maxProductionCapacity, 
            int runwayCount, double passengerCapacity);

    /**
     * @brief Displays the stats specific to the airport.
     */
    void displayStats() const override;

    /**
     * @brief Checks if the airport can handle more passengers.
     * @return True if there is capacity for more passengers, otherwise false.
     */
    bool canHandleMorePassengers() const;

    bool checkProductionCapacity() const;

    /**
     * @brief Accepts visitors for the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;
};

#endif // AIRPORT_H
