// Class definition of Factory Method - ConcreteProduct (subtype)

#ifndef MUSEUM_H
#define MUSEUM_H

#include "LandmarkBuilding.h"
#include "TaxManager.h"
#include <string>

/**
 * @brief The Museum class, a specific type of LandmarkBuilding.
 */
class Museum : public LandmarkBuilding {

    public:
        /**
         * @brief Constructor for Museum.
         */
        Museum();

        /**
         * @brief Displays the stats specific to the museum.
         */
        void displayStats() const override;

        /**
         * @brief Accepts visitors using the visitor pattern.
         * @param visitor A pointer to the visitor object.
         */
        void accept(TaxManager* visitor) override;

        /**
         * @brief Clones the museum object for repair purposes.
         * @return A pointer to the cloned Museum object.
         */
        Building* repairClone() const override;
};

#endif // MUSEUM_H
