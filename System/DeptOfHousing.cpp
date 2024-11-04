#include "DeptOfHousing.h"
#include <iostream>

#include "DeptOfHousing.h"
#include <iostream>

/**
 * @brief Constructor for DeptOfHousing.
 * @param initialBudget The initial budget allocated to the department.
 */
DeptOfHousing::DeptOfHousing(double initialBudget) 
    : budget(initialBudget), deptOfPR(nullptr) {}

void DeptOfHousing::setPR(DeptOfPR *PR) {
    this->deptOfPR = PR;
}

/**
 * @brief Helper function to check if the price can be afforded.
 */
bool DeptOfHousing::canAfford(double price) const {
    return price <= budget;
}

/**
 * @brief Generalized building creation method.
 */
void DeptOfHousing::createBuilding(const std::string& type, const std::string& category) {
    try {
        Building* building = nullptr;

        if (canAfford(building->getPriceTag())) {
            buildings.push_back(building);
            budget -= building->getPriceTag();
            std::cout << category << " building (" << type << ") created successfully." << std::endl;
        } else {
            std::cerr << "Insufficient budget to create a " << type << " " << category << " building." << std::endl;
        }

        if (category == "Residential") {
            building = residentialCreator.createBuilding(type);
        } else if (category == "Commercial") {
            building = commercialCreator.createBuilding(type);
        } else if (category == "Industrial") {
            building = industrialCreator.createBuilding(type);
        } else if (category == "Landmark") {
            building = landmarkCreator.createBuilding(type);
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void DeptOfHousing::createResidentialBuilding(const std::string& type) {
    createBuilding(type, "Residential");
}

void DeptOfHousing::createCommercialBuilding(const std::string& type) {
    createBuilding(type, "Commercial");
}

void DeptOfHousing::createIndustrialBuilding(const std::string& type) {
    createBuilding(type, "Industrial");
}

void DeptOfHousing::createLandmarkBuilding(const std::string& type) {
    createBuilding(type, "Landmark");
}

/**
 * @brief Removes a building from the managed list by its name.
 * @param name The name of the building to be removed.
 */
void DeptOfHousing::removeBuildingByName(const std::string& name) {
    int index = findBuildingIndex(name);
    if (index != -1) {
        delete buildings[index]; // Clean up memory before removal
        buildings.erase(buildings.begin() + index);
        std::cout << "Building '" << name << "' removed successfully." << std::endl;
    } else {
        std::cerr << "Building with name '" << name << "' not found." << std::endl;
    }
}

/**
 * @brief Displays all buildings managed by the department.
 */
void DeptOfHousing::displayAllBuildings() const {
    if (buildings.empty()) {
        std::cout << "No buildings are currently managed." << std::endl;
        return;
    }

    std::cout << "List of Managed Buildings:" << std::endl;
    for (const auto& building : buildings) {
        building->displayStats();
        std::cout << "--------------------------" << std::endl;
    }
}

/**
 * @brief Gets the total number of managed buildings.
 */
int DeptOfHousing::getTotalBuildings() const {
    return buildings.size();
}

/**
 * @brief Gets the total price of all buildings.
 */
double DeptOfHousing::getTotalPrice() const {
    double total = 0.0;
    for (const auto& building : buildings) {
        total += building->getPriceTag();
    }
    return total;
}

/**
 * @brief Gets the remaining budget of the department.
 */
double DeptOfHousing::getRemainingBudget() const {
    return budget;
}

/**
 * @brief Finds the index of a building by its name.
 * @param name The name of the building.
 * @return The index of the building or -1 if not found.
 */
int DeptOfHousing::findBuildingIndex(const std::string& name) const {
    for (size_t i = 0; i < buildings.size(); ++i) {
        if (buildings[i]->getName() == name) {
            return i;
        }
    }
    return -1; // Not found
}

/**
 * @brief Lists all buildings with their indices.
 */
void DeptOfHousing::listBuildings() const {
    for (size_t i = 0; i < buildings.size(); ++i) {
        std::cout << "============== BUILDINGS ================\n";
        buildings[i]->displayStats();
    }
}
std::vector<Building *> DeptOfHousing::getBuildings()
{
   return this->buildings;
}
bool DeptOfHousing::requestFunding(double amount) {
    std::cout << "Requesting additional funds from the DeptOfPR...\n";
    if (deptOfPR->notifyTaxman("Housing")) {
        budget += amount;
        std::cout << "Funding request approved. New budget: " << budget << "\n";
        return true;
    } else {
        std::cerr << "Funding request denied.\n";
        return false;
    }
}

std::string DeptOfHousing::getBuildingName(int index) const {
    if (index >= 0 && index < buildings.size()) {
        return buildings[index]->getName();
    }
    return "";
}

/**
 * @brief Repairs buildings of a specified type by cloning and replacing them.
 */
void DeptOfHousing::repairBuilding(const std::string& type) {
    for (size_t i = 0; i < buildings.size(); ++i) {
        if (buildings[i]->getType() == type) {
            Building* repairedBuilding = buildings[i]->repairClone();
            delete buildings[i]; // Clean up the old building
            buildings[i] = repairedBuilding;
            std::cout << type << " building '" << repairedBuilding->getName() << "' has been repaired via cloning.\n";
        }
    }
}

void DeptOfHousing::addBudget(double amount) {
    budget += amount;
    std::cout << "Budget updated. New budget: " << budget << "\n";
}
