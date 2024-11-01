// Class defintion and implementation of Factory Method - ConcreteProduct (classification)

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
    LandmarkBuilding()
        : Building() {
        width = 10;    // Default width for landmarks
        length = 15;   // Default length for landmarks
        priceTag = 1000000.0;  // Default price tag for a landmark
    }

    /**
     * @brief Virtual destructor for LandmarkBuilding.
     */
    // virtual ~LandmarkBuilding() = default;

    /**
     * @brief Displays the stats specific to a landmark building.
     */
    void displayStats() const override {
        Building::displayStats();  // Call the base class method
    }


    /**
     * @brief Abstract method to accept a visitor for the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    virtual void accept(TaxManager* visitor) = 0;

    virtual Building* repairClone() const override {

    }
};

#endif // LANDMARKBUILDING_H