#include "Building.h"
#include "Citizen.h"
#include "TaxManager.h"

/**
 * @brief Construct a new Building object.
 * 
 * @param name Name of the building.
 * @param maxCapacity Maximum number of tenants the building can accommodate.
 */
Building::Building(const std::string& name, int maxCapacity)
    : name(name), maxCapacity(maxCapacity), electricityMeterBox(0.0),
      waterMeterBox(0.0), electricityUsage(0.0), waterUsage(0.0),
      wasteProduction(0.0), width(1), length(1), priceTag(0.0),
      netWorth(0.0), waterSupply(true), powerSupply(true) {}
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
void Building::requestElectricity(double requestedElectricity) {
    // electricityUsage += usage;
      powerSupply = true;
   double got = electricityMeterBox + requestedElectricity;
    setWaterMeterBox(got);

}

/**
 * @brief Requests water for the building.
 * 
 * @param usage Amount of water requested (in liters).
 */
void Building::requestWater(double requestedWater) {
    waterSupply = true;
    double got = waterMeterBox + requestedWater;
    setWaterMeterBox(got);
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
    double newA = waterUsage + amount  ;
    double meterA = waterMeterBox - newA;

  if (newA > waterMeterBox) {
        std::cout << "Building " << name << " does not have enough electricity that is requested , try buying units or using less water , current meter box amount:  "<<waterMeterBox<<" attempted to use" <<newA  << std::endl;
        waterSupply = true;
    } 
    else if ( meterA <= 0 && meterA >=-10 )
    {
        setWaterUsage(newA);
        setWaterMeterBox(meterA);
        std::cout<<"Building: "<<name<<" water usage is now went is very low! , please buy more units the current units is : "<<waterMeterBox <<"will not be able to comsume more water! , you recently just used: "<<waterUsage <<"\n";
          waterSupply = true;
    }
    else
    {
        setWaterUsage(newA);
        setWaterMeterBox(meterA);
        std::cout << "Building: " << name << "has used: "<<newA<<" and is now left with: "<<meterA<<std::endl;
          waterSupply = true;
    }
}

/**
 * @brief Consumes a specified amount of electricity.
 * 
 * @param amount Amount of electricity consumed (in kWh).
 */
void Building::consumeElectricity(double amount) {
    double newA = electricityUsage + amount;
    double meterA = electricityMeterBox - newA;

   if (newA  > electricityUsage) 
     {
        std::cout << "Building " << name << " does not have enough electricity that is requested , try buying units or using less electricity , current meter box amount:  "<<electricityMeterBox<<" attempted to use" <<newA  << std::endl;
        powerSupply = true;
    } 
    else if( meterA <= 0  && meterA >= -10)
    {
        std::cout<<"Building: "<<name<<" now has Low Credits! , please buy more units the current units is : ";
         setElectricityMeterBox( meterA );
         setElectricityUsage(newA);
         std::cout<< electricityMeterBox <<" however , will not be able to comsume more electricity! current units is : "<<electricityMeterBox <<"will not be able to comsume more electricity! , you recently just used: "<<electricityUsage <<"\n";
          powerSupply = true;
    }  else
    {
       setElectricityUsage(newA);
       setElectricityMeterBox(meterA);

        std::cout << "Building: " << name << "has used: "<<electricityUsage<<" and is now left with: "<<electricityMeterBox<<std::endl;
        powerSupply = true;
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
