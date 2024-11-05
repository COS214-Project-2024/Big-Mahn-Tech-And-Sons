/**
 * @file Government.h
 * @brief Declaration of the Government class acting as the facade.
 */

#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <vector>
#include "Citizen.h"
#include "Settings.h"

class DeptOfFinance;
class DeptOfHousing;
class DeptOfPR;
class PandemicCommnad;
class FestivalCommand;
class NaturalDisasterCommand;

#include <iostream>
#include "PandemicCommand.h"


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
    ///< @brief Departments managed by the Government facade

    DeptOfPR* PR;
    // WaterSupply* waterS;
    // PowerSupply* powerS;
    // WasteManagement* wasteS;
    DeptOfFinance* finance;
    DeptOfHousing* housing;
    int year;
    
    string commercialTypes[4] = {"Shop", "Office", "School", "Hospital"};
    string residentialTypes[3] = {"House", "Apartment", "Estate"};
    string industrialTypes[4] = {"Warehouse", "Factory", "Airport", "TrainStation"};
    string landmarkTypes[3] = {"Park", "Monument", "Museum"};

    DeptOfTransportation* transport;

    PandemicCommand* pandemic;

FestivalCommand* festive;

NaturalDisasterCommand* disaster;
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
    void events();

    string cityname;
    //menus
    int main_menu(Settings settings); //OK
    int pov_menu(Settings settings);
        int citizen_pov_menu(Settings settings);

        int government_pov_menu(Settings settings);
            int city_grid_menu(Settings settings);
            int government_stats_menu(Settings settings);
};

#endif // GOVERNMENT_H
