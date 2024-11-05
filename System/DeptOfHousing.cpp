#include "DeptOfHousing.h"
#include <iostream>

#include "DeptOfHousing.h"
#include <iostream>

DeptOfHousing::DeptOfHousing(double initialBudget)
    : budget(initialBudget), deptOfPR(nullptr) {}

void DeptOfHousing::setPR(DeptOfPR *PR)
{
    this->deptOfPR = PR;
}

bool DeptOfHousing::canAfford(double price) const
{
    return price <= budget;
}

void DeptOfHousing::createBuilding(const std::string &type, const std::string &category)
{
    try
    {
        // Building* building = nullptr;

        Building *building = NULL;
        if (category == "Residential")
        {
            building = residentialCreator.createBuilding(type);
        }
        else if (category == "Commercial")
        {
            building = commercialCreator.createBuilding(type);
        }
        else if (category == "Industrial")
        {
            building = industrialCreator.createBuilding(type);
        }
        else if (category == "Landmark")
        {
            building = landmarkCreator.createBuilding(type);
        }

        if (building != NULL && canAfford(building->getPriceTag()))
        {
            buildings.push_back(building);
            budget -= building->getPriceTag();
            std::cout << category << " building (" << type << ") created successfully." << std::endl;
        }
        else
        {
            std::cout << "Insufficient budget to create a " << type << " " << category << " building." << std::endl;
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void DeptOfHousing::createResidentialBuilding(const std::string &type)
{
    createBuilding(type, "Residential");
}

void DeptOfHousing::createCommercialBuilding(const std::string &type)
{
    createBuilding(type, "Commercial");
}

void DeptOfHousing::createIndustrialBuilding(const std::string &type)
{
    createBuilding(type, "Industrial");
}

void DeptOfHousing::createLandmarkBuilding(const std::string &type)
{
    createBuilding(type, "Landmark");
}

void DeptOfHousing::removeBuildingByName(const std::string &name)
{
    int index = findBuildingIndex(name);
    if (index != -1)
    {
        delete buildings[index]; // Clean up memory before removal
        buildings.erase(buildings.begin() + index);
        std::cout << "Building '" << name << "' removed successfully." << std::endl;
    }
    else
    {
        std::cout << "Building with name '" << name << "' not found." << std::endl;
    }
}

int DeptOfHousing::getTotalBuildings() const
{
    return buildings.size();
}

double DeptOfHousing::getTotalPrice() const
{
    double total = 0.0;
    for (const auto &building : buildings)
    {
        total += building->getPriceTag();
    }
    return total;
}

double DeptOfHousing::getRemainingBudget() const
{
    return budget;
}

int DeptOfHousing::findBuildingIndex(const std::string &name) const
{
    for (size_t i = 0; i < buildings.size(); ++i)
    {
        if (buildings[i]->getName() == name)
        {
            return i;
        }
    }
    return -1; // Not found
}

void DeptOfHousing::listBuildings() const
{
    for (size_t i = 0; i < buildings.size(); ++i)
    {
        std::cout << i << ": " << buildings[i]->getName() << std::endl;
    }
}

std::vector<Building *> DeptOfHousing::getBuildings()
{
    return this->buildings;
}

bool DeptOfHousing::requestFunding(double amount)
{
    std::cout << "Requesting additional funds from the DeptOfPR...\n";
    if (deptOfPR->notifyTaxman("Housing"))
    {
        budget += amount;
        std::cout << "Funding request approved. New budget: " << budget << "\n";
        return true;
    }
    else
    {
        std::cout << "Funding request denied.\n";
        return false;
    }
}

Building* DeptOfHousing::getBuildingByName(const std::string& name) {
    int index = findBuildingIndex(name);
    if (index != -1) {
       return this->getBuildings().at(index);
    } else {
        std::cout << "Building with name '" << name << "' not found." << std::endl;
        return NULL;
    }


}

void DeptOfHousing::displayAllBuildings() const {
    if (buildings.empty()) {
        std::cout << "No buildings are currently managed." << std::endl;
        return;
    }

    std::cout << "List of Managed Buildings:" << this->getTotalBuildings() << std::endl;
    std::cout << "Budget "  << this->budget << std::endl;
    std::cout << "Price " << this->getTotalPrice() << std::endl;
    for (const auto& building : buildings) {
        building->displayStats();
        std::cout << "--------------------------" << std::endl;
    }
}

Building* DeptOfHousing::getBuildingByName(const std::string& name) {
    int index = findBuildingIndex(name);
    if (index != -1) {
       return this->getBuildings().at(index);
    } else {
        std::cout << "Building with name '" << name << "' not found." << std::endl;
        return NULL;
    }


}

void DeptOfHousing::displayAllBuildings() const {
    if (buildings.empty()) {
        std::cout << "No buildings are currently managed." << std::endl;
        return;
    }

    std::cout << "List of Managed Buildings:" << this->getTotalBuildings() << std::endl;
    std::cout << "Budget "  << this->budget << std::endl;
    std::cout << "Price " << this->getTotalPrice() << std::endl;
    for (const auto& building : buildings) {
        building->displayStats();
        std::cout << "--------------------------" << std::endl;
    }
}

std::string DeptOfHousing::getBuildingName(int index) const
{
    if (index >= 0 && index < buildings.size())
    {
        return buildings[index]->getName();
    }
    return "";
}

void DeptOfHousing::repairBuilding(const std::string &type)
{
    for (size_t i = 0; i < buildings.size(); ++i)
    {
        if (buildings[i]->getType() == type)
        {
            Building *repairedBuilding = buildings[i]->repairClone();
            delete buildings[i]; // Clean up the old building
            buildings[i] = repairedBuilding;
            std::cout << type << " building '" << repairedBuilding->getName() << "' has been repaired via cloning.\n";
        }
    }
}

void DeptOfHousing::addBudget(double amount)
{
    budget += amount;
    std::cout << "Budget updated. New budget: " << budget << "\n";
}