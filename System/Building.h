// Class defintion of Factory Method - Product

/**
 * @file Building.h
 * @brief Declaration of the Building class.
 */

#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>
#include <memory>
#include <iostream> // For std::cout
#include <utility>   // For std::pair

#include "Element.h"
#include "TaxManager.h"

class Citizen; ///< Forward declaration of Citizen class

/**
 * @class Building
 * @brief Base class for all types of buildings.
 *
 * This class provides the common attributes and functionalities for all building types,
 * including managing tenants, utilities, and grid placement.
 */

//test

class Building {
protected:
    std::string name;                  ///< Name of the building
    int maxCapacity;                   ///< Maximum capacity of people in the building
    double electricityMeterBox;        ///< Electric meter reading
    double waterMeterBox;              ///< Water meter reading
    double electricityUsage;           ///< Total electricity usage
    double waterUsage;                 ///< Total water usage
    double wasteProduction;            ///< Total waste produced
    std::vector<Citizen*> tenants;     ///< Vector to store tenants or workers
    int width;                         ///< Width of the building for grid placement
    int length;                        ///< Length of the building for grid placement
    double priceTag;                   ///< Price tag of the building
    double netWorth;                   ///< Net worth of the building
    bool waterSupply;                  ///< Water supply status
    bool powerSupply;                  ///< Power supply status

    // Grid coordinates: four (x, y) points representing corners of the building
    std::vector<std::pair<int, int>> gridCoordinates;

public:
    /**
     * @brief Constructor for Building.
     * @param name Name of the building.
     * @param maxCapacity Maximum capacity of the building.
     */
    Building(const std::string& name, int maxCapacity)
        : name(name), maxCapacity(maxCapacity), electricityMeterBox(0.0),
          waterMeterBox(0.0), electricityUsage(0.0), waterUsage(0.0),
          wasteProduction(0.0), width(1), length(1), priceTag(0.0),
          netWorth(0.0), waterSupply(true), powerSupply(true) {}

    // Virtual destructor to allow polymorphism
    virtual ~Building() = default;

    /**
     * @brief Adds a tenant to the building.
     * @param tenant Pointer to the tenant to be added.
     * @return true if the tenant was added successfully, false if capacity is reached.
     */
    bool addTenant(Citizen* tenant);

    /**
     * @brief Removes a tenant from the building.
     * @param tenant Pointer to the tenant to be removed.
     * @return true if the tenant was removed successfully, false if the tenant was not found.
     */
    bool removeTenant(Citizen* tenant);

    /**
     * @brief Requests electricity usage.
     * @param usage Amount of electricity requested.
     */
    void requestElectricity(double usage);

    /**
     * @brief Requests water usage.
     * @param usage Amount of water requested.
     */
    void requestWater(double usage);

    /**
     * @brief Calculates the total resource usage (electricity + water).
     * @return Total resource usage.
     */
    double calculateResourceUsage() const {
        return electricityUsage + waterUsage;
    }

    /**
     * @brief Gets the grid coordinates of the building's corners.
     * @return Vector of 4 (x, y) coordinate pairs.
     */
    std::vector<std::pair<int, int>> getGridCoordinates() const;

    void setCoordinates(const std::vector<std::pair<int, int>>& coords);

    /**
     * @brief Accepts visitors for the visitor pattern.
     * @param visitor A pointer to the visitor that will interact with the building.
     */
    virtual void accept(TaxManager* visitor) = 0;

    /**
     * @brief Displays the statistics of the building.
     *
     * This method prints all the relevant statistics of the building to the console.
     */
    virtual void displayStats() const {
        std::cout << "Building Name: " << name << std::endl;
        std::cout << "Max Capacity: " << maxCapacity << std::endl;
        std::cout << "Electricity Meter: " << electricityMeterBox << " kWh" << std::endl;
        std::cout << "Water Meter: " << waterMeterBox << " L" << std::endl;
        std::cout << "Electricity Usage: " << electricityUsage << " kWh" << std::endl;
        std::cout << "Water Usage: " << waterUsage << " L" << std::endl;
        std::cout << "Waste Produced: " << wasteProduction << " kg" << std::endl;
        std::cout << "Dimensions (WxL): " << width << " x " << length << " units" << std::endl;
        std::cout << "Total Resource Usage: " << calculateResourceUsage() << " units" << std::endl;
        std::cout << "Tenants: ";
        for (const auto& tenant : tenants) {
            std::cout << tenant << " ";
        }
        std::cout << std::endl;
    }

