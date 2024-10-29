/**
 * @file Electricity.h
 * @brief Declaration of the Electricity class.
 */

#ifndef ELECTRICITY_H
#define ELECTRICITY_H

#include "Resource.h"

/**
 * @class Electricity
 * @brief Represents electricity resource in the simulation.
 */
class Electricity : public Resource {

private:
    std::string name; ///< The name of the resource.
    double amount; ///< The amount of the resource available.


public:

    Electricity(){}

    Electricity(std::string& name,  double amount); ///< Constructor.

    /**
     * @brief Gets the current amount of electricity.
     * @return double Current electricity amount.
     */
    double getAmount() const;

    /**
     * @brief Deducts a specified amount from the available electricity.
     * @param used Amount to be deducted.
     */
    void use(double used);

    /**
     * @brief Reports the current status of the electricity resource.
     */
    void reportStatus() const override;
};

#endif // ELECTRICITY_H
