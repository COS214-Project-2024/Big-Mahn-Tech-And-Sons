// Class defintion of Factory Method - ConcreteProduct participant (classification)

/**
 * @file ResidentialBuilding.h
 * @brief Defines the ResidentialBuilding class, an abstract class for residential buildings.
 */

#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "Building.h"
#include "TaxManager.h"

/**
 * @class ResidentialBuilding
 * @brief Abstract base class for residential buildings.
 *
 * Represents the shared attributes and behaviors of residential buildings, 
 * including utility management and visitor acceptance. Derived classes 
 * implement specific types of residential buildings.
 */
class ResidentialBuilding : public Building {
    
    public:
        /**
         * @brief Default constructor for ResidentialBuilding.
         */
        ResidentialBuilding();

        /**
         * @brief Displays statistics specific to residential buildings.
         *
         * This function provides information about the building’s usage, 
         * capacity, and other residential-specific attributes.
         */
        void displayStats() const;

        /**
         * @brief Accepts a visitor to perform operations based on building type.
         *
         * Enables the visitor pattern, allowing different visitor operations
         * based on building type.
         * 
         * @param visitor A pointer to a TaxManager visitor.
         */
        virtual void accept(TaxManager* visitor) = 0;

        /**
         * @brief Creates a copy of the ResidentialBuilding instance.
         * 
         * Supports the Prototype pattern by returning a copy of the building 
         * with identical attributes.
         * 
         * @return A pointer to a cloned ResidentialBuilding instance.
         */
        virtual Building* repairClone() const = 0;

        /**
         * @brief Calculates the tax amount for the residential building.
         * 
         * The tax amount is calculated based on the number of occupants 
         * and the tax rate per occupant.
         * 
         * @return The calculated tax amount for the building.
         */
        double calculateTax() const override;


};

#endif // RESIDENTIALBUILDING_H
