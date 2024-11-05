#include "PowerSupply.h"

PowerSupply::PowerSupply(double budget, double capacity, Power *powerResource)
    : DeptOfUtilities(budget), powerCapacity(capacity), powerResource(powerResource)
{
    cout << "Power Supply Department created  with capacity : "
         << capacity << " MegaWatts and budget: ZAR" << this->budget << endl
         << endl;
}

PowerSupply::~PowerSupply()
{
    if (powerResource)
    {
        delete powerResource;
    }
}

double PowerSupply::getBudget()
{
    return this->budget;
}

void PowerSupply::distributePower() // Distributes electricity across various sectors in the city.
{
    this->requestPR("building");
    for (Building *it : buildings)
    {
        if (it != NULL)
        {
            cout << "----------- Next building " << it->getName() << " gets power ----------- " << endl;

            double usage = it->getElectricityUsage(); // Assume this method exists in Building
            if (powerResource->getPowerAmount() >= usage)
            {
                powerResource->usePower(usage); // Decrease available power

                double newVal = it->getElectricityMeterBox() + usage;
                it->setElectricityMeterBox(newVal);
                std::cout << "Distributed power : " << it->getElectricityUsage() << " units to " << it->getName() << std::endl;
            }
            else
            {
                powerResource->usePower(powerResource->getPowerAmount()); // Decrease available water
                std::cout << "Only distributed power : " << powerCapacity << " units to " << it->getName() << std::endl;
                powerCapacity = 0; // All water is consumed
            }
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
        std::cout << "Distributed power : " << b->getElectricityUsage() << " units to " << b->getName() << std::endl;
    }
    else
    {
        powerResource->usePower(powerResource->getPowerAmount()); // Decrease available water
        std::cout << "Only distributed power : " << powerCapacity << " units to " << b->getName() << std::endl;
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
        std::cout << "Distributed power : " << incomingAmt << " units to " << b->getName() << std::endl;
    }
    else
    {
        std::cout << "Failed to distribute " << incomingAmt << " units because the amount exceeds the meterBox capacity for " << b->getName() << std::endl;
        cout << "The current power usage for " << b->getName() << " is only " << usage << endl;
    }
}

double PowerSupply::calculatePowerUsage() // calculates the current power usage based on consumption rates.
{
    double totalUsage = 0.0;
    this->requestPR("building");
    for (Building *it : buildings)
    {
        if (it != NULL)
        {
            totalUsage += it->getElectricityUsage(); // Assume this method exists
        }
    }
    return totalUsage;
}

void PowerSupply::powerShutDown()
{
    this->requestPR("building");
    for (Building *it : buildings)
    {
        if (it != NULL)
        {
            it->powerCut(); // Assuming Building has this method
        }
    }
    cout << "Water supply has been shut down for all buildings." << endl;
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
