// Class defintion of Factory Method - ConcreteProduct (classification)

/**
 * @file IndustrialBuilding.h
 * @brief Defines the IndustrialBuilding class, an abstract class for industrial buildings.
 */

#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include "Building.h"

/**...............................................................................................................................................................................................................................................
 * @class IndustrialBuilding
 * @brief Abstract base class for industrial buildings.
 *
 * Represents the shared attributes and behaviors of industrial buildings,
 * such as production capacity. Derived classes implement specific types
 * of industrial buildings.
 */
class IndustrialBuilding : public Building
{

public:
    /**
     * @brief Default constructor for IndustrialBuilding.
     */
    IndustrialBuilding();

    /**
     * @brief Displays statistics specific to industrial buildings.
     *
     * Provides information about the building’s usage, capacity, and
     * other industrial-specific attributes.
     */
    void displayStats() const override;

    /**
     * @brief Accepts a visitor to perform operations based on building type.
     *
     * Enables the visitor pattern, allowing different visitor operations
     * based on building type.
     *
     * @param visitor A pointer to a TaxManager visitor.
     */
    virtual void accept(TaxManager *visitor) override;

    /**
     * @brief Creates a copy of the IndustrialBuilding instance.
     *
     * Supports the Prototype pattern by returning a copy of the building
     * with identical attributes.
     *
     * @return A pointer to a cloned IndustrialBuilding instance.
     */
    virtual Building *repairClone() const override;

    /**
     * @brief Calculates tax for a landmark.
     * Landmarks are exempt from tax, so this function returns 0.0.
     *
     * @return Tax amount (always 0.0 for landmarks).
     */
    virtual double calculateTax() const override;
};

#endif // INDUSTRIALBUILDING_H
