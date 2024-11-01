// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Park.h"
#include <iostream>

/**
 * @brief Constructor for Park.
 * @param name Name of the park.
 * @param maxCapacity Maximum visitor capacity.
 * @param greenSpaceArea Total area of green space in square meters.
 * @param playgroundCount Number of playgrounds within the park.
 * @param heritageStatus Whether the park is a heritage site.
 */
Park::Park()
    : LandmarkBuilding()
{
    name = "Magnolia Park";
    maxCapacity = 50;
    width = 50;             // Wider park area
    length = 70;            // Longer park area
    priceTag = 300000.0;    // Default price tag for a park
    type = "Park";
}

/**
 * @brief Displays the stats specific to the park.
 */
void Park::displayStats() const {
    LandmarkBuilding::displayStats();  // Call base class method
}

/**
 * @brief Accepts visitors using the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Park::accept(TaxManager* visitor) { // Malaika STUB!!!
    // visitor->visit(this);  // Visitor pattern implementation
}


Building* Park::repairClone() const  {
        return new Park(*this);  // Clone this School
}