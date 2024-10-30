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
#include <algorithm> // For std::find

#include "Element.h"
#include "TaxManager.h"
using namespace std;
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
    string type;

    // Grid coordinates: four (x, y) points representing corners of the building
    std::vector<std::pair<int, int>> gridCoordinates;

public:
    /**
     * @brief Constructor for Building.
     * @param name Name of the building.
     * @param maxCapacity Maximum capacity of the building.
     */
    Building(const std::string& name, int maxCapacity);

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
    virtual void displayStats() const;

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

     /**
     * @brief Gets the type of the building (e.g., Residential, Commercial).
     * 
     * @return A string representing the type of the building.
     */
    string getType() const;

    int getCurrentOccupants() const;

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


    // Getter for net worth
    double getNetWorth() const;

    /**
 * @brief Consumes water based on the specified amount and updates the building's water usage accordingly.
 * 
 * If the supplied amount is greater than or equal to the water requirement, the water usage is fully satisfied.
 * Otherwise, only part of the requirement is met, and the remaining water need is updated.
 * 
 * @param amount The amount of water received by the building.
 */
virtual void consumeWater(double amount);

/**
 * @brief Consumes electricity based on the specified amount and updates the building's electricity usage accordingly.
 * 
 * If the supplied amount is greater than or equal to the electricity requirement, the electricity usage is fully satisfied.
 * Otherwise, only part of the requirement is met, and the remaining electricity need is updated.
 * 
 * @param amount The amount of electricity received by the building.
 */
virtual void consumeElectricity(double amount);

/**
 * @brief Cuts off the water supply to the building.
 * 
 * Disables the building's water supply and sets the water meter to zero.
 */
virtual void waterCut();
/**
 * @brief Cuts off the power supply to the building.
 * 
 * Disables the building's power supply and sets the electricity meter to zero.
 */
virtual void powerCut();

/**
 * @brief Clears the waste produced by the building.
 * 
 * Resets the building's waste production to zero and outputs the amount cleared.
 */
virtual void clearWaste();

/**
 * @brief Retrieves the current amount of waste produced by the building.
 * 
 * @return The amount of waste in tons.
 */
double getWasteAmount();

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


};

#endif // BUILDING_H