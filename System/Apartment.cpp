// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Apartment.h"
#include <iostream>

/**
 * @brief Default constructor for Apartment.
 * Initializes the apartment with unique default values.
 */
Apartment::Apartment()
    : ResidentialBuilding("Urban Apartment", 50, false),  // Default: Urban Apartment without backyard
      numUnits(25), hasElevator(true) {  // Defaults: 25 units, with elevator
    width = 30;  // Custom width for apartment
    length = 50; // Custom length for apartment
    electricityMeterBox = 200.0;  // Default electricity meter reading
    waterMeterBox = 500.0;        // Default water meter reading
    electricityUsage = 0.0;       // Start with no electricity usage
    waterUsage = 0.0;             // Start with no water usage
    waste = 0.0;                  // Start with no waste production
    priceTag = 150000.0; // Setting price tag for Apartment
}

/**
 * @brief Displays the stats specific to the apartment.
 */
void Apartment::displayStats() const {
    // Call the parent class's displayStats() to print shared details.
    ResidentialBuilding::displayStats();
    std::cout << "Number of Units: " << numUnits << std::endl;
    std::cout << "Has Elevator: " << (hasElevator ? "Yes" : "No") << std::endl;
}

/**
 * @brief Accepts a visitor for the visitor pattern.
 * @param visitor A pointer to the TaxManager visitor.
 */
void Apartment::accept(TaxManager* visitor) {
    visitor->visit(this);
}

/**
 * @brief Getter for the number of units.
 * @return The number of units in the apartment.
 */
int Apartment::getNumUnits() const {
    return numUnits;
}

/**
 * @brief Setter for the number of units.
 * @param units The new number of units for the apartment.
 */
void Apartment::setNumUnits(int units) {
    numUnits = units;
}

/**
 * @brief Getter for elevator availability.
 * @return True if the apartment has an elevator, otherwise false.
 */
bool Apartment::getHasElevator() const {
    return hasElevator;
}

/**
 * @brief Setter for elevator availability.
 * @param elevator The new elevator status for the apartment.
 */
void Apartment::setHasElevator(bool elevator) {
    hasElevator = elevator;
}
