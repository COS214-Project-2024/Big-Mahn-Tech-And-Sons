/**
 * @file Government.h
 * @brief Declaration of the Government class acting as the facade.
 */

#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <vector>
#include "Citizen.h"
#include "EventsCommand.h"

class DeptOfFinance;
class DeptOfHousing;
class DeptOfPR;
#include <iostream>


using namespace std;

/**
 * @class Government
 * @brief Acts as the Government facade, providing simplified access to various departments.
 *
 * Currently focuses on the Department of Transportation.
 */
class Government {
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
    void stopSim();



 private:
    ///< @brief Departments managed by the Government facade

    DeptOfPR* PR;
    // WaterSupply* waterS;
    // PowerSupply* powerS;
    // WasteManagement* wasteS;
    DeptOfFinance* finance;
    DeptOfHousing* housing;
    string commercialTypes[4] = {"Shop", "Office", "School", "Hospital"};
   string residentialTypes[3] = {"House", "Apartment", "Estate"};
   string industrialTypes[4] = {"Warehouse", "Factory", "Airport", "TrainStation"};
   string landmarkTypes[3] = {"Park", "Monument", "Museum"};

    DeptOfTransportation* transport;

    EventsCommand* pandemic;
    EventsCommand* economicDownturn;
    EventsCommand* naturalDisaster;
    EventsCommand* loadsheding;
    EventsCommand* festive;
    EventsCommand* babyBoom;
    EventsCommand* increaseEconomy;

    // Simulation status
    bool simulationIsActive;

    // Handles random events affecting the city
    //EventsCommand eventsCommand;

    void simulateYear();

    // Simulation methods
    void handleCitizenNeeds();
    void addNewCitizens();
    void displayCity();
    void addRoad();
    void addBuilding();
    void manageResources();
    void evaluatePolicies();
    void triggerRandomEvents();


};

#endif