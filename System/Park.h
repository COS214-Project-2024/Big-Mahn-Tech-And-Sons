// Class defintion of Factory Method - ConcreteProduct (subtype)

#ifndef PARK_H
#define PARK_H

#include "LandmarkBuilding.h"
#include "TaxManager.h"
#include <string>

/**
 * @class Park
 * @brief Concrete class representing a public park.
 *
 * Parks are natural spaces designed for recreation and leisure,
 * often containing gardens, playgrounds, or walking paths.
 */
class Park : public LandmarkBuilding {

    public:
        /**
         * @brief Default constructor for Park.
         */
        Park();

        /**
         * @brief Displays the statistics specific to the park.
         */
        void displayStats() const override;

        /**
         * @brief Accepts a visitor for tax calculation using the visitor pattern.
         * @param visitor A pointer to the visitor (TaxManager).
         */
        void accept(TaxManager* visitor) override;

        /**
         * @brief Creates a clone of the park object for repair purposes.
         * @return A pointer to the cloned Park object.
         */
        Building* repairClone() const override;
};

#endif // PARK_H
