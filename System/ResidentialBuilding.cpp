// Class implementation of Factory Method - ConcreteProduct participant (classification)

#include "ResidentialBuilding.h"
#include "TaxManager.h"

ResidentialBuilding::ResidentialBuilding()
    : Building() {}

void ResidentialBuilding::displayStats() const
{
    Building::displayStats();
}

double ResidentialBuilding::calculateTax() const
{
    int numOccupants = getCurrentOccupants();
    return numOccupants * getCitizenTax() * 1000; // tax per occupant
}