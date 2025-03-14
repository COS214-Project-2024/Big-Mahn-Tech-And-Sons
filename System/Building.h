/**
 * @file Building.h
 * @brief Declaration of the Building class.
 */

#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>
#include <iostream>  // For std::cout
#include <utility>   // For std::pair
#include <algorithm> // For std::find

#include "Element.h"

class Citizen; ///< Forward declaration of Citizen class
class TaxManager;
class DeptOfPR;

/**
 * @class Building
 * @brief Base class for all types of buildings.
 *
 * This class provides the common attributes and functionalities for all building types,
 * including managing tenants, utilities, and grid placement.
 */
class Building : public Element
{
class Building : public Element
{

protected:
    std::string name;                                 ///< Name of the building
    int maxCapacity;                                  ///< Maximum capacity of people in the building
    double electricityMeterBox;                       ///< Electric meter reading
    double waterMeterBox;                             ///< Water meter reading
    double electricityUsage;                          ///< Total electricity usage
    double waterUsage;                                ///< Total water usage
    double wasteProduction;                           ///< Total waste produced
    std::vector<Citizen *> tenants;                   ///< Vector to store tenants or workers
    int width;                                        ///< Width of the building for grid placement
    int length;                                       ///< Length of the building for grid placement
    double priceTag;                                  ///< Price tag of the building
    double netWorth;                                  ///< Net worth of the building
    bool waterSupply;                                 ///< Water supply status
    bool powerSupply;                                 ///< Power supply status
    std::vector<std::pair<int, int>> gridCoordinates; ///< Grid coordinates
    std::string type;                                 ///< Type of Building
    DeptOfPR *PR;                                     ///< Reference to the government’s DeptOfPR
    double citizenTax;                                ///< Tax rate for citizens
    double businessTax;                               ///< Tax rate for businesses
protected:
    std::string name;                                 ///< Name of the building
    int maxCapacity;                                  ///< Maximum capacity of people in the building
    double electricityMeterBox;                       ///< Electric meter reading
    double waterMeterBox;                             ///< Water meter reading
    double electricityUsage;                          ///< Total electricity usage
    double waterUsage;                                ///< Total water usage
    double wasteProduction;                           ///< Total waste produced
    std::vector<Citizen *> tenants;                   ///< Vector to store tenants or workers
    int width;                                        ///< Width of the building for grid placement
    int length;                                       ///< Length of the building for grid placement
    double priceTag;                                  ///< Price tag of the building
    double netWorth;                                  ///< Net worth of the building
    bool waterSupply;                                 ///< Water supply status
    bool powerSupply;                                 ///< Power supply status
    std::vector<std::pair<int, int>> gridCoordinates; ///< Grid coordinates
    std::string type;                                 ///< Type of Building
    DeptOfPR *PR;                                     ///< Reference to the government’s DeptOfPR
    double citizenTax;                                ///< Tax rate for citizens
    double businessTax;                               ///< Tax rate for businesses

public:
    /**
     * @brief Default constructor.
     */
    Building();

    /**
     * @brief Virtual destructor to allow polymorphism.
     */
    virtual ~Building() = default;

    /**
     * @brief Adds a tenant to the building.
     * @param tenant A pointer to the Citizen to be added as a tenant.
     * @return True if the tenant was added, false if capacity is full.
     */
    bool addTenant(Citizen *tenant);

    std::vector<Citizen *> getOccupants();

    /**
     * @brief Removes a tenant from the building.
     * @param tenant A pointer to the Citizen to be removed.
     * @return True if the tenant was removed, false otherwise.
     */
    bool removeTenant(Citizen *tenant);

    /**
     * @brief Requests electricity usage.
     * @param requestedElectricity Amount of electricity requested.
     */
    void requestElectricity(double requestedElectricity);

    /**
     * @brief Requests water usage.
     * @param requestedWater Amount of water requested.
     */
    void requestWater(double requestedWater);

