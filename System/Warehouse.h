// Class defintion of Factory Method - ConcreteProduct (subtype)

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "IndustrialBuilding.h"
#include "TaxManager.h"

/**
 * @class Warehouse
 * @brief Represents a warehouse, a type of industrial building.
 */
class Warehouse : public IndustrialBuilding {

public:
    /**
     * @brief Constructor for Warehouse.
     */
    Warehouse();

    /**
     * @brief Displays the stats specific to the warehouse.
     */
    void displayStats() const override;

    /**
     * @brief Accepts visitors for the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;

};

#endif // WAREHOUSE_H