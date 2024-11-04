// Class implementation of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file Hospital.cpp
 * @brief Implements the Hospital class.
 */

#include "Hospital.h"
#include <iostream>

/**
 * @brief Default constructor for Hospital.
 */
Hospital::Hospital()
    : CommercialBuilding() {
    name = "Community Health Center";  // Default name for the hospital
    maxCapacity = 200;                  // Set maximum capacity for the hospital
    availableBeds = maxCapacity;        // Initialize available beds to max capacity
    width = 20;                         // Default width for hospitals
    length = 40;                        // Default length for hospitals
    electricityMeterBox = 250.0;       // Initial electricity meter reading
    waterMeterBox = 350.0;             // Initial water meter reading
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 400000.0;                // Default price tag for Hospital
    netWorth = 3000000.0;
    type = "Hospital";
    annualRevenue = 2000000.0;          // Default annual revenue for Hospital
}

/**
 * @brief Displays the stats specific to the hospital.
 */
void Hospital::displayStats() const {
    CommercialBuilding::displayStats();  // Call base class method
    std::cout << "Available Beds: " << availableBeds << std::endl;
}

/**
 * @brief Checks the availability of beds in the hospital.
 * @return True if beds are available, otherwise false.
 */
bool Hospital::checkAvailability() const {
    return availableBeds > 0;  // Beds are available if any exist
}

/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Hospital::accept(TaxManager* visitor) {
    visitor->visitCommercialBuilding(this);
}

/**
 * @brief Clones the hospital for repair purposes.
 * @return Pointer to the cloned hospital object.
 */
Building* Hospital::repairClone() const {
    std::cout << "Prototype: Cloning a Hospital building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing commercial building (Hospital): " << getName() << "\n";
    return new Hospital(*this);  // Return a new cloned instance of Hospital
}
