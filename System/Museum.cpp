// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Museum.h"
#include <iostream>

/**
 * @brief Constructor for Museum.
 */
Museum::Museum() : LandmarkBuilding()
{
    name = "Pretoria Museum"; // Name of the museum
    maxCapacity = 80;         // Maximum visitor capacity
    width = 30;               // Museum size width
    length = 50;              // Museum size length
    priceTag = 500000.0;      // Default price tag for a museum
    type = "Museum";          // Type of building
}

/**
 * @brief Displays the stats specific to the museum.
 */
void Museum::displayStats() const
{
    LandmarkBuilding::displayStats(); // Call base class method
}

/**
 * @brief Accepts visitors using the visitor pattern.
 * @param visitor A pointer to the visitor object.
 *
 * The function is stubbed, as no tax is applied to museums.
 */
void Museum::accept(TaxManager *visitor)
{
    std::cout << "No tax applied to museum: " << getName()
              << ". Museums are non-taxable." << std::endl;
}

/**
 * @brief Clones the museum object for repair purposes.
 * @return A pointer to the cloned Museum object.
 */
Building *Museum::repairClone() const
{
    std::cout << "Prototype: Cloning a Museum building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing landmark building (Museum): " << getName() << "\n";
    return new Museum(*this); // Clone this Museum
}
