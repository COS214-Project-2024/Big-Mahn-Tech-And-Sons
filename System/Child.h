/**
 * @file ChildState.h
 * @brief Declaration of the ChildState class.
 */

#ifndef CHILDSTATE_H
#define CHILDSTATE_H

#include <string>
#include "CitizenStates.h"

/**
 * @class ChildState
 * @brief Represents the Child state of a citizen.
 *
 * Implements behaviors specific to child citizens.
 */
class ChildState : public CitizenState {
public:
    /**
     * @brief Handles the behavior specific to the Child state for a citizen.
     * @param citizen Pointer to the Citizen object.
     */
    void handle(Citizen* citizen) override;

    /**
     * @brief Gets the name of the state.
     * 
     * @return std::string The state name "Child".
     */
    std::string getStateName() const override;
};

#endif // CHILDSTATE_H
