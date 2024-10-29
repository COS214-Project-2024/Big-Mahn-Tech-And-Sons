#include "PowerSupply.h"

PowerSupply::PowerSupply(string name, double budget, double capacity, Power* powerResource)
    : DeptOfUtilities(name, budget), powerCapacity(capacity),  powerResource(powerResource) {}

/**
 * @brief Adds a building to the power supply system.
 * @param building Pointer to the building to add.
 */
void PowerSupply::addBuilding(Building* building) {
    buildings.push_back(building);
}


/**
 * @brief Distributes electricity across various sectors in the city.
 */
void PowerSupply::distributePower() {
    for (auto& building : buildings) {
        double usage = building->getPowerUsage(); // Assume this method exists in Building
        if (powerCapacity >= usage) {
            building->consumePower(usage); // Assume this method exists in Building
            powerCapacity -= usage; // Decrease available power
        } else {
            building->consumePower(powerCapacity); // Consume remaining power
            powerCapacity = 0; // All power is consumed
            break; // Exit after distributing available power
        }
    }
}

/**
 * @brief Calculates the current power usage based on consumption rates.
 * @return The amount of electricity consumed.
 */
double PowerSupply::calculatePowerUsage() {
    double totalUsage = 0.0;
    for (Building* building : buildings) {
        totalUsage += building->getPowerUsage(); // Assume this method exists
    }
    return totalUsage;
}

/**
 * @brief Shuts down power generation for maintenance or emergency purposes.
 */
void PowerSupply::powerShutDown() {
    for (Building* building : buildings) {
        building->powerCut(); // Assuming Building has this method
    }
    std::cout << "Power supply has been shut down for all buildings." << std::endl;
}

/**
 * @brief Increases the electricity generation capacity of the power plants.
 */
void PowerSupply::increasePowerCapacity() {
    powerCapacity *= 1.5; // Increase capacity by 50%, might change as demand increases
    std::cout << "Increased power generation capacity. New capacity: " << powerCapacity << " units." << std::endl;
}


/**
 * @brief Gets the current total power generation capacity.
 * @return The current power generation capacity available.
 */
double PowerSupply::getPowerCapacity() {
    return powerCapacity;
}

/**
 * @brief The handleRequest() function is the core method responsible for either processing 
 *          the request or passing it along the chain to the next handler. PowerSupply 
 *          checks if it can handle the request, if not, PowerSupply will pass it on
 *          to the next concreteHandler.
 */
void PowerSupply::handleRequest(Request& req) {
    if (req.getType() == Request::Type::POWER) 
    {
        double demand = req.getAmount();
        if (powerCapacity >= demand) {
            distributePower();
            std::cout << "PowerSupply: Distributed " << demand << " units of electricity.\n";
        } else {
            std::cout << "PowerSupply: Insufficient power capacity.\n";
        }
    } 
    else if (successor) 
    {
        successor->handleRequest(req);
    } 
    else 
    {
        std::cout << "PowerSupply: Request could not be handled.\n";
    }
}