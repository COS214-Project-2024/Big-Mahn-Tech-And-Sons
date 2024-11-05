// Class definition of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file Shop.h
 * @brief Declaration of the Shop class.
 */

#ifndef SHOP_H
#define SHOP_H

#include "CommercialBuilding.h"

/**
 * @class Shop
 * @brief Class representing a shop as a subtype of CommercialBuilding.
 *
 * Implements specific attributes and operations for a shop,
 * such as managing available jobs.
 */
class Shop : public CommercialBuilding {
    
    public:
        /**
         * @brief Default constructor for Shop.
         */
        Shop();

        /**
         * @brief Displays the stats specific to the shop.
         */
        void displayStats() const override;

        /**
         * @brief Checks the availability of jobs in the shop.
         * @return True if jobs are available, otherwise false.
         */
        bool checkAvailability() const override;

        /**
         * @brief Accepts visitors for the visitor pattern.
         * @param visitor A pointer to the visitor object.
         */
        void accept(TaxManager* visitor) override;

        /**
         * @brief Clones the shop for repair purposes.
         * @return Pointer to the cloned shop object.
         */
        Building* repairClone() const override;
};

#endif // SHOP_H
