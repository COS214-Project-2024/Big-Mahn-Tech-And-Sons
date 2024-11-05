#include "WaterSupply.h"

WaterSupply::WaterSupply(double budget, double capacity, Water *waterResource)
    : DeptOfUtilities(budget), waterCapacity(capacity), waterResource(waterResource), budg2(budget)
{
    cout << "Water Supply Department created with capacity : " << capacity
         << " kiloLiters and budget: ZAR" << this->budg2 << endl
         << endl;
}

WaterSupply::~WaterSupply()
{
    if (waterResource)
    {
        delete waterResource;
    }
}

void WaterSupply::distributeWater()
{
    this->requestPR("building");
    for (Building *it : buildings)
    {
        if (it != NULL)
        {
            cout << "----------- Next building " << it->getName() << " gets water ----------- " << endl;

            double usage = it->getWaterUsage(); // this method exists in Building
            cout << "Water usage so far is : " << usage << " kiloLiters"<< endl;
            if (waterResource->getWaterAmount() >= usage)
            {
                waterResource->useWater(usage); // Decrease available water

                double newDist = it->getWaterMeterBox() + usage;
                it->setWaterMeterBox(newDist);
                std::cout << "Distributed water : " << it->getWaterUsage() << " kiloLiters to " << it->getName() << std::endl;
            }
            else
            {
                waterResource->useWater(waterResource->getWaterAmount()); // Decrease available water
                std::cout << "Only distributed water : " << waterCapacity << " kiloLiters to " << it->getName() << std::endl;
                waterCapacity = 0;
                this->budget -= 500; // All water is consumed
            }
        }
    }
}

void WaterSupply::distributeWaterToBuilding(Building *b)
{
    double usage = b->getWaterUsage(); // this method exists in Building
    cout << "Water usage for building : " << b->getName() << ": " << usage << " kiloLiters" << endl;
    if (waterResource->getWaterAmount() >= usage)
    {

        waterResource->useWater(usage); // Decrease available water
        double newDist = b->getWaterMeterBox() + usage;
        b->setWaterMeterBox(newDist);
        this->budget -= 300;

        std::cout << "Distributed water : " << b->getWaterUsage() << " kiloLiters to " << b->getName() << std::endl;
    }
    else
    {
        waterResource->useWater(waterResource->getWaterAmount()); // Decrease available water
        std::cout << "Only distributed water : " << waterCapacity << "  kiloLiters to " << b->getName() << std::endl;
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
        std::cout << "Distributed water : " << incomingAmt << " kiloLiters to " << b->getName() << std::endl;
        this->budget -= 300;
    }
    else
    {
        std::cout << "Failed to distribute " << incomingAmt << " kiloLiters because the water amount exceeds the meterBox capacity for " << b->getName() << std::endl;
        cout << "The current water usage for " << b->getName() << " kiloLiters is only " << usage << endl;
    }
}

double WaterSupply::calculateWaterUsage()
{
    double totalUsage = 0.0;
    this->requestPR("building");
    for (Building *it : buildings)
    {
        if (it != NULL)
        {
            totalUsage += it->getWaterUsage(); // Assume this method exists
        }
    }
    return totalUsage;
}

void WaterSupply::waterShutDown()
{
    this->requestPR("building");
    for (Building *it : buildings)
    {
        if (it != NULL)
        {
            it->waterCut(); // Assuming Building has this method
        }
    }
    cout << "Water supply has been shut down for all buildings." << endl;
}

void WaterSupply::increaseWaterCapacity()
{
    waterCapacity *= 1.5; // Increase capacity by 50%, might change as citizens  demand more
    cout << "Increased water storage capacity. New capacity: " << waterCapacity << " kiloLiters." << endl;
}

double WaterSupply::getWaterCapacity()
{
    return waterCapacity;
}

double WaterSupply::getBudget()
{
    return budg2;
}
bool WaterSupply::handleRequest(Request &req)
{
    if ((req.getType() == "water" || req.getType() == "WATER" || req.getType() == "Water") && this->getBudget() >= 1000)
    {
        if (req.getAmount() <= waterCapacity)
        {
            std::cout << "WaterSupply handling request for " << req.getAmount()
                      << " kiloLiters of water for " << req.getBuilding()->getName() << std::endl;
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
