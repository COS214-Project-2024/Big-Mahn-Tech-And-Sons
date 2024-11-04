// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Monument.h"
#include <iostream>

/**
 * @brief Constructor for Monument.
 */
Monument::Monument() : LandmarkBuilding() {
    name = "Voortrekker Monument";  // Name of the monument
    maxCapacity = 150;              // Maximum visitor capacity
    width = 20;                     // Default monument width
    length = 20;                    // Default monument length
    priceTag = 750000.0;            // Default price tag for a monument
    type = "Monument";              // Type of building
}

/**
 * @brief Displays the stats specific to the monument.
 */
void Monument::displayStats() const {
    LandmarkBuilding::displayStats();  // Call base class method
}

/**
 * @brief Accepts visitors using the visitor pattern.
 * @param visitor A pointer to the visitor object.
 * 
 * The function is stubbed, as no tax is applied to monuments.
 */
void Monument::accept(TaxManager* visitor) {
    std::cout << "No tax applied to monument: " << getName() 
              << ". Monuments are non-taxable." << std::endl;
}

/**
 * @brief Clones the monument object for repair purposes.
 * @return A pointer to the cloned Monument object.
 */
Building* Monument::repairClone() const {
    std::cout << "Prototype: Cloning a Monument building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing landmark building (Monument): " << getName() << "\n";
    return new Monument(*this);  // Clone this Monument
}
