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
protected:
    int maxProductionCapacity; ///< Maximum production capacity of the building.
    double productionRate;     ///< Current production rate of the building.

public:
    /**
     * @brief Constructor for IndustrialBuilding.
     * @param name Name of the building.
     * @param maxCapacity Maximum capacity of the building.
     * @param maxProductionCapacity Maximum production capacity of the building.
     */
    IndustrialBuilding(const std::string& name, int maxCapacity, int maxProductionCapacity)
        : Building(name, maxCapacity), 
          maxProductionCapacity(maxProductionCapacity), 
          productionRate(0.0) {}

    /**
     * @brief Displays the stats specific to industrial buildings.
     */
    void displayStats() const {
        Building::displayStats();  // Call base class method
        std::cout << "Max Production Capacity: " << maxProductionCapacity << std::endl;
        std::cout << "Current Production Rate: " << productionRate << std::endl;
    }

    /**
     * @brief Checks if the building can accommodate additional production.
     * @return True if production capacity is available, otherwise false.
     */
    virtual bool checkProductionCapacity() const = 0;

    virtual std::shared_ptr<Building> clone() const override {

    };

    /**
     * @brief Accepts visitors for the visitor pattern.
     * This method remains virtual, to be overridden in the final building types.
     * @param visitor A pointer to the visitor object.
     */
    virtual void accept(TaxManager* visitor) {
       // visitor->visit(this);
    };

     virtual void repair() override {

     };

    // Getter and Setter for production rate
    double getProductionRate() const { return productionRate; }
    void setProductionRate(double rate) { productionRate = rate; }
};

#endif // INDUSTRIALBUILDING_H