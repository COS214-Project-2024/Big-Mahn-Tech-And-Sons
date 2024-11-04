/**
 * @file GoTrain.h
 * @brief Part of the command design pattern allowing a citizen to travel from the current position to a train station node in the road network.
 */

#ifndef GOTRAIN_H
#define GOTRAIN_H

#include "GoToCommand.h"
#include "Citizen.h"
#include "DeptOfTransportation.h"
#include "IndustrialBuilding.h"
#include "DeptOfHousing.h"


#include <iostream>
using namespace std;

/**
 * @class GoTrain
 * @brief A concrete command class that allows a citizen to travel from their current position to a train station.
 * 
 * This class is part of the Command design pattern and simulates the citizen's journey to a train station within the road network.
 */
class GoTrain : public GoToCommand
{
private:
    Citizen* citizen;           /**< Pointer to the citizen traveling to the train station */
   // DeptOfTransportation* DOT;  /**< Pointer to the Department of Transportation */
   // IndustrialBuilding* IB;     /**< Pointer to the Industrial Building */
    DeptOfHousing* DOH;         /**< Pointer to the Department of Housing */
    string destination;         /**< The destination train station */



public:
    /**
     * @brief Constructor for the GoTrain class.
     * 
     * Initializes a GoTrain command for the specified citizen to simulate their journey to a train station.
     * 
     * @param citizen A pointer to the Citizen object representing the person traveling to the train station.
     * @param roadNetwork A pointer to the RoadNetwork object used for navigating to the train station.
     */
    GoTrain(Citizen* citizen , /**/ DeptOfHousing* deptH);


    bool execute() override ;
};

#endif
