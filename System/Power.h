/**
 * @file Power.h
 * @brief Declaration of the Power class.
 */

#ifndef POWER_H
#define POWER_H

#include "Resource.h"

/**
 * @class Power
 * @brief Represents power resource in the simulation.
 */
class Power{

private:
    std::string name; ///< The name of the resource.
    double amount; ///< The amount of the resource available.

public:

    Power() {}

    Power(std::string& name, double amount); ///< Constructor.

    /**
     * @brief Gets the current amount of power.
     * @return double Current power amount.
     */
    double getAmount() const;

    /**
     * @brief Deducts a specified amount from the available power.
     * @param used Amount to be deducted.
     */
    void use(double used);

    /**
     * @brief Reports the current status of the power resource.
     */
    void reportStatus() const;
};

#endif // POWER_H
