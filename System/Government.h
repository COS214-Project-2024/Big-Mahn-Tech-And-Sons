/**
 * @file Government.h
 * @brief Declaration of the Government class acting as the facade.
 */

#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <vector>
#include "Dept.Transportation.h"
#include "DeptOfFinance.h"
#include "DeptOfPR.h"
#include "DeptOfUtilities.h"
#include "DeptOfHousing.h"
#include "Citizen.h"
#include "EventsCommand.h"




/**
 * @class Government
 * @brief Acts as the Government facade, providing simplified access to various departments.
 *
 * Currently focuses on the Department of Transportation.
 */
class Government {
private:

public:
    /**
     * @brief Constructs a new Government object.
     */
    Government();

    /**
     * @brief Destroys the Government object.
     */
    //~Government();
    
    /**
     * @brief Main simulation loop
     * 
     *  */ 
    void runSim();

private:
    ///< @brief Departments managed by the Government facade

    DepartmentOfPR PR;
   // DepartmentUtilities utilities;
    DeptOfFinance finance;
    HousingDept housing;

    // Simulation status
    bool simulationIsActive;

    // Handles random events affecting the city
    EventsCommand eventsCommand;

    // Simulation methods
    void handleCitizenNeeds();
    void manageResources();
    void evaluatePolicies();
    void triggerRandomEvents();

};

#endif 
