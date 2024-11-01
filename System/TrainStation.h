// Class definition of Factory Method - ConcreteProduct (subtype)

#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "IndustrialBuilding.h"
#include "TaxManager.h"

/**
 * @class TrainStation
 * @brief Represents a train station, a subtype of IndustrialBuilding.
 */
class TrainStation : public IndustrialBuilding {

    public:
        /**
         * @brief Default Constructor for TrainStation.
         */
        TrainStation();

        /**
         * @brief Displays stats specific to the train station.
         */
        void displayStats() const override;

        /**
         * @brief Accepts visitors for the visitor pattern.
         * @param visitor A pointer to the visitor object.
         */
        void accept(TaxManager* visitor) override;

        /**
         * @brief Creates a clone of the train station for repair purposes.
         * @return A pointer to the cloned TrainStation object.
         */
        Building* repairClone() const override;
};

#endif // TRAINSTATION_H
