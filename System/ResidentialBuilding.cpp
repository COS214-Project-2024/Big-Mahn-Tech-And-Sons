// Class implementation of Factory Method - ConcreteProduct participant (classification)

#include "ResidentialBuilding.h"


ResidentialBuilding::ResidentialBuilding()
    : Building() {}


void ResidentialBuilding::displayStats() const {
    Building::displayStats();
}