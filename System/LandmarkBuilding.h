// Class definition of Factory Method - ConcreteProduct participant (classification)

/**
 * @file LandmarkBuilding.h
 * @brief Declaration of the LandmarkBuilding class representing landmark buildings.
 */

#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H

#include "Building.h"
#include "TaxManager.h"
#include <iostream>
#include <string>

/**
 * @class LandmarkBuilding
 * @brief Abstract base class representing landmark buildings.
 *
 * Landmark buildings are symbolic or special-purpose structures with 
 * cultural, historical, or architectural significance.
 */
class LandmarkBuilding : public Building {

    public:
        /**
         * @brief Constructor for LandmarkBuilding.
         */
        LandmarkBuilding();

        /**
         * @brief Displays the stats specific to a landmark building.
         */
        void displayStats() const;

        /**
         * @brief Abstract method to accept a visitor for the visitor pattern.
         * @param visitor A pointer to the visitor object.
         */
        virtual void accept(TaxManager* visitor) = 0;

        /**
         * @brief Abstract method to create a clone of the landmark building for repair purposes.
         * @return Building* A pointer to the cloned building.
         */
        virtual Building* repairClone() const = 0;

        /**
         * @brief Calculates tax for a landmark.
         * Landmarks are exempt from tax, so this function returns 0.0.
         * 
         * @return Tax amount (always 0.0 for landmarks).
         */
        double calculateTax() const override;
};

#endif // LANDMARKBUILDING_H
