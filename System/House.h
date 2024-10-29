// Class defintion of Factory Method - ConcreteProduct (subtype)

/**
 * @file House.h
 * @brief Declaration of the House class.
 */

#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"

/**
 * @class House
 * @brief Represents a residential house building.
 */
class House : public ResidentialBuilding {
private:
    int numFloors;  ///< Number of floors in the house.

public:
    /**
     * @brief Default constructor for House.
     * Initializes with unique default values.
     */
    House();

    /**
     * @brief Displays the stats specific to the house.
     */
    void displayStats() const override;

    /**
     * @brief Accepts a visitor for the visitor pattern.
     * @param visitor A pointer to the TaxManager visitor.
     */
    void accept(TaxManager* visitor) override;

    // Getters and Setters
    int getNumFloors() const;
    void setNumFloors(int floors);
};

#endif // HOUSE_H