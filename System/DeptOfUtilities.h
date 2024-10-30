/**
 * @file DeptOfUtilities.h
 * @brief Header file for the DeptOfUtilities class that manages city utility 
 * departments like power, water, and waste management.
 * 
 * Design Pattern used : Chain of responsibility
 * Handler : DeptOfUtilities
 * ConcreteHandler1 : PowerSupply
 * ConcreteHandler2 : WaterSupply
 * ConcreteHandler3 : WasteManagement
 */

#ifndef DEPTOFUTILITIES_H
#define DEPTOFUTILITIES_H

#include <iostream>
using namespace std;

#include "DeptOfPR.h"
#include "Request.h"
#include "DeptOfPR.h"
#include "Request.h"

/**
 * @class DeptOfUtilities
 * @brief Base class for managing various city utility departments like power, water, and waste management.
 */
class DeptOfUtilities {
private:
    string departmentName; /**< Name of the department (e.g., Power, Water, Waste Management). */
    double resourceUsage;  /**< The amount of resources used by the department. */
    double budget;         /**< The budget allocated to the department. */
    DeptOfPR* PR;

protected:
    DeptOfUtilities* successor;

public:
    /**
     * @brief Constructor for DeptOfUtilities.
     * @param name The name of the department.
     * @param budget The initial budget allocated to the department.
     */
    DeptOfUtilities(string name, double budget);

    /**
     * @brief Displays the information about the department.
     */
    void displayDepartmentInfo();

    /**
     * @brief Requests additional budget allocation from the government.
     */
    void requestBudget();

    /**
     * @brief the handleRequest() function is the core method responsible for either processing 
     *          the request or passing it along the chain to the next handler. It is in the
     *          inherited classes
     */
    virtual void handleRequest(Request &req);

    /**
     * @brief if DeptOfUtilities needs to talk to another department for whatever reason
     */
    void requestPR();

    /**
     * @brief Sets the next department in the chain of responsibility.
     * This method allows the current department to set its successor,enabling the chain of responsibility
     * pattern. When a request cannot be handled by the current department, it will pass the request to
     * the successor department.
     * 
     * @param nextDepartment A pointer to the next department that will handle requests if the current department cannot.                      .
     */
    void setSuccessor(DeptOfUtilities* nextDepartment);

    
    //+++++++++++++++++========== FOR THE EVENT COMMAND +++++++++++++++++++++++++++++++

    /**
     * @brief Initiates power load shedding for the department.
     */
    void initiateLoadshedding();

    /**
     * @brief Restores power or resources after load shedding.
     */
    void restorePower();

    /**
     * @brief Increases the resource usage of the department.
     */
    void increaseUsage();

    /**
     * @brief Reduces the resource usage of the department.
     */
    void reduceUsage();

    /**
     * @brief Tracks the department's resource usage across various sectors or functions.
     */
    void trackUsage();

};

#endif // DEPTOFUTILITIES_H
