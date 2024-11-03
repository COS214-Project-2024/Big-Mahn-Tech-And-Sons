// Class defintion and implementation of Factory Method - ConcreteProduct (classification)

/**
 * @file IndustrialBuilding.h
 * @brief Declaration and implementation of the IndustrialBuilding class.
 */

#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include "Building.h"
#include "TaxManager.h"
#include <iostream>

/**
 * @class IndustrialBuilding
 * @brief Abstract class representing industrial buildings.
 *
 * This class provides shared attributes and operations for all industrial buildings,
 * such as production capacity, while leaving implementation details to the subtypes.
 */
class IndustrialBuilding : public Building {

public:
    /**
     * @brief Constructor for IndustrialBuilding.
     */
    IndustrialBuilding()
        : Building() {}

    /**
     * @brief Displays the stats specific to industrial buildings.
     */
    void displayStats() const {
        Building::displayStats();  // Call base class method
    }

    virtual Building* repairClone() const override {

    };

    /**
     * @brief Accepts visitors for the visitor pattern.
     * This method remains virtual, to be overridden in the final building types.
     * @param visitor A pointer to the visitor object.
     */
    virtual void accept(TaxManager* visitor) {
       // visitor->visit(this);
    };
};

#endif // INDUSTRIALBUILDING_H