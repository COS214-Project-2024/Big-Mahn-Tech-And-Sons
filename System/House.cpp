// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "House.h"
#include <iostream>

/**
 * @brief Default constructor for House.
 * Initializes the house with unique default values.
 */
House::House()
    : ResidentialBuilding("Family House", 4, true),  // Default: Family House with backyard
      numFloors(2) {  // Default number of floors
    width = 15;  // Custom width
    length = 20; // Custom length
    electricityMeterBox = 50.0;  // Default electricity meter reading
    waterMeterBox = 100.0;       // Default water meter reading
    electricityUsage = 0.0;      // Start with no electricity usage
    waterUsage = 0.0;            // Start with no water usage
    wasteProduction = 0.0;                 // Start with no waste production
    priceTag = 250000.0; // Setting price tag for House
}

/**
 * @brief Displays the stats specific to the house.
 */
void House::displayStats() const {
    // Call the parent class's displayStats() to print shared details.
    ResidentialBuilding::displayStats();  
    std::cout << "Number of Floors: " << numFloors << std::endl;
}

/**
 * @brief Accepts a visitor for the visitor pattern.
 * @param visitor A pointer to the TaxManager visitor.
 */
void House::accept(TaxManager* visitor) {
    visitor->visitResidentialBuilding(this);
}

/**
 * @brief Getter for the number of floors.
 * @return The number of floors in the house.
 */
int House::getNumFloors() const {
    return numFloors;
}

/**
 * @brief Setter for the number of floors.
 * @param floors The new number of floors for the house.
 */
void House::setNumFloors(int floors) {
    numFloors = floors;
}


Building* House::clone() const  {
    return new House(*this);  // Clone this estate
}