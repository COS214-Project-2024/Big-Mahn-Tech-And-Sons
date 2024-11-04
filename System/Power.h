/**
 * @file Power.h
 * @brief Declaration of the Power class.
 */

#ifndef POWER_H
#define POWER_H
#include <iostream>
using namespace std;
#include "Resource.h"

/**
 * @class Power
 * @brief Represents power resource in  the simulation.
 */
class Power{

private:
    double amount; ///< The amount of the resource available.

public:

    Power(double amount); ///< Constructor.

    /**
     * @brief Gets the current amount of power.
     * @return double Current power amount.
     */
    double getPowerAmount() const;

    /**
     * @brief Deducts a specified amount from the available power.
     * @param used Amount to be deducted.
     */
    void usePower(double used);
};

#endif // POWER_H
