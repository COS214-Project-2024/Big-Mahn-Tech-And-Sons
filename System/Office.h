// Class definition of Factory Method - COncreteProduct (subtype)

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
 * This class implements the specific attributes and operations for an office,
 * such as managing available jobs.
 */
class Office : public CommercialBuilding {
public:
    /**
     * @brief Constructor for Office.
     * @param name Name of the office.
     * @param maxCapacity Maximum capacity of the office.
     */
    Office(const std::string& name, int maxCapacity);

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

    std::shared_ptr<Building>clone() const override;

private:
    int availableJobs;  ///< Number of available jobs in the office.
};

#endif // OFFICE_H