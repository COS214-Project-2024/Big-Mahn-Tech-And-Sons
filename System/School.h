// Class defintion of Factory Method - ConcreteProduct (subtype)

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
 * This class implements the specific attributes and operations for a school,
 * such as managing available kids' spaces.
 */
class School : public CommercialBuilding {
public:
    /**
     * @brief Constructor for School.
     * @param name Name of the school.
     * @param maxCapacity Maximum capacity of the school.
     */
    School(const std::string& name, int maxCapacity);

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

private:
    int availableKidsSpaces;  ///< Number of available kids' spaces in the school.
};

#endif // SCHOOL_H