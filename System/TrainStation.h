// Class definition of Factory Method -ConcreteProduct (subtype)

#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "IndustrialBuilding.h"
#include "TaxManager.h"

/**
 * @class TrainStation
 * @brief Represents a train station, a type of industrial building.
 */
class TrainStation : public IndustrialBuilding {
private:
    int platformCount;      ///< Number of platforms at the station.
    double dailyPassengerCapacity; ///< Maximum number of passengers the station can handle per day.
    double currentPassengers; ///< Current number of passengers being handled.

public:
    /**
     * @brief Constructor for TrainStation.
     * @param name Name of the train station.
     * @param maxCapacity Maximum capacity of people at the station.
     * @param maxProductionCapacity Maximum production capacity of the station.
     * @param platformCount Number of platforms.
     * @param dailyPassengerCapacity Maximum passenger capacity per day.
     */
    TrainStation(const std::string& name, int maxCapacity, int maxProductionCapacity,
                 int platformCount, double dailyPassengerCapacity);

    /**
     * @brief Displays the stats specific to the train station.
     */
    void displayStats() const override;

    /**
     * @brief Checks if the station can handle more passengers.
     * @return True if there is capacity for more passengers, otherwise false.
     */
    bool canHandleMorePassengers() const;

    /**
     * @brief Accepts visitors for the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;

    bool checkProductionCapacity() const;
};

#endif // TRAINSTATION_H
