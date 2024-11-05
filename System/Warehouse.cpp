// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Warehouse.h"
#include <iostream>

/**
 * @brief Default Constructor for Warehouse.
 * Initializes the warehouse with specific default values.
 */
Warehouse::Warehouse()
    : IndustrialBuilding() {
    name = "Builder's Warehouse";
    maxCapacity = 100;
    width = 30;
    length = 50;
    electricityMeterBox = 100.0;  ///< Initial electricity meter reading.
    waterMeterBox = 50.0;         ///< Initial water meter reading.
    electricityUsage = 0.0;       ///< Initial electricity usage.
    waterUsage = 0.0;             ///< Initial water usage.
    wasteProduction = 0.0;        ///< Initial waste production.
    priceTag = 300000.0;          ///< Default price tag for a warehouse.
    type = "Warehouse";
}

/**
 * @brief Displays the stats specific to the warehouse.
 */
void Warehouse::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method.
}

/**
 * @brief Accepts a visitor for applying the Visitor pattern.
 * @param visitor A pointer to the TaxManager object.
 */
void Warehouse::accept(TaxManager* visitor) {
    std::cout << "No tax applied to warehouse: " << getName() 
              << ". Warehouses are non-taxable." << std::endl;
}

/**
 * @brief Clones the warehouse for repair purposes.
 * @return A pointer to the cloned Warehouse object.
 */
Building* Warehouse::repairClone() const {
    std::cout << "Prototype: Cloning a Warehouse building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing industrial building (Warehouse): " << getName() << "\n";
    return new Warehouse(*this);
}

double Warehouse::calculateTax() const
{
   return 0.0;
}
