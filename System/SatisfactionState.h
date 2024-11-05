/**
 * @file SatisfactionState.h
 * @author u23539764
 * @brief Declaration of the SatisfactionState abstract class and its derived states.
 */

#ifndef SATISFACTIONSTATE_H
#define SATISFACTIONSTATE_H

#include <string>
#include "Citizen.h"

using namespace std;

/**
 * @class SatisfactionState
 * @brief Abstract class representing the satisfaction state of a citizen.
 *
 * This class serves as a base for different satisfaction states (e.g., HappyState, SadState).
 * It defines the interface for handling citizen satisfaction and provides a mechanism
 * for changing the behavior of citizens based on their satisfaction levels.
 */
class SatisfactionState {
public:
    /**
     * @brief Pure virtual method to handle actions related to a citizen's satisfaction.
     *
     * This method must be overridden by derived classes to define specific behavior
     * when a citizen is in a particular satisfaction state. It allows for dynamic
     * handling of citizen actions and interactions based on their current state.
     *
     * @param citizen A pointer to the Citizen object whose state is being handled.
     */
    virtual void handle(Citizen* citizen) = 0;

    /**
     * @brief Gets the name of the satisfaction state.
     *
     * This method must be overridden by derived classes to provide a string representation
     * of the state. This can be useful for logging, debugging, or UI display purposes.
     *
     * @return std::string The name of the satisfaction state.
     */
    virtual std::string getStateName() const = 0;
};

#endif // SATISFACTIONSTATE_H
