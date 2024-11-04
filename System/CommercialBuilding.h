// Class definition of Factory Method - ConcreteProduct participant (classification)

/**
 * @file CommercialBuilding.h
 * @brief Declaration of the CommercialBuilding class.
 */

#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "Building.h"
#include "TaxManager.h"
#include <iostream>

/**
 * @class CommercialBuilding
 * @brief Abstract class representing commercial buildings.
 *
 * Provides shared attributes and operations for all commercial buildings,
 * such as available jobs, kid spaces, and beds. Subtypes handle specific implementations.
 */
class CommercialBuilding : public Building {

    protected:
        int availableJobs;       ///< Available jobs (for shops and offices).
        int availableKidsSpaces; ///< Available kid spaces (for schools).
        int availableBeds;       ///< Available beds (for hospitals).
        bool closed;             ///< Indicates if the building is closed due to recession.
        double annualRevenue;

    public:
        /**
         * @brief Constructor for CommercialBuilding.
         */
        CommercialBuilding();

        /**
         * @brief Displays the stats specific to commercial buildings.
         */
        void displayStats() const;

        // Getters and Setters
        int getAvailableJobs() const;
        void setAvailableJobs(int jobs);

        int getAvailableKidsSpaces() const;
        void setAvailableKidsSpaces(int kidsSpaces);

        int getAvailableBeds() const;
        void setAvailableBeds(int beds);

        /**
         * @brief Checks the availability of resources depending on the subtype.
         * Pure virtual function to be defined in derived classes.
         */
        virtual bool checkAvailability() const = 0;

        /**
         * @brief Accepts visitors for the visitor pattern.
         * @param visitor Pointer to a TaxManager object.
         */
        virtual void accept(TaxManager* visitor) = 0;

        /**
         * @brief Closes the building due to recession.
         */
        void closeBuilding();

        /**
         * @brief Reopens the building and restores resources to maximum capacity.
         */
        void reopenBuilding();

        /**
         * @brief Checks if the building is closed.
         * @return True if the building is closed, otherwise false.
         */
        bool isClosed() const;

        /**
         * @brief Clones the commercial building for repairs.
         * Pure virtual method to be defined in derived classes.
         */
        virtual Building* repairClone() const = 0;
};

#endif // COMMERCIALBUILDING_H
