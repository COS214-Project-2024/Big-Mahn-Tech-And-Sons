/**
 * @file Power.cpp
 * @brief Implementation of the Power class.
 */

#include "Power.h"

Power::Power(double amount) : amount(amount) {}

/**
 * @brief Gets the current amount of power.
 * @return double Current power amount.
 */
double Power::getPowerAmount() const
{
    return amount;
}

/**
 * @brief Deducts a specified amount from the available power.
 * @param used Amount to be deducted.
 */
void Power::usePower(double used)
{
    if (used <= amount)
    {
        amount -= used;
    }
    else
    {
        std::cout << "Insufficient power available to meet request." << std::endl;
    }
}
