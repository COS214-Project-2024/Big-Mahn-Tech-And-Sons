// Class implementation of Factory Method - ConcreteProduct participant (classification)

/**
 * @file ResidentialBuilding.cpp
 * @brief Implements the ResidentialBuilding class.
 */

#include "ResidentialBuilding.h"
#include "TaxManager.h"

/**
 * @brief Default constructor for ResidentialBuilding.
 */
ResidentialBuilding::ResidentialBuilding()
    : Building() {}

/**
 * @brief Displays statistics specific to residential buildings.
 */
void ResidentialBuilding::displayStats() const {
    Building::displayStats();
}

double ResidentialBuilding::calculateTax() const {
    int numOccupants = getCurrentOccupants();
    return numOccupants * getCitizenTax() * 1000; // tax per occupant
}