// Class implementation of Factory Method - Product participant

#include "Building.h"
#include "Citizen.h"
#include "DeptOfPR.h"
#include <algorithm>  // For std::find

Building::Building()
    : name("Building Name"), maxCapacity(100), electricityMeterBox(0.0),
      waterMeterBox(0.0), electricityUsage(0.0), waterUsage(0.0),
      wasteProduction(0.0), width(1), length(1), priceTag(0.0),
      netWorth(0.0), waterSupply(true), powerSupply(true), type("Building"), citizenTax(0.03), businessTax(0.05) {}

/**
 * @brief Adds a tenant to the building.
 * 
 * @param tenant Pointer to the Citizen to be added.
 * @return true if the tenant was successfully added, false if capacity is reached.
 */
bool Building::addTenant(Citizen* tenant) {
    if (tenants.size() < maxCapacity) {
        tenants.push_back(tenant);
        tenant->setCurrent(this);
        tenant->setHome(this);
        return true;
    } else {
        notifyPR();
    }
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

void Building::requestElectricity(double requestedElectricity)
{
}

/**
 * @brief Gets the grid coordinates of the building.
 * 
 * @return A vector of grid coordinate pairs (x, y).
 */
void Building::requestWater(double requestedWater)
{
}
std::vector<std::pair<int, int>> Building::getGridCoordinates() const
{
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
    std::cout << "Electricity Meter: " << electricityMeterBox << " units" << std::endl;
    std::cout << "Water Meter: " << waterMeterBox << " L" << std::endl;
    std::cout << "Electricity Usage: " << electricityUsage << " units" << std::endl;
    std::cout << "Water Usage: " << waterUsage << " kL" << std::endl;
    std::cout << "Waste Produced: " << wasteProduction << " kg" << std::endl;
    std::cout << "Dimensions (WxL): " << width << " x " << length << " units" << std::endl;

    std::cout << std::endl;
    std::cout << "Tenants: \n";
    for (const auto& tenant : tenants) {
         tenant->display();  // Displays tenant pointers
    }
}

void Building::notifyPR()
{
    cout << "Building notifying Department of PR observer\n";
    PR->update(this);
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
double Building::getCitizenTax() const { return citizenTax; }
double Building::getBusinessTax() const { return businessTax; }

// Setters
void Building::setName(const std::string& newName) { name = newName; }
void Building::setMaxCapacity(int capacity) { maxCapacity = capacity; }
void Building::setElectricityMeterBox(double reading) { electricityMeterBox = reading;  cout << "ElectricityMeterBox is now: " <<electricityMeterBox<<endl; }
void Building::setWaterMeterBox(double reading) { waterMeterBox = reading; cout << "WaterMeterBox is now: "<<waterMeterBox<<endl; }
void Building::setElectricityUsage(double usage) { electricityUsage = usage;}
void Building::setWaterUsage(double usage) { waterUsage = usage; }
void Building::setWaste(double waste) { wasteProduction = waste; }
void Building::setWidth(int newWidth) { width = newWidth; }
void Building::setLength(int newLength) { length = newLength; }
void Building::setCitizenTax(double taxRate) { citizenTax = taxRate; }
void Building::setBusinessTax(double taxRate) { businessTax = taxRate; }

/**
 * @brief Consumes a specified amount of water.
 * 
 * @param amount Amount of water consumed (in liters).
 */
void Building::consumeWater(double amount) {
    if(waterMeterBox <= 0) {
        // make request for more water as we are out
        std::cout << "Requesting more water..." << std::endl;
        this->notifyPR();
        return;
    } else if (amount <= 0 || waterMeterBox < amount) {
        std::cout << "Water supply cut off due to zero or negative usage." << std::endl;
        return; // Cannot consume negative or more than available
    }
    setWaterUsage(amount);
    waterMeterBox -= amount; // Decrease usage
    std::cout << "Consumed " << amount << " liters of water." << std::endl;
    setWaterMeterBox(waterMeterBox);

}

/**
 * @brief Consumes a specified amount of electricity.
 * 
 * @param amount Amount of electricity consumed (in kWh).
 */
void Building::consumeElectricity(double amount) {
    if(electricityMeterBox <= 0) {
        // make request for more power as we are out
        std::cout << "Requesting more electricity..." << std::endl;
        this->notifyPR();
    }
    if (amount <= 0 || electricityUsage < amount) {
        std::cout << "Power supply cut off due to zero or negative usage." << std::endl;
        return; // Cannot consume negative or more than available
    }
    setElectricityUsage(amount);
    electricityMeterBox -= amount; // Decrease usage
    std::cout << "Consumed " << amount << " units of electricity." << std::endl;
    setElectricityMeterBox(electricityMeterBox);
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
