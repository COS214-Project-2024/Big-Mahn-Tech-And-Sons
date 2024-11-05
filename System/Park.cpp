// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Park.h"
#include <iostream>

/**
 * @brief Constructor for Park.
 */
Park::Park() : LandmarkBuilding()
{
    name = "Magnolia Park";
    maxCapacity = 50;    // Maximum capacity of the park
    width = 50;          // Wider park area
    length = 70;         // Longer park area
    priceTag = 300000.0; // Default price tag for a park
    type = "Park";       // Type of building
}

/**
 * @brief Displays the stats specific to the park.
 */
void Park::displayStats() const
{
    LandmarkBuilding::displayStats(); // Call base class method
}

/**
 * @brief Accepts visitors using the visitor pattern.
 * @param visitor A pointer to the visitor object.
 *
 * The function is stubbed, as no tax is applied to parks.
 */
void Park::accept(TaxManager *visitor)
{
    std::cout << "No tax applied to park: " << getName()
              << ". Parks are non-taxable." << std::endl;
}

/**
 * @brief Clones the park object for repair purposes.
 * @return A pointer to the cloned Park object.
 */
Building *Park::repairClone() const
{
    std::cout << "Prototype: Cloning a Park building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing landmark building (Park): " << getName() << "\n";
    return new Park(*this); // Clone this Park
}