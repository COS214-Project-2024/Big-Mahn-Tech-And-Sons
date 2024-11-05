#ifndef HAPPYSTATE_H
#define HAPPYSTATE_H

#include "SatisfactionState.h"
#include <string>

using namespace std;

/**
 * @class HappyState
 * @brief Represents a state of high satisfaction for a citizen.
 *
 * This class is a concrete implementation of the SatisfactionState interface,
 * indicating that a citizen is in a happy state when their satisfaction level
 * is greater than or equal to 65. It defines the behavior and characteristics
 * associated with this state.
 */
class HappyState : public SatisfactionState {
public:
    /**
     * @brief Handles the actions associated with the Happy state.
     *
     * This method defines what happens when a citizen is in a Happy state. 
     * It performs actions or state transitions based on the citizen's satisfaction.
     *
     * @param citizen A pointer to the Citizen object representing the individual
     *                in the Happy state.
     */
    void handle(Citizen* citizen) override;

    /**
     * @brief Returns the name of the state.
     *
     * This method provides a string representation of the current state name.
     *
     * @return A string indicating that the state is "Happy".
     */
    string getStateName() const override;
};

#endif // HAPPYSTATE_H
