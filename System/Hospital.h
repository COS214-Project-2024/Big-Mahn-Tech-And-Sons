// Class defintion of Factory Method - ConcreteProduct (subtype)

/**
 * @file Hospital.h
 * @brief Declaration of the Hospital class.
 */

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "CommercialBuilding.h"

/**
 * @class Hospital
 * @brief Class representing a hospital as a subtype of CommercialBuilding.
 *
 * This class implements the specific attributes and operations for a hospital,
 * such as managing available beds.
 */
class Hospital : public CommercialBuilding {
public:
    /**
     * @brief Constructor for Hospital.
     * @param name Name of the hospital.
     * @param maxCapacity Maximum capacity of the hospital.
     */
    Hospital();

    /**
     * @brief Displays the stats specific to the hospital.
     */
    void displayStats() const override;

    /**
     * @brief Checks the availability of beds in the hospital.
     * @return True if beds are available, otherwise false.
     */
    bool checkAvailability() const override;

    /**
     * @brief Accepts visitors for the visitor pattern.
     * @param visitor A pointer to the TaxManger object.
     */
    void accept(TaxManager* visitor) override;

   Building* repairClone() const override;

private:
    int availableBeds;  ///< Number of available beds in the hospital.
};

#endif // HOSPITAL_H