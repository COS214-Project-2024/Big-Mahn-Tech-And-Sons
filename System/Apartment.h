// Class defintion of Factory Method - ConcreteProduct (subtype)

/**
 * @file Apartment.h
 * @brief Declaration of the Apartment class.
 */

#ifndef APARTMENT_H
#define APARTMENT_H

#include "ResidentialBuilding.h"

/**
 * @class Apartment
 * @brief Represents an apartment building with multiple units.
 */
class Apartment : public ResidentialBuilding {
private:
    int numUnits;      ///< Number of units in the apartment building.
    bool hasElevator;  ///< Indicates if the apartment building has an elevator.

public:
    /**
     * @brief Default constructor for Apartment.
     * Initializes with unique default values.
     */
    Apartment();

    /**
     * @brief Displays the stats specific to the apartment.
     */
    void displayStats() const override;

    /**
     * @brief Accepts a visitor for the visitor pattern.
     * @param visitor A pointer to the TaxManager visitor.
     */
    void accept(TaxManager* visitor) override;

    // Getters and Setters
    int getNumUnits() const;
    void setNumUnits(int units);

    bool getHasElevator() const;
    void setHasElevator(bool elevator);
};

#endif // APARTMENT_H