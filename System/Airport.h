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

public:
    /**
     * @brief Constructor for Airport.
     */
    Airport();

    /**
     * @brief Displays the stats specific to the airport.
     */
    void displayStats() const override;


    /**
     * @brief Accepts visitors for the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;

};

#endif // AIRPORT_H
