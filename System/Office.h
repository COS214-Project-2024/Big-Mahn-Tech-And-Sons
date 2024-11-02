// Class definition of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file Office.h
 * @brief Declaration of the Office class.
 */

#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuilding.h"

/**
 * @class Office
 * @brief Class representing an office as a subtype of CommercialBuilding.
 *
 * Implements specific attributes and operations for an office,
 * such as managing available jobs.
 */
class Office : public CommercialBuilding {
    
    public:
        /**
         * @brief Default constructor for Office.
         */
        Office();

        /**
         * @brief Displays the stats specific to the office.
         */
        void displayStats() const override;

        /**
         * @brief Checks the availability of jobs in the office.
         * @return True if jobs are available, otherwise false.
         */
        bool checkAvailability() const override;

        /**
         * @brief Accepts visitors for the visitor pattern.
         * @param visitor A pointer to the visitor object.
         */
        void accept(TaxManager* visitor) override;

        /**
         * @brief Clones the office for repair purposes.
         * @return Pointer to the cloned office object.
         */
        Building* repairClone() const override;
    };

#endif // OFFICE_H
