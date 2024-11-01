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

public:
    /**
     * @brief Constructor for TrainStation.
     */
    TrainStation();

    /**
     * @brief Displays the stats specific to the train station.
     */
    void displayStats() const override;

    /**
     * @brief Accepts visitors for the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;
};

#endif // TRAINSTATION_H