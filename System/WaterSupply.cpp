#include "WaterSupply.h"

WaterSupply::WaterSupply(string name, double budget, double capacity, Water *waterResource)
    : DeptOfUtilities(name, budget), waterCapacity(capacity), waterResource(waterResource) {
    cout<< "Water Supply Department : " << name << " created  with capacity : " << capacity << endl << endl;

    }

/**
 * @brief Adds a building to the water supply system.
 * @param building Pointer to the building to add.
 */
void WaterSupply::addBuilding(Building *building)
{
    if(building)
    { 
        buildings.push_back(building);
        cout << "Building has been added, it will receive water supply"<< endl << endl;
    }
}

/**
 * @brief Destructor for WaterSupply.
 * This destructor releases any dynamically allocated resources.
 */
WaterSupply::~WaterSupply()
{
    // // Delete the water resource if it was dynamically allocated
    // if (waterResource)
    // {
    //     delete waterResource;
    // }

    // // Iterate through the vector of buildings and delete each one if it was dynamically allocated
    // for (Building *building : buildings)
    // {
    //     if (building)
    //     {
    //         delete building;
    //     }
    // }
    // // Clear the vector to ensure it does not hold dangling pointers
    // buildings.clear();
}

/**
 * @brief Distributes water to various sectors of the city based on demand.
 */
void WaterSupply::distributeWater()
{
    for (Building *it : buildings)
    {
        double usage = it->getWaterUsage();
        if (waterResource->getAmount() >= usage)
        {
            it->consumeWater(usage);
            waterResource->use(usage);
        }
        else
        {
            it->consumeWater(waterResource->getAmount());
            waterResource->use(waterResource->getAmount());
            break;
        }
    }
}

/**
 * @brief Calculates the current water usage based on consumption rates.
 * @return The amount of water used.
 */
double WaterSupply::calculateWaterUsage()
{
    double totalUsage = 0.0;
    for (Building *building : buildings)
    {
        totalUsage += building->getWaterUsage(); // Assume this method exists
    }
    return totalUsage;
}

/**
 * @brief Shuts down the water supply for water cut.
 */
void WaterSupply::waterShutDown()
{
    for (Building *building : buildings)
    {
        building->waterCut(); // Assuming Building has this method
    }
    cout << "Water supply has been shut down for all buildings." << endl;
}

/**
 * @brief Increases the water storage capacity of the system.
 */
void WaterSupply::increaseWaterCapacity()
{
    waterCapacity *= 1.5; // Increase capacity by 50%, might change as citizens  demand more
    // TODO : Implement logic to increase storage capacity
    cout << "Increased water storage capacity. New capacity: " << waterCapacity << " 000 liters." << endl;
}

/**
 * @brief Gets the current total water capacity.
 * @return The current water capacity available.
 */
double WaterSupply::getWaterCapacity()
{
    return waterCapacity;
}

string WaterSupply::finalCapacity()
{
    cout << "The current water capacity is " << getWaterCapacity() << " 000 liters " << endl << endl;
}

/**
 * @brief The handleRequest() function is the core method responsible for either processing
 *          the request or passing it along the chain to the next handler. WaterSupply
 *          checks if it can handle the request, if not, WaterSupply will pass it on
 *          to the next concreteHandler.
 */
void WaterSupply::handleRequest(Request &req) {
    if (req.getType() == "WATER" || req.getType() == "water" || req.getType() == "w" || req.getType() == "W") {
        double demand = req.getAmount();
        if (waterCapacity >= demand) {
            distributeWater();
            std::cout << "WaterSupply: Distributed " << demand << " units of water.\n";
        } else {
            std::cout << "WaterSupply: Insufficient water capacity.\n";
        }
    } 
    else if (successor) 
    {
        successor->handleRequest(req);
    } else 
    {
        std::cout << "WaterSupply: Request could not be handled.\n";
    }
}