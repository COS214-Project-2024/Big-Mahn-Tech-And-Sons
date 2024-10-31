// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Warehouse.h"
#include <iostream>

/**
 * @brief Constructor for Warehouse.
 * @param name Name of the warehouse.
 * @param maxCapacity Maximum capacity of people the warehouse can accommodate.
 * @param maxProductionCapacity Maximum production capacity of the warehouse.
 * @param storageCapacity Total storage capacity in tons.
 */
Warehouse::Warehouse()
    : IndustrialBuilding() {
        name = "Builder's Warehouse";
        maxCapacity = 100;
    width = 30;                  
    length = 50;                 
    electricityMeterBox = 100.0; ///< Initial electricity meter reading.
    waterMeterBox = 50.0;        ///< Initial water meter reading.
    electricityUsage = 0.0;      ///< Initial electricity usage.
    waterUsage = 0.0;            ///< Initial water usage.
    wasteProduction = 0.0;                 ///< Initial waste production.
    priceTag = 300000.0;         ///< Default price tag for a warehouse.
    type = "WareHouse";
}

/**
 * @brief Displays the stats specific to the warehouse.
 */
void Warehouse::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method.

}

/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Warehouse::accept(TaxManager* visitor) { // Yohali Stub!!!!!!!
  //  visitor->visit(this);
}
