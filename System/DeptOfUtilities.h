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
#include <vector>
using namespace std;

class DeptOfPR;
class PowerSupply;
class WaterSupply;
class WasteManagement;
class Request;
class Building;

/**
 * @class DeptOfUtilities
 * @brief Base class for managing various city utility departments like power, water, and waste management.
 */
class DeptOfUtilities
{
private:
    double resourceUsage; /**< The amount of resources used by the department. */
    DeptOfPR *PR;

protected:
    DeptOfUtilities *successor;
    double budget; /**< The budget allocated to the department. */

public:
    // PowerSupply * powerSupply;
    /**
     * @brief Constructor for DeptOfUtilities.
     * @param name The name of the department.
     * @param budget The initial budget allocated to the department.
     */
    DeptOfUtilities(double budget);

    /**
     * @brief Displays the information about the department.
     */
    virtual void displayDepartmentInfo();

    /**
     * @brief the handleRequest() function is the core method responsible for either processing
     *          the request or passing it along the chain to the next handler. It is in the
     *          inherited classes
     */
    virtual bool handleRequest(Request &req) = 0;

    /**
     * @brief if DeptOfUtilities needs to talk to another department for whatever reason
     */
    virtual void requestPR();

    /**
     * @brief increasing usage of resources
     */
    virtual void increaseUsage();

    /**
     * @brief Sets the next department in the chain of responsibility.
     * This method allows the current department to set its successor,enabling the chain of responsibility
     * pattern. When a request cannot be handled by the current department, it will pass the request to
     * the successor department.
     *
     * @param nextDepartment A pointer to the next department that will handle requests if the current department cannot.                      .
     */
    virtual void setSuccessor(DeptOfUtilities *nextDepartment);

    /**
     * @brief Sets the next department in the chain of responsibility.
     *
     * This method allows the current department to set its successor When a request cannot be handled by the current department,
     * it will pass the request to the successor department.
     *
     * @param nextDepartment A pointer to the next department that will handle requests if the
     *                       current department cannot.
     */
    void setPR(DeptOfPR *pr);
};

#endif // DEPTOFUTILITIES_H
