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
class DeptOfTransportation; // Forward declaration for the Department of Transportation

#include <iostream>

using namespace std;

/**
 * @class Government
 * @brief Acts as the Government facade, providing simplified access to various departments.
 *
 * This class serves as a facade for different departments within the government, facilitating interactions
 * and managing city simulations. It handles various events and operations that affect citizens and city
 * infrastructure.
 */
class Government
{
public:
    /**
     * @brief Constructs a new Government object.
     *
     * Initializes the government structure and its associated departments.
     */
    Government();

    /**
     * @brief Destroys the Government object.
     */
    //~Government();

    /**
     * @brief Main simulation loop for managing city operations.
     *
     * This method runs the main simulation, handling events and managing citizen interactions.
     */
    void runSim();

    /**
     * @brief Stops the simulation.
     *
     * This method can be called to terminate the ongoing simulation process.
     */
    void stopSim();

private:
    /**
     * @brief Departments managed by the Government facade.
     *
     * These department pointers represent various sectors that the government oversees.
     */
    DeptOfPR *PR;                    ///< Pointer to the Public Relations department
    DeptOfFinance *finance;          ///< Pointer to the Finance department
    DeptOfHousing *housing;          ///< Pointer to the Housing department
    DeptOfTransportation *transport; ///< Pointer to the Transportation department

    string commercialTypes[4] = {"Shop", "Office", "School", "Hospital"};            ///< Types of commercial buildings
    string residentialTypes[3] = {"House", "Apartment", "Estate"};                   ///< Types of residential buildings
    string industrialTypes[4] = {"Warehouse", "Factory", "Airport", "TrainStation"}; ///< Types of industrial buildings
    string landmarkTypes[3] = {"Park", "Monument", "Museum"};                        ///< Types of landmarks

    // Event commands for managing various simulated events
    EventsCommand *pandemic;         ///< Event command for a pandemic scenario
    EventsCommand *economicDownturn; ///< Event command for an economic downturn
    EventsCommand *naturalDisaster;  ///< Event command for a natural disaster
    EventsCommand *loadshedding;     ///< Event command for loadshedding
    EventsCommand *festive;          ///< Event command for festive events
    EventsCommand *babyBoom;         ///< Event command for a baby boom
    EventsCommand *increaseEconomy;  ///< Event command for economic growth

    // Simulation status
    bool simulationIsActive; ///< Flag indicating if the simulation is currently active

    /**
     * @brief Simulates a year in the city's operations.
     *
     * This method manages the yearly progress of the simulation, handling various events and actions.
     */
    void simulateYear();

    /**
     * @brief Handles citizen needs during the simulation.
     *
     * This method addresses the requirements and demands of the citizens.
     */
    void handleCitizenNeeds();

    /**
     * @brief Simulates daily operations within the city.
     *
     * This method processes the daily activities and routines of citizens and city functions.
     */
    void simulateDailyOperations();

    /**
     * @brief Adds new citizens to the city.
     *
     * This method simulates the introduction of new citizens into the city.
     */
    void addNewCitizens();

    /**
     * @brief Displays the current state of the city.
     *
     * This method outputs information regarding the city's status and operations.
     */
    void displayCity();

    /**
     * @brief Adds a new road to the city.
     *
     * This method handles the creation of new road infrastructure within the simulation.
     */
    void addRoad();

    /**
     * @brief Adds a new building to the city.
     *
     * This method manages the construction of new buildings within the city.
     */
    void addBuilding();

    /**
     * @brief Manages city resources efficiently.
     *
     * This method oversees the allocation and management of resources within the city.
     */
    void manageResources();

    /**
     * @brief Evaluates government policies and their impacts.
     *
     * This method assesses the effectiveness of implemented policies on the city.
     */
    void evaluatePolicies();

    /**
     * @brief Triggers random events affecting the city.
     *
     * This method initiates unforeseen events that impact city operations and citizens.
     */
    void triggerRandomEvents();
};

#endif // GOVERNMENT_H
