#include "PowerSupply.h"

PowerSupply::PowerSupply(string name, double budget, double capacity, Power* powerResource)
    : DeptOfUtilities(name, budget), powerCapacity(capacity),  powerResource(powerResource) {}


/**
 * @brief Destructor for PowerSupply.
 * This destructor releases any dynamically allocated resources.
 */
PowerSupply::~PowerSupply() {
    // // Delete the power resource if it was dynamically allocated
    // if (powerResource) {
    //     delete powerResource;
    // }

    // // Iterate through the vector of buildings and delete each one if it was dynamically allocated
    // for (Building* building : buildings) {
    //     if (building) {
    //         delete building;
    //     }
    // }
    // // Clear the vector to ensure it does not hold dangling pointers
    // buildings.clear();
}

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
        double usage = building->getElectricityUsage(); // Assume this method exists in Building
        if (powerCapacity >= usage) {
            building->consumeElectricity(usage); // Assume this method exists in Building
            powerCapacity -= usage; // Decrease available power
        } else {
            building->consumeElectricity(powerCapacity); // Consume remaining power
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
        totalUsage += building->getElectricityUsage(); // Assume this method exists
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
bool PowerSupply::handleRequest(Request& req) {
    if (req.getType() == "Power" && this->budget >= 10000  ) 
    {
        // Check if PowerSupply can fulfill the power request
        if (req.getAmount() <= powerCapacity)
        {
            std::cout << "PowerSupply handling request for " << req.getAmount()
                      << " units of power for " << req.getBuilding()->getName() << std::endl;
            powerCapacity -= req.getAmount();
            this->budget -= 10000;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        // Forward request if type is not handled by PowerSupply
        if (successor)
        {
            successor->handleRequest(req);
        } else {
            std::cout << "No handler found for request type: " << req.getType() << std::endl;
            return false;
        }
    }
}