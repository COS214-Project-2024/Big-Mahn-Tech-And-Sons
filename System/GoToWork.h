/**
 * @file GoToWork.h
 * @brief Part of the command design pattern allowing a citizen to travel from the current position to the work node in the road network.
 */

#ifndef GOTOWORK_H
#define GOTOWORK_H

#include "GoToCommand.h"
#include "Citizen.h"
#include "DeptOfTransportation.h"

#include <iostream>

using namespace std;

/**
 * @class GoToWork
 * @brief A concrete command class that allows a citizen to travel from their current position to their work destination.
 * 
 * This class is part of the Command design pattern and enables the simulation of a citizen's journey to work
 * within the road network. Upon successful arrival at the work destination, the citizen may earn income.
 */
class GoToWork : public GoToCommand
{
private:
    Citizen* citizen;           ///< Pointer to the citizen traveling to work.
    DeptOfHousing* housing;     ///< Pointer to the Department of Housing for housing-related functionalities.

public:
    /**
     * @brief Constructor for the GoToWork class.
     * 
     * Initializes a GoToWork command for the specified citizen, simulating their journey to work
     * and adding income upon successful arrival.
     * 
     * @param citizen A pointer to the Citizen object representing the person going to work.
     * @param housing A pointer to the DeptOfHousing object for accessing housing-related functionalities.
     */
    GoToWork(Citizen* citizen, DeptOfHousing* housing);

    /**
     * @brief Executes the command for the citizen to go to their work destination.
     *
     * This method simulates the journey of the citizen to their workplace and potentially adds income
     * to their account upon arrival.
     *
     * @return True if the journey to the work destination is successful; false otherwise.
     */
    bool execute() override;
};

#endif // GOTOWORK_H
