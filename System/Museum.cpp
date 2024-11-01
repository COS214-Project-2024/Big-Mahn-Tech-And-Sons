// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Museum.h"
#include <iostream>

/**
 * @brief Constructor for Museum.
 * @param name Name of the museum.
 * @param maxCapacity Maximum visitor capacity.
 * @param exhibitCount Number of exhibits in the museum.
 * @param entryFee Entry fee in local currency.
 * @param heritageStatus Whether the museum is a heritage site.
 */
Museum::Museum()
    : LandmarkBuilding()
{
    name = "Pretoria Museum";
    maxCapacity = 80;
    width = 30;           // Museum size width
    length = 50;          // Museum size length
    priceTag = 500000.0;  // Default price tag for a museum
    type = "Museum";
}

/**
 * @brief Displays the stats specific to the museum.
 */
void Museum::displayStats() const {
    LandmarkBuilding::displayStats();  // Call base class method
}

/**
 * @brief Accepts visitors using the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Museum::accept(TaxManager* visitor) { // Malaika STUB!!!
    // visitor->visit(this);  // Visitor pattern implementation
}

Building* Museum::repairClone() const
{
   return new Museum(*this);
}

