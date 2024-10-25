// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Factory.h"
#include <iostream>

/**
 * @brief Constructor for Factory.
 * @param name Name of the factory.
 * @param maxCapacity Maximum capacity of the factory.
 * @param maxProductionCapacity Maximum production capacity of the factory.
 * @param operationalHours Operational hours per day.
 */
Factory::Factory(const std::string& name, int maxCapacity, int maxProductionCapacity, double operationalHours)
    : IndustrialBuilding(name, maxCapacity, maxProductionCapacity),
      operationalHours(operationalHours) {
    priceTag = 500000.0; // Unique price tag for factory
}

/**
 * @brief Displays the stats specific to the factory.
 */
void Factory::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method
    std::cout << "Operational Hours: " << operationalHours << std::endl;
}

/**
 * @brief Checks if the factory can accommodate additional production.
 * @return True if production capacity is available, otherwise false.
 */
bool Factory::checkProductionCapacity() const {
    return (productionRate < maxProductionCapacity);
}

/**
 * @brief Accepts visitors for the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Factory::accept(TaxManager* visitor) {
    visitor->visit(this);
}
