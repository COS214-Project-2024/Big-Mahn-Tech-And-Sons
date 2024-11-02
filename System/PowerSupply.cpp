#include "PowerSupply.h"

PowerSupply::PowerSupply(double budget, double capacity, Power *powerResource)
    : DeptOfUtilities(budget), powerCapacity(capacity), powerResource(powerResource)
{
    cout << "Power Supply Department created  with capacity : " << capacity << endl
         << endl;
}

PowerSupply::~PowerSupply()
{
    // Delete the power resource if it was dynamically allocated
    if (powerResource)
    {
        delete powerResource;
    }
    // Clear the vector to ensure it does not hold dangling pointers
    buildings.clear();
}

void PowerSupply::addBuilding(Building *building)
{
    if (building)
    {
        buildings.push_back(building);
        cout << "Building has been added, it will receive power supply" << endl
             << endl;
    }
}

void PowerSupply::distributePower() // Distributes electricity across various sectors in the city.
{
    for (auto &building : buildings)
    {
        double usage = building->getElectricityUsage(); // Assume this method exists in Building
        if (powerCapacity >= usage)
        {
            building->consumeElectricity(usage); // Assume this method exists in Building
            powerCapacity -= usage;              // Decrease available power
        }
        else
        {
            building->consumeElectricity(powerCapacity); // Consume remaining power
            powerCapacity = 0;                           // All power is consumed
            break;                                       // Exit after distributing available power
        }
    }
}

double PowerSupply::calculatePowerUsage() // calculates the current power usage based on consumption rates.
{
    double totalUsage = 0.0;
    for (Building *building : buildings)
    {
        totalUsage += building->getElectricityUsage(); // Assume this method exists
    }
    return totalUsage;
}

void PowerSupply::powerShutDown()
{
    for (Building *building : buildings)
    {
        building->powerCut(); // Assuming Building has this method
    }
    std::cout << "Power supply has been shut down for all buildings." << std::endl;
}

void PowerSupply::increasePowerCapacity() // Increases the electricity generation capacity of the power plants.
{
    powerCapacity *= 1.5; // Increase capacity by 50%, might change as demand increases
    std::cout << "Increased power generation capacity. New capacity: " << powerCapacity << " units." << std::endl;
}

double PowerSupply::getPowerCapacity() // Gets the current total power generation capacity.
{
    return powerCapacity;
}


bool PowerSupply::handleRequest(Request &req)
{
    if ((req.getType() == "power" || req.getType() == "POWER") && this->budget >= 10000)
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
    else if (successor) // Forward request if type is not handled by PowerSupply
    {
        return successor->handleRequest(req);
    }
    else
    {
        return false;
    }
}
