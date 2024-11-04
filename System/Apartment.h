// Class defintion of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file Apartment.h
 * @brief Declaration of the Apartment class, representing a multi-unit residential building.
 */

#ifndef APARTMENT_H
#define APARTMENT_H

#include "ResidentialBuilding.h"
#include "TaxManager.h"

/**
 * @class Apartment
 * @brief Represents an apartment building with multiple residential units.
 */
class Apartment : public ResidentialBuilding {

    public:
        /**
         * @brief Default constructor for Apartment, initializing unique apartment attributes.
         */
        Apartment();

        /**
         * @brief Displays the statistics of the apartment, including specific and inherited details.
         */
        void displayStats() const override;

        /**
         * @brief Accepts a visitor for tax management or other visitor pattern operations.
         * @param visitor A pointer to the TaxManager visitor.
         */
        void accept(TaxManager* visitor) override;

      Building* repairClone() const;
      
    // Getters and Setters
    int getNumUnits() const;
    void setNumUnits(int units);

    bool getHasElevator() const;
    void setHasElevator(bool elevator);
};

#endif // APARTMENT_H
