#include "Estate.h"
#include <iostream>

/**
 * @brief Default constructor for Estate.
 * Initializes the estate with unique default values.
 */
Estate::Estate()
    : ResidentialBuilding("Luxury Estate", 10, true),  // Default: Luxury Estate with backyard
      numFloors(2), hasSwimmingPool(true) {  // Defaults: 2 floors, with swimming pool
    width = 40;  // Custom width for estate
    length = 60; // Custom length for estate
    electricityMeterBox = 300.0;  // Default electricity meter reading
    waterMeterBox = 800.0;        // Default water meter reading
    electricityUsage = 0.0;       // Start with no electricity usage
    waterUsage = 0.0;             // Start with no water usage
    waste = 0.0;                  // Start with no waste production
    priceTag = 500000.0; // Setting price tag for Estate
}

/**
 * @brief Displays the stats specific to the estate.
 */
void Estate::displayStats() const {
    // Call the parent class's displayStats() to print shared details.
    ResidentialBuilding::displayStats();
    std::cout << "Number of Floors: " << numFloors << std::endl;
    std::cout << "Has Swimming Pool: " << (hasSwimmingPool ? "Yes" : "No") << std::endl;
}

/**
 * @brief Accepts a visitor for the visitor pattern.
 * @param visitor A pointer to the TaxManager visitor.
 */
void Estate::accept(TaxManager* visitor) {
    visitor->visit(this);
}

/**
 * @brief Getter for the number of floors.
 * @return The number of floors in the estate.
 */
int Estate::getNumFloors() const {
    return numFloors;
}

/**
 * @brief Setter for the number of floors.
 * @param floors The new number of floors for the estate.
 */
void Estate::setNumFloors(int floors) {
    numFloors = floors;
}

/**
 * @brief Getter for swimming pool availability.
 * @return True if the estate has a swimming pool, otherwise false.
 */
bool Estate::getHasSwimmingPool() const {
    return hasSwimmingPool;
}

/**
 * @brief Setter for swimming pool availability.
 * @param pool The new swimming pool status for the estate.
 */
void Estate::setHasSwimmingPool(bool pool) {
    hasSwimmingPool = pool;
}