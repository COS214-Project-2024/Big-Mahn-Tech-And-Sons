// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Monument.h"
#include <iostream>

/**
 * @brief Constructor for Monument.
 * @param name Name of the monument.
 * @param maxCapacity Maximum visitor capacity.
 * @param yearEstablished Year the monument was established.
 * @param heritageStatus Whether the monument is a heritage site.
 */
Monument::Monument()
    : LandmarkBuilding()

{
    name = "Voortrekker Monument";
    maxCapacity = 150;
    width = 20;            // Default monument width
    length = 20;           // Default monument length
    priceTag = 750000.0;   // Default price tag for a monument
    type = "Monument";
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
 */
void Monument::accept(TaxManager* visitor) { // Malaika STUB!!!
    // visitor->visit(this);  // Visitor pattern implementation
}


Building* Monument::repairClone() const  {
        return new Monument(*this);  // Clone this School
}
