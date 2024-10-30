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
Warehouse::Warehouse(const std::string& name, int maxCapacity, int maxProductionCapacity, double storageCapacity)
    : IndustrialBuilding(name, maxCapacity, maxProductionCapacity),
      storageCapacity(storageCapacity), currentStorage(0.0) {

    width = 30;                  
    length = 50;                 
    electricityMeterBox = 100.0; ///< Initial electricity meter reading.
    waterMeterBox = 50.0;        ///< Initial water meter reading.
    electricityUsage = 0.0;      ///< Initial electricity usage.
    waterUsage = 0.0;            ///< Initial water usage.
    wasteProduction = 0.0;                 ///< Initial waste production.
    priceTag = 300000.0;         ///< Default price tag for a warehouse.
}

/**
 * @brief Displays the stats specific to the warehouse.
 */
void Warehouse::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method.
    std::cout << "Storage Capacity: " << storageCapacity << " tons" << std::endl;
    std::cout << "Current Storage: " << currentStorage << " tons" << std::endl;
}

/**
 * @brief Checks if there is available storage space in the warehouse.
 * @return True if space is available, otherwise false.
 */
bool Warehouse::hasStorageSpace() const {
    return currentStorage < storageCapacity;
}

bool Warehouse::checkProductionCapacity() const
{
    return false;
}

/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Warehouse::accept(TaxManager* visitor) { // Yohali Stub!!!!!!!
  //  visitor->visit(this);
}
