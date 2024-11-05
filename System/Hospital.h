// Class definition of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file Hospital.h
 * @brief Declaration of the Hospital class.
 */

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "CommercialBuilding.h"
class TaxManger;
/**
 * @class Hospital
 * @brief Class representing a hospital as a subtype of CommercialBuilding.
 *
 * Implements specific attributes and operations for a hospital,
 * such as managing available beds.
 */
class Hospital : public CommercialBuilding
{

public:
    /**
     * @brief Default constructor for Hospital.
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
     * @param visitor A pointer to the TaxManager object.
     */
    void accept(TaxManager *visitor) override;

    /**
     * @brief Clones the hospital for repair purposes.
     * @return Pointer to the cloned hospital object.
     */
    Building *repairClone() const override;
};

#endif // HOSPITAL_H
