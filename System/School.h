// Class definition of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file School.h
 * @brief Declaration of the School class.
 */

#ifndef SCHOOL_H
#define SCHOOL_H

#include "CommercialBuilding.h"

/**
 * @class School
 * @brief Class representing a school as a subtype of CommercialBuilding.
 *
 * Implements specific attributes and operations for a school,
 * such as managing available kids' spaces.
 */
class School : public CommercialBuilding {
    
    public:
        /**
         * @brief Default constructor for School.
         */
        School();

        /**
         * @brief Displays the stats specific to the school.
         */
        void displayStats() const override;

        /**
         * @brief Checks the availability of kids' spaces in the school.
         * @return True if kids' spaces are available, otherwise false.
         */
        bool checkAvailability() const override;

        /**
         * @brief Accepts visitors for the visitor pattern.
         * @param visitor A pointer to the visitor object.
         */
        void accept(TaxManager* visitor) override;

        /**
         * @brief Clones the school for repair purposes.
         * @return Pointer to the cloned school object.
         */
        Building* repairClone() const override;
};

#endif // SCHOOL_H