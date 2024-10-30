#include "WasteManagement.h"

WasteManagement::WasteManagement(string name, double budget, double capacity)
    : DeptOfUtilities(name, budget), wasteCapacity(capacity) {}

/**
 * @brief Adds a building to the waste management system.
 * @param building Pointer to the building to add.
 */
void WasteManagement::addBuilding(Building *building)
{
    buildings.push_back(building);
}

/**
 * @brief Collects waste from various parts of the city.
 */
void WasteManagement::collectWaste()
{
    for (Building *building : buildings)
    {
        double wasteAmount = building->getWasteAmount(); // Assuming Building has this method
        if (wasteCapacity >= wasteAmount)
        {
            building->clearWaste(); // Assuming Building has this method
            wasteCapacity -= wasteAmount;
            cout << "Collected " << wasteAmount << " units of waste from " << building->getName() << endl;
        }
        else
        {
            cout << "Not enough waste capacity to collect waste from " << building->getName() << endl;
        }
    }
}

/**
 * @brief Disposes of waste in landfills or dump locations.
 */
void WasteManagement::disposeWaste()
{
    // Logic for disposing of waste
    cout << "Waste has been disposed of in designated landfill sites." << endl;
}

/**
 * @brief Calculates the current amount of waste being processed.
 * @return The amount of waste being processed.
 */
double WasteManagement::calculateWasteProcessing()
{
    double totalWaste = 0.0;
    for (Building *building : buildings)
    {
        totalWaste += building->getWasteAmount(); // Assuming Building has this method
    }
    return totalWaste;
}

/**
 * @brief Expands the waste handling capacity to accommodate city growth.
 */
void WasteManagement::expandWasteCapacity()
{
    wasteCapacity += 500; // Example: Increase waste capacity by 500 units
    cout << "Expanded waste capacity. New capacity: " << wasteCapacity << " units." << endl;
}

/**
 * @brief Gets the current total waste handling capacity.
 * @return The current waste handling capacity available.
 */
double WasteManagement::getWasteCapacity()
{
    return wasteCapacity;
}

/**
 * @brief The handleRequest() function is the core method responsible for either processing
 *          the request or passing it along the chain to the next handler. WasteManagement
 *          checks if it can handle the request, if not, WasteManagement will pass it on
 *          to the next concreteHandler.
 */
void WasteManagement::handleRequest(Request &req)
{
    if (req.getTypeAsString() == "WASTE")
    {
        // Check if WasteManagement can fulfill the waste request
        if (req.getAmount() <= wasteCapacity)
        {
            std::cout << "WasteManagement handling request for " << req.getAmount()
                      << " kg of waste for " << req.getBuilding()->getName() << std::endl;
            wasteCapacity -= req.getAmount();
        }
        else
        {
            std::cout << "Insufficient waste capacity. Forwarding request to successor." << std::endl;
            if (successor)
                successor->handleRequest(req);
        }
    }
    else
    {
        // Forward request if type is not handled by WasteManagement
        if (successor)
            successor->handleRequest(req);
    }
}
