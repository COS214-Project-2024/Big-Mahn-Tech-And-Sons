/**
 * @file WaterSupply.h
 * @author MissNcube
 * @brief Header file for the WaterSupply class, responsible for managing water distribution and supply in the city.
 *  
 *  Design Pattern used : Chain of responsibility
 *  Handler : DepartmentUtilities
 *  ConcreteHandler1 : PowerSupply
 *  ConcreteHandler2 : waterSupply
 *  ConcreteHandler3 : WasteManagement
 */

#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "DeptOfUtilities.h"
#include "Building.h"
#include "Water.h"
#include "Request.h"

/**
 * @class WaterSupply
 * @brief Manages the water distribution and supply system for the city.
 * Inherits from the DeptOfUtilities class.
 */
class WaterSupply : public DeptOfUtilities {
private:
    double waterCapacity; /**< Total water capacity available for distribution. */
    vector<Building*> buildings;    /**< Vector to store buildings to be sourced  for water supply. */
    Water* waterResource;   /**< pointer to  the water resource. */

public:
    /**
     * @brief Constructor for WaterSupply.
     * @param name The name of the department.
     * @param budget The budget allocated to the water supply department.
     * @param capacity The initial water capacity available for the department.
     */
    WaterSupply(string name, double budget, double capacity, Water* waterResource);

    /**
     * @brief Destructor for WaterSupply.
     * This destructor releases any dynamically allocated resources.
     */
    ~WaterSupply();

    /**
     * @brief Distributes water to various sectors of the city based on demand.
     */
    void distributeWater();

    /**
     * @brief Calculates the current water usage based on consumption rates.
     * @return The amount of water used.
     */
    double calculateWaterUsage();

    /**
     * @brief Shuts down the water supply for water cut.
     */
    void waterShutDown();


    /**
     * @brief Increases the water storage capacity of the system.
     */
    void increaseWaterCapacity();

    /**
     * @brief Gets the current total water capacity.
     * @return The current water capacity available.
     */
    double getWaterCapacity();

    /**
     * @brief the handleRequest() function is the core method responsible for either processing 
     *          the request or passing it along the chain to the next handler. WaterSupply 
     *          checks if it can handle the request, if not, WaterSupply will pass it on
     *          to the next concreteHandler.
     */
    void handleRequest(Request &req);

    /**
    * @brief Adds a building to the water supply system.
    * @param b Pointer to the building to be added.
    */
    void addBuilding(Building *b);
};

#endif  // WATERSUPPLY_H