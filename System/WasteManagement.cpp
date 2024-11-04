#include "WasteManagement.h"

WasteManagement::WasteManagement(double budget, double capacity)
    : DeptOfUtilities(budget), wasteCapacity(capacity), replenishedCapacity(capacity)
{
    cout << "Waste Management Department created  with capacity : "
         << capacity << " kilograms and budget: ZAR" << this->budget << endl
         << endl;
}

WasteManagement::~WasteManagement()
{
    buildings.clear(); // Clear the vector
}

void WasteManagement::collectWaste()
{
    this->requestPR("building");
    for (Building *building : buildings)
    {
        cout << "----------- Next building: " << building->getName() << " gets waste removed ----------- " << endl;

        double wasteAmount = building->getWasteAmount(); // Building has this method
        if (wasteCapacity >= wasteAmount)
        {
            building->clearWaste(); // building has this method
            wasteCapacity -= wasteAmount;
            cout << "Cleared " << wasteAmount << " kilograms of waste from " << building->getName() << endl;
            this->budget -= 500;
        }
        else
        {
            cout << "Not enough waste capacity to collect waste from " << building->getName() << endl;
        }
        cout << endl;
    }
}

void WasteManagement::collectWasteFromBuilding(Building *building)
{
    double wasteAmount = building->getWasteAmount(); // Building has this method
    if (wasteCapacity >= wasteAmount)
    {
        building->clearWaste(); // building has this method
        wasteCapacity -= wasteAmount;
        cout << "Cleared " << wasteAmount << " kilograms of waste from: " << building->getName() << endl;
        this->budget -= 250;
    }
    else
    {
        cout << "Not enough waste capacity to collect waste from " << building->getName() << endl;
    }
}

void WasteManagement::CollectWasteFromBuilding(Building *building, double incomingAmt)
{
    if (wasteCapacity >= incomingAmt)
    {
        building->clearWaste(); // building has this method
        wasteCapacity -= incomingAmt;
        cout << "Cleared " << incomingAmt << " kilogrmas of waste from: " << building->getName() << endl;
        this->budget -= 250;
    }
    else
    {
        cout << "Not enough waste capacity to collect waste from " << building->getName() << endl;
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
    this->budget -= 300;
    wasteCapacity = replenishedCapacity;
    cout << "Waste capacity replenished back to: " << wasteCapacity << " kilograms" << endl;
}

double WasteManagement::calculateWasteProcessing() // Calculates the current amount of waste being processed.
{
    double totalWaste = 0.0;
    this->requestPR("building");
    for (Building *building : buildings)
    {
        if (building != NULL)
        {
            totalWaste += building->getWasteProduction(); // Assuming Building has this method
        }
    }
    return totalWaste; // The amount of waste being processed.
}

void WasteManagement::expandWasteCapacity()
{
    wasteCapacity *= 1.5; // Example: Increase waste capacity by 500 units to accommodate city growth.
    cout << "Expanded waste capacity. New capacity: " << wasteCapacity << " kilograms." << endl;
}

bool WasteManagement::handleRequest(Request &req)
{
    if ((req.getType() == "waste" || req.getType() == "WASTE" || req.getType() == "Waste") && this->budget >= 1000)
    {
        double wasteAmount = req.getAmount();
        if (wasteCapacity >= wasteAmount)
        {
            CollectWasteFromBuilding(req.getBuilding(), req.getAmount());
            std::cout << "WasteManagement: Collected and processed " << wasteAmount << " kilograms of waste.\n";
            disposeWaste();
            this->budget -= 200;
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