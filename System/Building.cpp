// Class implementation of Factory Method - Product participant

#include "Building.h"
#include "Citizen.h"
#include <algorithm>  // For std::find

Building::Building()
    : name("Building Name"), maxCapacity(100), electricityMeterBox(0.0),
      waterMeterBox(0.0), electricityUsage(0.0), waterUsage(0.0),
      wasteProduction(0.0), width(1), length(1), priceTag(0.0),
      netWorth(0.0), waterSupply(true), powerSupply(true), type("Building") {}

/**
 * @brief Adds a tenant to the building.
 * 
 * @param tenant Pointer to the Citizen to be added.
 * @return true if the tenant was successfully added, false if capacity is reached.
 */
bool Building::addTenant(Citizen* tenant) {
    if (tenants.size() < maxCapacity) {
        tenants.push_back(tenant);
        tenant->setCurrentLocation(this) ;
        return true;
    }
    return false;
}

/**
 * @brief Removes a tenant from the building.
 * 
 * @param tenant Pointer to the Citizen to be removed.
 * @return true if the tenant was successfully removed, false if the tenant was not found.
 */
bool Building::removeTenant(Citizen* tenant) {
    auto it = std::find(tenants.begin(), tenants.end(), tenant);
    if (it != tenants.end()) {
        tenants.erase(it);
        return true;
        std::cout<<"Removed successfully \n";
    }
    return false;
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

    std::cout << std::endl;
    std::cout << "Tenants: \n";
    for (const auto& tenant : tenants) {
         tenant->display();  // Displays tenant pointers
    }
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
double Building::getWasteAmount() const { return wasteProduction; }

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
    if (amount <= 0 || waterUsage < amount) {
        std::cout << "Water supply cut off due to zero or negative usage." << std::endl;
        return; // Cannot consume negative or more than available
    }
    waterUsage -= amount; // Decrease usage
    std::cout << "Consumed " << amount << " liters of water." << std::endl;
}

/**
 * @brief Consumes a specified amount of electricity.
 * 
 * @param amount Amount of electricity consumed (in kWh).
 */
void Building::consumeElectricity(double amount) {
    if (amount <= 0 || electricityUsage < amount) {
        std::cout << "Power supply cut off due to zero or negative usage." << std::endl;
        return; // Cannot consume negative or more than available
    }
    electricityUsage -= amount; // Decrease usage
    std::cout << "Consumed " << amount << " kWh of electricity." << std::endl;
}

/**
 * @brief Requests electricity usage.
 * 
 * @param requestedElectricity Amount of electricity requested (in kWh).
 */
void Building::requestElectricity(double requestedElectricity) {
    std::cout << "Requesting " << requestedElectricity << " kWh of electricity." << std::endl;
    if (requestedElectricity <= 0) {
        std::cout << "Power supply cut off due to zero or negative usage." << std::endl;
        return; // Return early if the request is invalid
    }
    electricityUsage += requestedElectricity; // Update electricity usage
    electricityMeterBox += requestedElectricity; // Update meter box reading
}

/**
 * @brief Requests water usage.
 * 
 * @param requestedWater Amount of water requested (in liters).
 */
void Building::requestWater(double requestedWater) {
    std::cout << "Requesting " << requestedWater << " liters of water." << std::endl;
    if (requestedWater <= 0) {
        std::cout << "Water supply cut off due to zero or negative usage." << std::endl;
        return; // Return early if the request is invalid
    }
    waterUsage += requestedWater; // Update water usage
    waterMeterBox += requestedWater; // Update meter box reading
}

/**
 * @brief Cuts off the water supply to the building.
 */
void Building::waterCut() {
    waterSupply = false;
    std::cout << "Water supply cut off." << std::endl;
}

/**
 * @brief Cuts off the power supply to the building.
 */
void Building::powerCut() {
    powerSupply = false;
    std::cout << "Power supply cut off." << std::endl;
}

/**
 * @brief Clears the waste produced by the building.
 */
void Building::clearWaste() {
    wasteProduction = 0.0; // Reset waste production
    std::cout << "Waste cleared from the building." << std::endl;
}
