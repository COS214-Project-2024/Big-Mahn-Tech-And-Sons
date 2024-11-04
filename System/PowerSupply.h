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
class PowerSupply : public DeptOfUtilities
{
private:
    double powerCapacity;         /**< Total electricity capacity available for distribution. */
    vector<Building *> buildings; /**vector to store building  */
    Power *powerResource;         /**< pointer to  the power resource. */

public:
    /**
     * @brief Constructor for PowerSupply.
     * @param budget The budget allocated to the power supply department.
     * @param capacity The initial power capacity available for the department.
     */
    PowerSupply(double budget, double capacity, Power *powerResource);

    /**
     * @brief Destructor for the PowerSupply class.
     *
     * This destructor cleans up any resources allocated by the PowerSupply instance.
     */
    ~PowerSupply();

    /**
     * @brief Retrieves the current budget of the PowerSupply.
     *
     * @return The current budget as a double value.
     */
    double getBudget();

    /**
     * @brief Distributes electricity across various sectors in the city.
     */
    void distributePower();

    /**
     * @brief Distributes electricity to a specific building.
     */
    void distributePowerToBuilding(Building *b);

    /**
     * @brief Distributes power to a specified building.
     *
     * This method attempts to distribute a specified amount of power to the given building.
     * If the incoming amount exceeds the building's capacity, it will not distribute the excess.
     *
     * @param b Pointer to the Building object to which power will be distributed.
     * @param incomingAmt The amount of power to be distributed to the building.
     */
    void DistributePowerToBuilding(Building *b, double incomingAmt);

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
    bool handleRequest(Request &req) override;

    /**
     * @brief Adds a building to the water supply system.
     * @param b Pointer to the building to be added.
     */
    void addBuilding(Building *building);
};

#endif // POWERSUPPLY_H