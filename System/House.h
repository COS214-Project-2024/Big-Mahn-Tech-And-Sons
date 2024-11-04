// Class defintion of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file House.h
 * @brief Declaration of the House class, a concrete residential building type.
 */

#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"
#include "TaxManager.h"
/**
 * @class House
 * @brief Represents a residential house with specific attributes and behavior.
 */
class House : public ResidentialBuilding {
    
    public:
        /**
         * @brief Default constructor for House, initializing unique house attributes.
         */
        House();

        /**
         * @brief Displays the statistics of the house, including specific and inherited details.
         */
        void displayStats() const override;

        /**
         * @brief Accepts a visitor for the visitor pattern, allowing specific actions for tax management.
         * @param visitor A pointer to the TaxManager visitor.
         */
        void accept(TaxManager* visitor) override;

        /**
         * @brief Creates a clone of the house for repair actions.
         * @return Building* A pointer to the cloned house instance.
         */
        Building* repairClone() const override;
};

#endif // HOUSE_H
