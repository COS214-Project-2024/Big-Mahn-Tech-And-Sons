// Class implementation of Factory Method - ConcreteProduct participant (classification)

/**
 * @file LandmarkBuilding.cpp
 * @brief Implements the LandmarkBuilding class.
 */

#include "LandmarkBuilding.h"

/**
 * @brief Constructor for LandmarkBuilding.
 * Calls the base Building constructor.
 */
LandmarkBuilding::LandmarkBuilding()
    : Building() {
}

/**
 * @brief Displays the stats specific to a landmark building.
 */
void LandmarkBuilding::displayStats() const {
    Building::displayStats();  // Call the base class method
}
