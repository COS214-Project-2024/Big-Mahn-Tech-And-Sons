// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Hospital.h"
#include <iostream>

/**
 * @brief Constructor for Hospital.
 * @param name Name of the hospital.
 * @param maxCapacity Maximum capacity of the hospital.
 */
Hospital::Hospital()
    : CommercialBuilding() {
        availableBeds = maxCapacity;
    name = "Steve Biko Hospital";
    maxCapacity = 200;
    width = 20;  // Set a unique width for hospital
    length = 40; // Set a unique length for hospital
    electricityMeterBox = 250.0; // Initial electricity meter reading
    waterMeterBox = 350.0;       // Initial water meter reading
    electricityUsage = 0.0;
    waterUsage = 0.0;
    wasteProduction = 0.0;
    priceTag = 400000.0; // Setting price tag for Hospital
    netWorth = 3000000.0;
    type = "Hospital";
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

Building* Hospital::repairClone() const  {
    return new Hospital(*this);  // Clone this School
}