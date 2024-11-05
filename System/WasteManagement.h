/**
 * @file WasteManagement.h
 * @author MissNcube
 * @brief Header file for the WasteManagement class, responsible for handling waste collection, disposal, and recycling in the city.
 *
 *  Design Pattern used : Chain of responsibility
 *  Handler : DepartmentUtilities
 *  ConcreteHandler1 : PowerSupply
 *  ConcreteHandler2 : waterSupply
 *  ConcreteHandler3 : WasteManagement
 */

#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "DeptOfUtilities.h"
#include "Building.h"
#include "Request.h"

/**
 * @class WasteManagement
 * @brief Manages the waste collection, disposal, and recycling systems for the city.
 * Inherits from the DepartmentUtilities class.
 */
class WasteManagement : public DeptOfUtilities
{
private:
    double wasteCapacity;       /**< Total capacity for handling waste in the city. */
    double replenishedCapacity; /**< Total capacity for replenishing waste in the city after disposal. */

public:
    /**
     * @brief Constructor for WasteManagement.
     * @param name The name of the department.
     * @param budget The budget allocated to the waste management department.
     * @param capacity The initial waste handling capacity available for the department.
     */
    WasteManagement(double budget, double capacity);

    /**
     * @brief Destructor for WasteManagement.
     * Cleans up the buildings vector if the WasteManagement class owns the Building instances.
     */
    ~WasteManagement(); // Destructor declaration

    /**
     * @brief Collects waste from various parts of the city.
     */
    void collectWaste();

    /**
     * @brief Collects waste from a specific building.
     */
    void collectWasteFromBuilding(Building *building);

    /**
     * @brief Collects waste from a specific building and its amount.
     */
    void CollectWasteFromBuilding(Building *building, double incomingAmt);

    /**
     * @brief Disposes of waste in landfills or dump locations.
     */
    void disposeWaste();

    /**
     * @brief Calculates the current amount of waste being processed.
     * @return The amount of waste being processed.
     */
    double calculateWasteProcessing();

    /**
     * @brief Expands the waste handling capacity to accommodate city growth.
     */
    void expandWasteCapacity();

    /**
     * @brief Fetch the current capacity of the waste management class.
     * @return current capacity of the waste management , how much it can handle and proccess at a time.
     */
    double getWasteCapacity();

    /**
     * @brief Fetch the current budget of the waste management class.
     * @return The budget  allocated to the waste management department.
     */
    double getWasteManagementBudget();

    /**
     * @brief set the current budget of the waste management class.
     */
    void setWasteCapacity(double amt);

    /**
     * @brief the handleRequest() function is the core method responsible for either processing
     * the request or passing it along the chain to the next handler. WasteManagement
     * checks if it can handle the request, if not, WasteManagement will pass it on
     * to the next concreteHandler.
     */
    bool handleRequest(Request &req) override;
};

#endif // WASTEMANAGEMENT_H