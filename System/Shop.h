// Class defintion of Factory Method - COncreteProduct (subtype)

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
 * This class implements the specific attributes and operations for a shop,
 * such as managing available jobs.
 */
class Shop : public CommercialBuilding {
public:
    /**
     * @brief Constructor for Shop.
     * @param name Name of the shop.
     * @param maxCapacity Maximum capacity of the shop.
     */
    Shop(const std::string& name, int maxCapacity);

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

private:
    int availableJobs;  ///< Number of available jobs in the shop.
};

#endif // SHOP_H
