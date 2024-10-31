/**
 * @file Water.h
 * @brief Declaration of the Water class.
 */

#ifndef WATER_H
#define WATER_H

#include "Resource.h"

/**
 * @class Water
 * @brief Represents water resource in the simulation.
 */
class Water {
    private:

        std::string name;
        double amount;

    public:

        Water(){}
        
        Water(std::string  name, double amount);
        /**
         * @brief Gets the current amount of water.
         * @return double Current water amount.
         */
        double getAmount() const;

        /**
         * @brief Deducts a specified amount from the available water.
         * @param used Amount to be deducted.
         */
        void use(double used);

    //have a function that produces more water fpr a specific building 
};

#endif // WATER_H