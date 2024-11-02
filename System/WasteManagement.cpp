#include "WasteManagement.h"

WasteManagement::WasteManagement(double budget, double capacity)
    : DeptOfUtilities(budget), wasteCapacity(capacity)
{
    cout << "Waste Management Department created  with capacity : " << capacity << endl
         << endl;
}

void WasteManagement::addBuilding(Building *building)
{
    if (building) // building to add.
    {
        buildings.push_back(building); // Adds a building to the waste management system.
        cout << "Building has been added, waste management will be handled " << endl
             << endl;
    }
}

WasteManagement::~WasteManagement()
{
    buildings.clear(); // Clear the vector
}

void WasteManagement::collectWaste()
{
    for (Building *building : buildings)
    {
        double wasteAmount = building->getWasteAmount(); // Building has this method
        if (wasteCapacity >= wasteAmount)
        {
            building->clearWaste(); // building has this method
            wasteCapacity -= wasteAmount;
            cout << "Collected " << wasteAmount << " units of waste from " << building->getName() << endl;
        }
        else
        {
            cout << "Not enough waste capacity to collect waste from " << building->getName() << endl;
        }
    }
}

double WasteManagement::getWasteCapacity()
{
    return wasteCapacity;
}

double WasteManagement::getWasteManagementBudget()
{
    return budget;
}

void WasteManagement::disposeWaste()
{
    cout << "Waste has been disposed of in designated landfill sites." << endl;
}

double WasteManagement::calculateWasteProcessing() // Calculates the current amount of waste being processed.
{
    double totalWaste = 0.0;
    for (Building *building : buildings)
    {
        totalWaste += building->getWasteAmount(); // Assuming Building has this method
    }
    return totalWaste; // The amount of waste being processed.
}

void WasteManagement::expandWasteCapacity()
{
    wasteCapacity += 500; // Example: Increase waste capacity by 500 units to accommodate city growth.
    cout << "Expanded waste capacity. New capacity: " << wasteCapacity << " units." << endl;
}

bool WasteManagement::handleRequest(Request &req)
{
    if ((req.getType() == "waste" || req.getType() == "WASTE") && this->budget >= 10000)
    {
        double wasteAmount = req.getAmount();
        if (wasteCapacity >= wasteAmount)
        {
            collectWaste();
            std::cout << "WasteManagement: Collected and processed " << wasteAmount << " units of waste.\n";
            this->budget -= 10000;
            return true;
        }
        else
        {
            std::cout << "WasteManagement: Insufficient waste handling capacity.\n";
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