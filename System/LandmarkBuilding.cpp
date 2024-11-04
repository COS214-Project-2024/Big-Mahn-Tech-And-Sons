// Class implementation of Factory Method - ConcreteProduct participant (classification)



#include "LandmarkBuilding.h"


LandmarkBuilding::LandmarkBuilding()
    : Building() {
}


void LandmarkBuilding::displayStats() const {
    Building::displayStats();  // Call the base class method
}
