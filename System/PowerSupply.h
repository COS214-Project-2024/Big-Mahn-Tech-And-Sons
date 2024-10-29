/**
 * @file PowerSupply.h
 * @author MissNcube
 * @brief Header file for the PowerSupply class, responsible for managing electricity generation and distribution in the city.
 *  
 *  Design Pattern used : Chain of responsibility
 *  Handler : DepartmentUtilities
 *  ConcreteHandler1 : PowerSupply
 *  ConcreteHandler2 : waterSupply
 *  ConcreteHandler3 : WasteManagement
 */

#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H

#include "DeptOfUtilities.h"
#include "Building.h" // Make sure to include the Building class header
#include "Power.h"
#include "Request.h"

/**
 * @class PowerSupply
 * @brief Manages the electricity generation and distribution system for the city.
 * Inherits from the DepartmentUtilities class.
 */
class PowerSupply : public DeptOfUtilities {
private:
    double powerCapacity; /**< Total electricity capacity available for distribution. */
    vector<Building*> buildings;  /**vector to store building  */
    Power* powerResource;   /**< pointer to  the power resource. */

public:
    /**
     * @brief Constructor for PowerSupply.
     * @param name The name of the department.
     * @param budget The budget allocated to the power supply department.
     * @param capacity The initial power capacity available for the department.
     */
    PowerSupply(string name, double budget, double capacity,  Power* powerResource);

    /**
     * @brief Distributes electricity across various sectors in the city.
     */
    void distributePower();

    /**
     * @brief Calculates the current power usage based on consumption rates.
     * @return The amount of electricity consumed.
     */
    double calculatePowerUsage();

    /**
     * @brief Shuts down power generation for maintenance or emergency purposes.
     */
    void powerShutDown();

    /**
     * @brief Increases the electricity generation capacity of the power plants.
     */
    void increasePowerCapacity();


    /**
     * @brief Gets the current total power generation capacity.
     * @return The current power generation capacity available.
     */
    double getPowerCapacity();

    /**
     * @brief the handleRequest() function is the core method responsible for either processing 
     *          the request or passing it along the chain to the next handler. PowerSupply 
     *          checks if it can handle the request, if not, PowerSupply will pass it on
     *          to the next concreteHandler.
     */
    void handleRequest(Request& req);

    /**
    * @brief Adds a building to the water supply system.
    * @param b Pointer to the building to be added.
    */
    void addBuilding(Building * building);
};

#endif  // POWERSUPPLY_H
