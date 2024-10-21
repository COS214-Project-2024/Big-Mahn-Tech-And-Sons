/**
 * @file cStates.h
 * @author u23539764
 * @brief Declaration of the SatisfactionState abstract class and its derived states.
 */


#ifndef SATISFACTIONSTATE_H
#define SATISFACTIONSTATE_H

#include <string>
#include "Citizen.h"
using namespace std;

class SatisfactionState {
   public:
 virtual void handle(Citizen* citizen) = 0;
    /**
     * @brief Gets the name of the state.
     * 
     * @return std::string The state name.
     */
    virtual std::string getStateName() const = 0;
    
};

#endif