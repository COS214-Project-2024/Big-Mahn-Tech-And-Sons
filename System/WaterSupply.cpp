#include "WaterSupply.h"

WaterSupply::WaterSupply(double budget, double capacity, Water *waterResource)
    : DeptOfUtilities(budget), waterCapacity(capacity), waterResource(waterResource)
{
    cout << "Water Supply Department created with capacity : " << capacity << endl
         << endl;
}

void WaterSupply::addBuilding(Building *building)
{
    if (building != NULL)
    {
        buildings.push_back(building);
        cout << "Building has been added, it will receive water supply" << endl
             << endl;
    }
}

WaterSupply::~WaterSupply()
{
    // Delete the water resource if it was dynamically allocated
    if (waterResource)
    {
        delete waterResource;
    }
    // Clear the vector to ensure it does not hold dangling pointers
    buildings.clear();
}

void WaterSupply::distributeWater()
{
    for (Building *it : buildings)
    {
        cout << "----------- Next building " << it->getName() << " gets water ----------- " << endl;

        double usage = it->getWaterUsage(); // this method exists in Building
        cout << "Water usage so far is : " << usage << endl;
        if (waterResource->getWaterAmount() >= usage)
        {
            waterResource->useWater(usage); // Decrease available water

            double newDist = it->getWaterMeterBox() + usage;
            it->setWaterMeterBox(newDist);
            std::cout << "Distributed water : " << it->getWaterUsage() << " to " << it->getName() << std::endl;
        }
        else
        {
            waterResource->useWater(waterResource->getWaterAmount()); // Decrease available water
            std::cout << "Only distributed water : " << waterCapacity << " to " << it->getName() << std::endl;
            waterCapacity = 0;
            this->budget -= 500; // All water is consumed
        }
    }
}

void WaterSupply::distributeWaterToBuilding(Building *b)
{
    double usage = b->getWaterUsage(); // this method exists in Building
    cout << "Water usage for building : " << b->getName() << ": " << usage << endl;
    if (waterResource->getWaterAmount() >= usage)
    {
        waterResource->useWater(usage); // Decrease available water
        double newDist = b->getWaterMeterBox() + usage;
        b->setWaterMeterBox(newDist);
        this->budget -= 300;

        std::cout << "Distributed water : " << b->getWaterUsage() << " to " << b->getName() << std::endl;
    }
    else
    {
        waterResource->useWater(waterResource->getWaterAmount()); // Decrease available water
        std::cout << "Only distributed water : " << waterCapacity << " to " << b->getName() << std::endl;
        waterCapacity = 0; // All water is consumed
    }
}

void WaterSupply::distributeWaterToBuilding(Building *b, double incomingAmt)
{
    double usage = b->getWaterUsage(); // this method exists in Building
    if (incomingAmt <= usage)
    {
        double newDist = b->getWaterMeterBox() + incomingAmt;
        b->setWaterMeterBox(newDist);
        std::cout << "Distributed water : " << incomingAmt << " to " << b->getName() << std::endl;
        this->budget -= 300;
    }
    else
    {
        std::cout << "Failed to distribute " << incomingAmt << " because the water amount exceeds the meterBox capacity for " << b->getName() << std::endl;
        cout << "The current water usage for " << b->getName() << " is only " << usage << endl;
    }
}

double WaterSupply::calculateWaterUsage()
{
    double totalUsage = 0.0;
    for (Building *building : buildings)
    {
        totalUsage += building->getWaterUsage(); // Assume this method exists
    }
    return totalUsage;
}

void WaterSupply::waterShutDown()
{
    for (Building *building : buildings)
    {
        building->waterCut(); // Assuming Building has this method
    }
    cout << "Water supply has been shut down for all buildings." << endl;
}

void WaterSupply::increaseWaterCapacity()
{
    waterCapacity *= 1.5; // Increase capacity by 50%, might change as citizens  demand more
    cout << "Increased water storage capacity. New capacity: " << waterCapacity << "." << endl;
}

double WaterSupply::getWaterCapacity()
{
    return waterCapacity;
}

double WaterSupply::getBudget()
{
    return 100000;
}
bool WaterSupply::handleRequest(Request &req)
{

    if (this->budget == 0)
    {
        this->budget = 1000000;
    }
    if ((req.getType() == "water" || req.getType() == "WATER" || req.getType() == "Water") && this->budget >= 1000)
    {
        if (req.getAmount() <= waterCapacity)
        {
            std::cout << "WaterSupply handling request for " << req.getAmount()
                      << " units of power for " << req.getBuilding()->getName() << std::endl;
            distributeWaterToBuilding(req.getBuilding(), req.getAmount());
            waterCapacity -= req.getAmount();
            return true;
        }
        else
        {
            std::cout << "WaterSupply: Insufficient water capacity.\n";
            return false;
        }
    }
    else if (successor)
    {
        if (successor != NULL)
        {
            return successor->handleRequest(req);
        }
    }
    else
    {
        return false;
    }
}
