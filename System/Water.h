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
class Water : public Resource {
    private:

        string name;
        double amount;

    public:

        Water(){}
        
        Water(string  name, double amount);
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

    /**
     * @brief Reports the current status of the water resource.
     */
    void reportStatus() const override;

    //have a function that produces more water fpr a specific building 
};

#endif // WATER_H
