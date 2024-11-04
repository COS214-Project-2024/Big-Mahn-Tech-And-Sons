/**
 * @file GoSchool.h
 * @brief Header file for the GoSchool class, which simulates a citizen going to school in a road network.
 * 
 * This file contains the declaration of the GoSchool class, which inherits from the GoToCommand class. 
 * It is responsible for handling the process of a citizen navigating the road network to reach a school destination.
 */

#ifndef GOSCHOOL_H
#define GOSCHOOL_H

#include <iostream>
#include "GoToCommand.h"
#include "Citizen.h"

using namespace std;

/**
 * @class GoSchool
 * @brief A class representing the action of a citizen going to school within the road network.
 * 
 * This class is derived from GoToCommand and simulates the process of a citizen 
 * navigating the road network to reach their school destination.
 */
class GoSchool : public GoToCommand
{
public:
    /**
     * @brief Executes the command for the citizen to go to school.
     *
     * This method simulates the action of the citizen navigating the road network
     * to reach the school destination.
     *
     * @return True if the navigation to the school is successful; false otherwise.
     */
    bool execute() override;
};

#endif // GOSCHOOL_H
