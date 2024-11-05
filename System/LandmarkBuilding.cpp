// Class implementation of Factory Method - ConcreteProduct participant (classification)

#include "LandmarkBuilding.h"
#include "TaxManager.h"

LandmarkBuilding::LandmarkBuilding()
    : Building()
{
}

void LandmarkBuilding::displayStats() const
{
    Building::displayStats(); // Call the base class method
}

/**
 * @brief Calculates tax for a landmark.
 * Since landmarks are exempt, this returns 0.0.
 *
 * @return Tax amount (0.0).
 */
double LandmarkBuilding::calculateTax() const
{
    return 0.0;
}