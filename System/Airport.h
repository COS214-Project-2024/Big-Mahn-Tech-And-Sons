// Class definition of Factory Method - ConcreteProduct (subtype)

#ifndef AIRPORT_H
#define AIRPORT_H

#include "IndustrialBuilding.h"
#include "TaxManager.h"

/**
 * @class Airport
 * @brief Represents an airport, a subtype of IndustrialBuilding.
 */
class Airport : public IndustrialBuilding {

    public:
        /**
         * @brief Default Constructor for Airport.
         */
        Airport();

        /**
         * @brief Displays stats specific to the airport.
         */
        void displayStats() const override;

        /**
         * @brief Accepts visitors for the visitor pattern.
         * @param visitor A pointer to the visitor object.
         */
        void accept(TaxManager* visitor) override;

        /**
         * @brief Creates a clone of the airport for repair purposes.
         * @return A pointer to the cloned Airport object.
         */
        Building* repairClone() const override;
};

#endif // AIRPORT_H