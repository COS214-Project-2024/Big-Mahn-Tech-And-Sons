// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Park.h"
#include <iostream>

/**
 * @brief Constructor for Park.
 * @param name Name of the park.
 * @param maxCapacity Maximum visitor capacity.
 * @param greenSpaceArea Total area of green space in square meters.
 * @param playgroundCount Number of playgrounds within the park.
 * @param heritageStatus Whether the park is a heritage site.
 */
Park::Park(const std::string& name, int maxCapacity, double greenSpaceArea,
           int playgroundCount, bool heritageStatus)
    : LandmarkBuilding(name, maxCapacity, "Public Park", heritageStatus),
      greenSpaceArea(greenSpaceArea), playgroundCount(playgroundCount) 
{
    width = 50;             // Wider park area
    length = 70;            // Longer park area
    priceTag = 300000.0;    // Default price tag for a park
}

/**
 * @brief Displays the stats specific to the park.
 */
void Park::displayStats() const {
    LandmarkBuilding::displayStats();  // Call base class method
    std::cout << "Green Space Area: " << greenSpaceArea << " sq meters" << std::endl;
    std::cout << "Playground Count: " << playgroundCount << std::endl;
}

/**
 * @brief Accepts visitors using the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Park::accept(TaxManager* visitor) { // Malaika STUB!!!
    // visitor->visit(this);  // Visitor pattern implementation
}

/**
 * @brief Sets the green space area.
 * @param area New green space area in square meters.
 */
void Park::setGreenSpaceArea(double area) {
    if (area >= 0) {
        greenSpaceArea = area;
    } else {
        std::cerr << "Error: Green space area cannot be negative." << std::endl;
    }
}

/**
 * @brief Gets the green space area.
 * @return The area of green space in square meters.
 */
double Park::getGreenSpaceArea() const {
    return greenSpaceArea;
}

/**
 * @brief Sets the number of playgrounds.
 * @param count New playground count.
 */
void Park::setPlaygroundCount(int count) {
    if (count >= 0) {
        playgroundCount = count;
    } else {
        std::cerr << "Error: Playground count cannot be negative." << std::endl;
    }
}

/**
 * @brief Gets the number of playgrounds.
 * @return The number of playgrounds.
 */
int Park::getPlaygroundCount() const {
    return playgroundCount;
}
