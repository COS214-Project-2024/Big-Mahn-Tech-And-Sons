/**
 * @file Citizen.h
 * @brief Declaration of the Citizen class representing a citizen in the simulation.
 *
 * INVOKER: This class invokes the @file GoToCommand.h commands.
 * SUBJECT: Part of the observer design pattern, as it is observed by the Department of PR @file DeptPR.h.
 */

#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include "ModeOfTrans.h"
#include "CitizenStates.h"
#include "GoToCommand.h"
#include "DeptOfPR.h"
#include "DeptOfTransportation.h"

using namespace std;

class Building;
class SatisfactionState;
class CityGrid;
class CitizenState;

/**
 * @class Citizen
 * @brief Represents a citizen in the life simulation game.
 *
 * A Citizen can travel between buildings using various modes of transport.
 * The Citizen's behavior changes based on their state (Child, Adult, Pensioner).
 */
class Citizen
{
private:
    string name;                   /**< Name of the citizen */
    ModeOfTrans *modeOfTransport;  /**< Current mode of transport */
    DeptOfPR *PR;                  /**< Reference to the government’s PR department */
    Building *currentLocation;     /**< Current building location */
    Building *workLocation;        /**< Citizen's work location */
    Building *homeLocation;        /**< Citizen's home location */
    DeptOfTransportation *DT;      /**< Reference to the department of transportation */
    CitizenState *state;           /**< Current state of the citizen */
    SatisfactionState *satisState; /**< Current satisfaction state of the citizen */
    int age;                       /**< Age of the citizen */
    int ageThreshold = 0;          /**< Maximum age the citizen can reach before death */
    double budget;                 /**< Budget of the citizen */
    double health;                 /**< Health level of the citizen */
    double satisfaction;           /**< Satisfaction level of the citizen */

public:
    /**
     * @brief Constructs a new Citizen object.
     *
     * @param nam Name of the citizen.
     * @param PR Reference to the government's PR department.
     *
     * @note Initializes the citizen's age at 1.
     * @note Initializes health to 100 and satisfaction level at 50.
     * @note Randomizes the initial budget.
     * @note Sets the initial state to ChildState.
     */
    Citizen(const std::string &nam, DeptOfPR *PR);

    /**
     * @brief Destroys the Citizen object.
     */
    ~Citizen();

    /**
     * @brief Increases the citizen's age by one year.
     *
     * If the citizen is in the pensioner state, calculates a new age threshold.
     * If the citizen reaches this threshold, they die.
     */
    void getOlder();

    /**
     * @brief Notifies the PR department of any state change.
     */
    void notifyPR();

    /**
     * @brief Gets the age of the citizen.
     *
     * @return int The current age of the citizen.
     */
    int getAge();

    /**
     * @brief Gets the name of the citizen.
     *
     * @return std::string The name of the citizen.
     */
    std::string getName() const;

    /**
     * @brief Gets the health level of the citizen.
     *
     * @return double The current health level.
     */
    double getHealth();

    /**
     * @brief Gets the satisfaction level of the citizen.
     *
     * @return double The current satisfaction level.
     */
    double getSatisfactionLevel();

    /**
     * @brief Gets the budget of the citizen.
     *
     * @return double The current budget.
     */
    double getBudget() const;

    /**
     * @brief Adds income to the citizen's budget.
     *
     * @param amount The amount to add to the budget.
     */
    void work(double amount);

    /**
     * @brief Spends an amount from the citizen's budget.
     *
     * @param amount The amount to spend.
     * @return true If the spending was successful.
     * @return false If there was insufficient budget.
     */
    bool Spend(double amount);

    /**
     * @brief Displays the citizen's details.
     */
    void display();

    /**
     * @brief Decreases the health of the citizen by a certain percentage.
     * @param percentage The percentage by which the health is decreased.
     */
    void decreaseHealth(double percentage);

    /**
     * @brief Increases the health of the citizen by a certain percentage.
     * @param percentage The percentage by which the health is increased.
     */
    void increaseHealth(double percentage);

    /**
     * @brief Lowers the citizen's satisfaction by a certain amount.
     * @param amount The amount by which satisfaction decreases.
     */
    void decreaseSatisfaction(double amount);

    /**
     * @brief Increases the citizen's satisfaction by a certain amount.
     * @param amount The amount by which satisfaction increases.
     */
    void increaseSatisfaction(double amount);

    /**
     * @brief Sets the age threshold for the citizen.
     * @param age The age threshold.
     */
    void setThreshold(int age);

    /**
     * @brief Gets the citizen's age threshold.
     *
     * @return int The age threshold.
     */
    int getThreshold();

    /**
     * @brief Gets the name of the citizen's current state.
     *
     * @return std::string The state name.
     */
    std::string getStateName() const;

    /**
     * @brief Gets the name of the citizen's current satisfaction level.
     *
     * @return std::string The satisfaction level name.
     */
    std::string getSatisfactionLevelName() const;

    /**
     * @brief Sets the citizen's satisfaction state.
     *
     * @param state Pointer to the new satisfaction state.
     */
    void setSatisfactionState(SatisfactionState *state);

    /**
     * @brief Sets the citizen's state.
     *
     * @param state Pointer to the new state.
     */
    void setState(CitizenState *state);

    /**
     * @brief Updates the citizen's state based on their age.
     */
    void updateState();

    /**
     * @brief Gets the current mode of transport.
     *
     * @return ModeOfTrans* Pointer to the current mode of transport.
     */
    ModeOfTrans *getModeOfTransport() const;

    /**
     * @brief Sets the citizen's mode of transport.
     *
     * @param mode Pointer to the new mode of transport.
     */
    void setModeOfTransport(ModeOfTrans *mode);

    /**
     * @brief Gets the citizen's current building location.
     *
     * @return Building* Pointer to the current building.
     */
    Building *getCurrentLocation() const;

    /**
     * @brief Gets the citizen's home location.
     *
     * @return Building* Pointer to the home location.
     */
    Building *getHomeLocation() const;

    /**
     * @brief Gets the citizen's work location.
     *
     * @return Building* Pointer to the work location.
     */
    Building *getWorkLocation() const;

    /**
     * @brief Sets the citizen's work location.
     *
     * @param building Pointer to the work building.
     */
    void setWork(Building *building);

    /**
     * @brief Sets the citizen's home location.
     *
     * @param building Pointer to the home building.
     */
    void setHome(Building *building);

    /**
     * @brief Sets the citizen's current location.
     *
     * @param building Pointer to the current building.
     */
    void setCurrent(Building *building);

    /**
     * @brief Travels to another building.
     *
     * Executes the relevant command if the destination is a specific type (work, home, school, etc.).
     *
     * @param destination Pointer to the destination building.
     */
    void travelTo(Building *destination);

    /**
     * @brief Sets the citizen's current building location.
     *
     * @param b Pointer to the building.
     */
    void setCurrentLocation(Building *b);
};

#endif // CITIZEN_H
