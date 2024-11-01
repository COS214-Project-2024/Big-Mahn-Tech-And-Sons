#include "Building.h"
#include "Citizen.h"
#include <algorithm>  // For std::find
#include <iostream>   // For std::cout

/**
 * @brief Construct a new Building object.
 * 
 * @param name Name of the building.
 * @param maxCapacity Maximum number of tenants the building can accommodate.
 */
Building::Building()
    : name("Building Name"), maxCapacity(100), electricityMeterBox(0.0),
      waterMeterBox(0.0), electricityUsage(0.0), waterUsage(0.0),
      wasteProduction(0.0), width(1), length(1), priceTag(0.0),
      netWorth(0.0), waterSupply(true), powerSupply(true), type("Building") {}

/**
 * @brief Adds a tenant to the building.
 * 
 * @param tenant Pointer to the Citizen to be added.
 * @return true if the tenant was successfully added, false otherwise.
 */
bool Building::addTenant(Citizen* tenant) {
    if (tenants.size() < maxCapacity) {
        tenants.push_back(tenant);
        return true;
    }
    return false;
}

/**
 * @brief Removes a tenant from the building.
 * 
 * @param tenant Pointer to the Citizen to be removed.
 * @return true if the tenant was successfully removed, false otherwise.
 */
bool Building::removeTenant(Citizen* tenant) {
    auto it = std::find(tenants.begin(), tenants.end(), tenant);
    if (it != tenants.end()) {
        tenants.erase(it);
        return true;
    }
    return false;
}

/**
 * @brief Requests electricity for the building.
 * 
 * @param usage Amount of electricity requested (in kWh).
 */
void Building::requestElectricity(double usage) {
    // electricityUsage += usage;
}

/**
 * @brief Requests water for the building.
 * 
 * @param usage Amount of water requested (in liters).
 */
void Building::requestWater(double usage) {
    // waterUsage += usage;
}

/**
 * @brief Gets the grid coordinates of the building.
 * 
 * @return A vector of grid coordinate pairs (x, y).
 */
std::vector<std::pair<int, int>> Building::getGridCoordinates() const {
    return gridCoordinates;
}

/**
 * @brief Sets the grid coordinates of the building.
 * 
 * @param coords Vector of coordinate pairs to set.
 */
void Building::setCoordinates(const std::vector<std::pair<int, int>>& coords) {
    gridCoordinates = coords;
}

/**
 * @brief Displays the building's statistics.
 */
void Building::displayStats() const {
    std::cout << "Building Name: " << name << std::endl;
    std::cout << "Max Capacity: " << maxCapacity << std::endl;
    std::cout << "Electricity Meter: " << electricityMeterBox << " kWh" << std::endl;
    std::cout << "Water Meter: " << waterMeterBox << " L" << std::endl;
    std::cout << "Electricity Usage: " << electricityUsage << " kWh" << std::endl;
    std::cout << "Water Usage: " << waterUsage << " L" << std::endl;
    std::cout << "Waste Produced: " << wasteProduction << " kg" << std::endl;
    std::cout << "Dimensions (WxL): " << width << " x " << length << " units" << std::endl;

    std::cout << "Tenants: ";
    for (const auto& tenant : tenants) {
        std::cout << tenant << " ";  // Displays tenant pointers
    }
    std::cout << std::endl;
}

// Getters

std::string Building::getName() const { return name; }
int Building::getMaxCapacity() const { return maxCapacity; }
double Building::getElectricityMeterBox() const { return electricityMeterBox; }
double Building::getWaterMeterBox() const { return waterMeterBox; }
double Building::getElectricityUsage() const { return electricityUsage; }
double Building::getWaterUsage() const { return waterUsage; }
double Building::getWasteProduction() const { return wasteProduction; }
const std::vector<Citizen*>& Building::getTenants() const { return tenants; }
int Building::getWidth() const { return width; }
int Building::getLength() const { return length; }
double Building::getPriceTag() const { return priceTag; }
double Building::getNetWorth() const { return netWorth; }
int Building::getCurrentOccupants() const { return tenants.size(); }
std::string Building::getType() const { return type; }
double Building::getWasteAmount() { return wasteProduction; }

// Setters

void Building::setName(const std::string& newName) { name = newName; }
void Building::setMaxCapacity(int capacity) { maxCapacity = capacity; }
void Building::setElectricityMeterBox(double reading) { electricityMeterBox = reading; }
void Building::setWaterMeterBox(double reading) { waterMeterBox = reading; }
void Building::setElectricityUsage(double usage) { electricityUsage = usage; }
void Building::setWaterUsage(double usage) { waterUsage = usage; }
void Building::setWaste(double waste) { wasteProduction = waste; }
void Building::setWidth(int newWidth) { width = newWidth; }
void Building::setLength(int newLength) { length = newLength; }

/**
 * @brief Consumes a specified amount of water.
 * 
 * @param amount Amount of water consumed (in liters).
 */
void Building::consumeWater(double amount) {
    if (amount >= waterUsage) {
        waterUsage = 0;
        std::cout << "Building: " << name << " has received enough water." << std::endl;
    } else {
        waterUsage -= amount;
        std::cout << "Building: " << name << " received partial water. Remaining need: " 
                  << waterUsage << " units." << std::endl;
    }
}

/**
 * @brief Consumes a specified amount of electricity.
 * 
 * @param amount Amount of electricity consumed (in kWh).
 */
void Building::consumeElectricity(double amount) {
    if (amount >= electricityUsage) {
        electricityUsage = 0;
        std::cout << "Building " << name << " has received enough electricity." << std::endl;
    } else {
        electricityUsage -= amount;
        std::cout << "Building " << name << " received partial electricity. Remaining need: " 
                  << electricityUsage << " units." << std::endl;
    }
}

/**
 * @brief Cuts off the building's water supply.
 */
void Building::waterCut() {
    waterSupply = false;
    waterMeterBox = 0.0;
    std::cout << "Water supply cut at " << name << ".\n";
}

/**
 * @brief Cuts off the building's power supply.
 */
void Building::powerCut() {
    powerSupply = false;
    electricityMeterBox = 0.0;
    std::cout << "Power supply cut at " << name << ".\n";
}

/**
 * @brief Clears the building's waste production.
 */
void Building::clearWaste() {
    std::cout << name << " cleared " << wasteProduction << " kg of waste.\n";
    wasteProduction = 0;
}
