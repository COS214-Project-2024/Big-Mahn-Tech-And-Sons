#include "DeptOfHousing.h"
#include <iostream>

/**
 * @brief Constructor for DeptOfHousing.
 * @param initialBudget The initial budget allocated to the department.
 */
DeptOfHousing::DeptOfHousing(double initialBudget, DeptOfPR& pr) 
    : budget(initialBudget), deptOfPR(pr) {}

/**
 * @brief Helper function to handle building creation with budget validation.
 */
bool canAfford(double price, double budget) {
    return price <= budget;
}

/**
 * @brief Creates a residential building if within budget.
 */
void DeptOfHousing::createResidentialBuilding(const std::string& type) {
    try {
        auto building = residentialCreator.createBuilding(type);
        if (canAfford(building->getPriceTag(), budget)) {
            buildings.push_back(building);
            budget -= building->getPriceTag();
            std::cout << "Residential building (" << type << ") created successfully." << std::endl;
        } else {
            std::cerr << "Insufficient budget to create a " << type << "." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

/**
 * @brief Creates a commercial building if within budget.
 */
void DeptOfHousing::createCommercialBuilding(const std::string& type) {
    try {
        auto building = commercialCreator.createBuilding(type);
        if (canAfford(building->getPriceTag(), budget)) {
            buildings.push_back(building);
            budget -= building->getPriceTag();
            std::cout << "Commercial building (" << type << ") created successfully." << std::endl;
        } else {
            std::cerr << "Insufficient budget to create a " << type << "." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

/**
 * @brief Creates an industrial building if within budget.
 */
void DeptOfHousing::createIndustrialBuilding(const std::string& type) {
    try {
        auto building = industrialCreator.createBuilding(type);
        if (canAfford(building->getPriceTag(), budget)) {
            buildings.push_back(building);
            budget -= building->getPriceTag();
            std::cout << "Industrial building (" << type << ") created successfully." << std::endl;
        } else {
            std::cerr << "Insufficient budget to create a " << type << "." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

/**
 * @brief Creates a landmark building if within budget.
 */
void DeptOfHousing::createLandmarkBuilding(const std::string& type) {
    try {
        auto building = landmarkCreator.createBuilding(type);
        if (canAfford(building->getPriceTag(), budget)) {
            buildings.push_back(building);
            budget -= building->getPriceTag();
            std::cout << "Landmark building (" << type << ") created successfully." << std::endl;
        } else {
            std::cerr << "Insufficient budget to create a " << type << "." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

/**
 * @brief Finds the index of a building by its name.
 * @param name The name of the building.
 * @return The index of the building or -1 if not found.
 */
int DeptOfHousing::findBuildingIndex(const std::string& name) const {
    for (size_t i = 0; i < buildings.size(); ++i) {
        if (buildings[i]->getName() == name) { // Assume getName() returns the building name
            return i;
        }
    }
    return -1; // Not found
}

std::string  DeptOfHousing::findBuildingIndex(int i) const {
        // Assume getName() returns the building name
    return buildings[i]->getName();
}

/**
 * @brief Removes a building from the managed list by its name.
 * @param name The name of the building to be removed.
 */
void DeptOfHousing::removeBuildingByName(const std::string& name) {
    int index = findBuildingIndex(name);
    if (index != -1) {
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
 * @brief Lists all buildings with their indices.
 */
void DeptOfHousing::listBuildings() const {
    for (size_t i = 0; i < buildings.size(); ++i) {
        std::cout << i << ": " << buildings[i]->getName() << std::endl; // Assume getName() returns the building name
    }
}

bool DeptOfHousing::requestFunding(double amount) {
    // std::cout << "Requesting additional funds from the DeptOfPR...\n";
    // if (deptOfPR.processFundingRequest(amount)) {
    //     budget += amount;
    //     std::cout << "Funding request approved. New budget: " << budget << "\n";
    //     return true;
    // } else {
    //     std::cerr << "Funding request denied.\n";
    //     return false;
    // }

    // call DeptOfPR::notifyTaxman("Housing") to handle this situation

    return true; // Waiting for DeptOfFinance  to implement the funding request logic (Aundrea)
}