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
Museum::Museum(const std::string& name, int maxCapacity, int exhibitCount, 
               double entryFee, bool heritageStatus)
    : LandmarkBuilding(name, maxCapacity, "Museum", heritageStatus),
      exhibitCount(exhibitCount), entryFee(entryFee) 
{
    width = 30;           // Museum size width
    length = 50;          // Museum size length
    priceTag = 500000.0;  // Default price tag for a museum
}

/**
 * @brief Displays the stats specific to the museum.
 */
void Museum::displayStats() const {
    LandmarkBuilding::displayStats();  // Call base class method
    std::cout << "Exhibit Count: " << exhibitCount << std::endl;
    std::cout << "Entry Fee: " << entryFee << " currency units" << std::endl;
}

/**
 * @brief Accepts visitors using the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Museum::accept(TaxManager* visitor) { // Malaika STUB!!!
    // visitor->visit(this);  // Visitor pattern implementation
}

Building* Museum::clone() const
{
   return new Museum(*this);
}

/**
 * @brief Gets the number of exhibits.
 * @return The number of exhibits.
 */
int Museum::getExhibitCount() const {
    return exhibitCount;
}

/**
 * @brief Sets the number of exhibits.
 * @param count New number of exhibits.
 */
void Museum::setExhibitCount(int count) {
    if (count >= 0) {
        exhibitCount = count;
    } else {
        std::cerr << "Error: Exhibit count cannot be negative." << std::endl;
    }
}

/**
 * @brief Gets the entry fee.
 * @return The entry fee in local currency.
 */
double Museum::getEntryFee() const {
    return entryFee;
}

/**
 * @brief Sets the entry fee.
 * @param fee New entry fee in local currency.
 */
void Museum::setEntryFee(double fee) {
    if (fee >= 0.0) {
        entryFee = fee;
    } else {
        std::cerr << "Error: Entry fee cannot be negative." << std::endl;
    }
}
