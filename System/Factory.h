// Class defintion of Factory Method - ConcreteProduct (classification)

#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuilding.h"
#include "TaxManager.h"
#include <string>

/**
 * @class Factory
 * @brief Represents a factory, a type of industrial building.
 */
class Factory : public IndustrialBuilding {
private:
    double operationalHours; ///< Operational hours per day.

public:
    /**
     * @brief Constructor for Factory.
     * @param name Name of the factory.
     * @param maxCapacity Maximum capacity of the factory.
     * @param maxProductionCapacity Maximum production capacity.
     * @param operationalHours Operational hours per day.
     */
    Factory(const std::string& name, int maxCapacity, int maxProductionCapacity, double operationalHours);

    /**
     * @brief Displays the stats specific to the factory.
     */
    void displayStats() const override;

    /**
     * @brief Checks if the factory has available production capacity.
     * @return True if there is available capacity, otherwise false.
     */
    bool checkProductionCapacity() const;

    /**
     * @brief Accepts visitors for the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;
};

#endif // FACTORY_H
