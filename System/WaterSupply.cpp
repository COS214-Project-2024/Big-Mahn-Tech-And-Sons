#include "WaterSupply.h"

WaterSupply::WaterSupply(double budget, double capacity, Water *waterResource)
    : DeptOfUtilities(budget), waterCapacity(capacity), waterResource(waterResource)
{
    cout << "Water Supply Department created with capacity : " << capacity << endl
         << endl;
}

void WaterSupply::addBuilding(Building *building)
{
    if (building)
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
        double usage = it->getWaterUsage();
        if (waterResource->getWaterAmount() >= usage)
        {
            it->consumeWater(usage);
            waterResource->useWater(usage);
        }
        else
        {
            it->consumeWater(waterResource->getWaterAmount());
            waterResource->useWater(waterResource->getWaterAmount());
            waterCapacity = 0;
            break;
        }
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
    cout << "Increased water storage capacity. New capacity: " << waterCapacity << " 000 liters." << endl;
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
    if ((req.getType() == "water" || req.getType() == "WATER") && this->budget >= 10000)
    {
        if (req.getAmount() <= waterCapacity)
        {
            std::cout << "WaterSupply handling request for " << req.getAmount()
                      << " units of power for " << req.getBuilding()->getName() << std::endl;
            waterCapacity -= req.getAmount();
            this->budget -= 1000;
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
        return successor->handleRequest(req);
    }
    else
    {
        return false;
    }
}