    /**
     * @brief Gets the grid coordinates of the building.
     * @return A vector of coordinate pairs.
     */
    std::vector<std::pair<int, int>> getGridCoordinates() const;

    /**
     * @brief Sets the grid coordinates of the building.
     * @param coords A vector of coordinate pairs to be set.
     */
    void setCoordinates(const std::vector<std::pair<int, int>> &coords);

    /**
     * @brief Accepts a visitor for the visitor pattern.
     * @param visitor A pointer to the TaxManager visitor.
     */
    virtual void accept(TaxManager *visitor) = 0;

    /**
     * @brief Calculates the tax for the building.
     * @return The calculated tax amount.
     */
    virtual double calculateTax() const = 0;

    /**
     * @brief Displays the statistics of the building.
     */
    virtual void displayStats() const;

    /**
     * @brief Notifies the DeptOfPR about an update or request.
     */
    void notifyPR();

    // Getters

    std::string getName() const;
    int getMaxCapacity() const;
    double getElectricityMeterBox() const;
    double getWaterMeterBox() const;
    double getElectricityUsage() const;
    double getWaterUsage() const;
    double getWasteProduction() const;
    const std::vector<Citizen *> &getTenants() const;
    int getWidth() const;
    int getLength() const;
    double getPriceTag() const;
    double getNetWorth() const;
    int getCurrentOccupants() const;
    std::string getType() const;
    double getWasteAmount() const;
    double getCitizenTax() const;
    double getBusinessTax() const;

    // Setters

    void setName(const std::string &name);
    void setMaxCapacity(int capacity);
    void setElectricityMeterBox(double reading);
    void setWaterMeterBox(double reading);
    void setElectricityUsage(double usage);
    void setWaterUsage(double usage);
    void setWaste(double waste);
    void setWidth(int width);
    void setLength(int length);
    void setCitizenTax(double taxRate);
    void setBusinessTax(double taxRate);

    /**
     * @brief Consumes water based on the specified amount.
     * @param amount The amount of water to consume.
     */
    virtual void consumeWater(double amount);

    /**
     * @brief Consumes electricity based on the specified amount.
     * @param amount The amount of electricity to consume.
     */
    virtual void consumeElectricity(double amount);

    /**
     * @brief Cuts off the water supply to the building.
     */
    virtual void waterCut();

    /**
     * @brief Cuts off the power supply to the building.
     */
    virtual void powerCut();

    /**
     * @brief Clears the waste produced by the building.
     */
    virtual void clearWaste();

    /**
     * @brief Creates a clone of the building for repair purposes.
     * @return A pointer to a new Building object that is a clone of this building.
     */
    virtual Building *repairClone() const = 0;
    // Setters

    void setName(const std::string &name);
    void setMaxCapacity(int capacity);
    void setElectricityMeterBox(double reading);
    void setWaterMeterBox(double reading);
    void setElectricityUsage(double usage);
    void setWaterUsage(double usage);
    void setWaste(double waste);
    void setWidth(int width);
    void setLength(int length);
    void setCitizenTax(double taxRate);
    void setBusinessTax(double taxRate);

    /**
     * @brief Consumes water based on the specified amount.
     * @param amount The amount of water to consume.
     */
    virtual void consumeWater(double amount);

    /**
     * @brief Consumes electricity based on the specified amount.
     * @param amount The amount of electricity to consume.
     */
    virtual void consumeElectricity(double amount);

    /**
     * @brief Cuts off the water supply to the building.
     */
    virtual void waterCut();

    /**
     * @brief Cuts off the power supply to the building.
     */
    virtual void powerCut();

    /**
     * @brief Clears the waste produced by the building.
     */
    virtual void clearWaste();

    /**
     * @brief Creates a clone of the building for repair purposes.
     * @return A pointer to a new Building object that is a clone of this building.
     */
    virtual Building *repairClone() const = 0;
};

#endif // BUILDING_H