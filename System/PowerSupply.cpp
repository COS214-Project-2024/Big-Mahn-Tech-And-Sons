#include "PowerSupply.h"

PowerSupply::PowerSupply(double budget, double capacity, Power *powerResource)
    : DeptOfUtilities(budget), powerCapacity(capacity), powerResource(powerResource)
{
    cout << "Power Supply Department created  with capacity : " << capacity << endl
         << endl;
}

PowerSupply::~PowerSupply()
{
    if (powerResource)
    {
        delete powerResource;
    }
    buildings.clear();
}

double PowerSupply::getBudget()
{
    return this->budget;
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
    for (Building *it : buildings)
    {
        cout << "----------- Next building " << it->getName() << " gets water ----------- " << endl;

        double usage = it->getElectricityUsage(); // Assume this method exists in Building
        if (powerResource->getPowerAmount() >= usage)
        {
            powerResource->usePower(usage); // Decrease available power

            double newVal = it->getElectricityMeterBox() + usage;
            it->setElectricityMeterBox(newVal);
            std::cout << "Distributed power : " << it->getElectricityUsage() << " to " << it->getName() << std::endl;
        }
        else
        {
            powerResource->usePower(powerResource->getPowerAmount()); // Decrease available water
            std::cout << "Only distributed power : " << powerCapacity << " to " << it->getName() << std::endl;
            powerCapacity = 0; // All water is consumed
        }
    }
}

void PowerSupply::distributePowerToBuilding(Building *b)
{
    double usage = b->getElectricityUsage(); // Assume this method exists in Building
    if (powerResource->getPowerAmount() >= usage)
    {
        powerResource->usePower(usage); // Decrease available power

        double newVal = b->getElectricityMeterBox() + usage;
        b->setElectricityMeterBox(newVal);
        std::cout << "Distributed power : " << b->getElectricityUsage() << " to " << b->getName() << std::endl;
    }
    else
    {
        powerResource->usePower(powerResource->getPowerAmount()); // Decrease available water
        std::cout << "Only distributed power : " << powerCapacity << " to " << b->getName() << std::endl;
        powerCapacity = 0; // All water is consumed
    }
}

void PowerSupply::DistributePowerToBuilding(Building *b, double incomingAmt)
{
    double usage = b->getElectricityUsage(); // Assume this method exists in Building
    if (incomingAmt <= usage)
    {
        double newVal = b->getElectricityMeterBox() + incomingAmt;
        b->setElectricityMeterBox(newVal);
        std::cout << "Distributed power : " << incomingAmt << " to " << b->getName() << std::endl;
    }
    else
    {
        std::cout << "Failed to distribute " << incomingAmt << " because the amount exceeds the meterBox capacity for " << b->getName() << std::endl;
        cout << "The current power usage for " << b->getName() << " is only " << usage << endl;
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
    if ((req.getType() == "power" || req.getType() == "POWER" || req.getType() == "Power") && this->budget >= 1000)
    {
        if (req.getAmount() <= powerCapacity)
        {
            std::cout << "PowerSupply handling request for " << req.getAmount()
                      << " units of power for " << req.getBuilding()->getName() << std::endl;
            DistributePowerToBuilding(req.getBuilding(), req.getAmount());
            powerCapacity -= req.getAmount();
            this->budget -= 100;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (successor) // Forward request if type is not handled by PowerSupply
    {
        if (successor)
        {
            if (successor != NULL)
            {
                return successor->handleRequest(req);
            }
        }
    }
    else
    {
        return false;
    }
}
