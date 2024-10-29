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
private:
    double storageCapacity; ///< Maximum storage capacity in tons.
    double currentStorage;  ///< Current storage level in tons.

public:
    /**
     * @brief Constructor for Warehouse.
     * @param name Name of the warehouse.
     * @param maxCapacity Maximum capacity of people the warehouse can accommodate.
     * @param maxProductionCapacity Maximum production capacity of the warehouse.
     * @param storageCapacity Total storage capacity in tons.
     */
    Warehouse(const std::string& name, int maxCapacity, int maxProductionCapacity, double storageCapacity);

    /**
     * @brief Displays the stats specific to the warehouse.
     */
    void displayStats() const override;

    /**
     * @brief Checks if there is available storage space in the warehouse.
     * @return True if space is available, otherwise false.
     */
    bool hasStorageSpace() const;

    /**
     * @brief Accepts visitors for the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;
};

#endif // WAREHOUSE_H