    // Getters
    std::string getName() const;
    int getMaxCapacity() const;
    double getElectricityMeterBox() const;
    double getWaterMeterBox() const;
    double getElectricityUsage() const;
    double getWaterUsage() const;
    double getWasteProduction() const;
    const std::vector<Citizen*>& getTenants() const;
    int getWidth() const;
    int getLength() const;
    double getPriceTag() const;

    int getCurrentOccupants() const {
        return tenants.size();
    }

    // Setters
    void setName(const std::string& name);
    void setMaxCapacity(int capacity);
    void setElectricityMeterBox(double reading);
    void setWaterMeterBox(double reading);
    void setElectricityUsage(double usage);
    void setWaterUsage(double usage);
    void setWaste(double waste);
    void setWidth(int width);
    void setLength(int length);

    // New method to subtract tax from net worth
    void subtractTax(double amount) {
        netWorth -= amount;
    }

    // Getter for net worth
    double getNetWorth() const {
        return netWorth;
    }

    /**
 * @brief Consumes water based on the specified amount and updates the building's water usage accordingly.
 * 
 * If the supplied amount is greater than or equal to the water requirement, the water usage is fully satisfied.
 * Otherwise, only part of the requirement is met, and the remaining water need is updated.
 * 
 * @param amount The amount of water received by the building.
 */
virtual void consumeWater(double amount)
{
    if (amount >= waterUsage) {
        waterUsage = 0; 
        std::cout << "Building: " << name << " has received enough water." << std::endl;
    } else {
        waterUsage -= amount;
        std::cout << "Building: " << name << " received partial water. Remaining need: " << waterUsage << " units." << std::endl;
    }
}

/**
 * @brief Consumes electricity based on the specified amount and updates the building's electricity usage accordingly.
 * 
 * If the supplied amount is greater than or equal to the electricity requirement, the electricity usage is fully satisfied.
 * Otherwise, only part of the requirement is met, and the remaining electricity need is updated.
 * 
 * @param amount The amount of electricity received by the building.
 */
virtual void consumeElectricity(double amount)
{
    if (amount >= electricityUsage) {
        electricityUsage = 0;
        std::cout << "Building " << name << " has received enough electricity." << std::endl;
    } else {
        electricityUsage -= amount;
        std::cout << "Building " << name << " received partial electricity. Remaining need: " << electricityUsage << " units." << std::endl;
    }
}

/**
 * @brief Cuts off the water supply to the building.
 * 
 * Disables the building's water supply and sets the water meter to zero.
 */
virtual void waterCut() {
    waterSupply = false;
    waterMeterBox = 0.0;
    std::cout << "Water supply cut at " << name << ".\n";
}

/**
 * @brief Cuts off the power supply to the building.
 * 
 * Disables the building's power supply and sets the electricity meter to zero.
 */
virtual void powerCut() {
    powerSupply = false;
    electricityMeterBox = 0.0;
    std::cout << "Power supply cut at " << name << ".\n";
}

/**
 * @brief Clears the waste produced by the building.
 * 
 * Resets the building's waste production to zero and outputs the amount cleared.
 */
virtual void clearWaste() {
    std::cout << name << " cleared " << wasteProduction << " kg of waste.\n";
    wasteProduction = 0;
}

/**
 * @brief Retrieves the current amount of waste produced by the building.
 * 
 * @return The amount of waste in tons.
 */
double getWasteAmount()
{
    return wasteProduction;
}

/**
     * @brief Creates a clone of the building.
     * 
     * This method supports the Prototype pattern, creating a new instance of the building
     * with the same properties as the original.
     * 
     * @return A shared pointer to the cloned building instance.
     */
    virtual std::shared_ptr<Building> clone() const = 0;


    /**
     * @brief Repairs the building by restoring its condition.
     * 
     * Each specific building type will implement its own repair logic.
     */
    virtual void repair() = 0;

    /**
     * @brief Gets the type of the building (e.g., Residential, Commercial).
     * 
     * @return A string representing the type of the building.
     */
    virtual std::string getType() const = 0;

};

#endif // BUILDING_H