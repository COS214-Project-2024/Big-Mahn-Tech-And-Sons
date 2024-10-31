/**
 * @file Power.cpp
 * @brief Implementation of the Power class.
 */

#include "Power.h"
#include <iostream>

Power::Power(std::string name, double amount) 
    : name(name), amount(amount) {}

/**
 * @brief Gets the current amount of power.
 * @return double Current power amount.
 */
double Power::getAmount() const {
    return amount;
}

/**
 * @brief Deducts a specified amount from the available power.
 * @param used Amount to be deducted.
 */
void Power::use(double used) {
    if (used <= amount) {
        amount -= used;
    } else {
        std::cout << "Insufficient power available to meet request." << std::endl;
    }
}

/**
 * @brief Reports the current status of the power resource.
 */
void Power::reportStatus() const {
    std::cout << "Power Resource: " << name << ", Available Amount: " << amount << std::endl;
}
