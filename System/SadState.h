/**
 * @file SadState.h
 * @brief Declaration of the SadState class representing a low satisfaction state.
 */

#ifndef SADSTATE_H
#define SADSTATE_H

#include "SatisfactionState.h"
#include <string>

using namespace std;

/**
 * @class SadState
 * @brief Represents a state of low satisfaction for a citizen.
 *
 * This class inherits from SatisfactionState and is responsible for handling
 * situations where a citizen's satisfaction level falls below a specified threshold.
 * It defines actions to be taken when a citizen is in a sad state and can contribute
 * to a broader satisfaction management system.
 */
class SadState : public SatisfactionState
{
public:
   /**
    * @brief Handles the behavior of a citizen in a sad state.
    *
    * This method defines the actions or responses that should occur
    * when a citizen's satisfaction is below the threshold (less than 45).
    * Specific behaviors may include interactions with other systems to
    * improve citizen satisfaction or address underlying issues.
    *
    * @param citizen A pointer to the Citizen object whose state is being handled.
    */
   void handle(Citizen *citizen) override;

   /**
    * @brief Gets the name of the state.
    *
    * This method returns a string representation of the SadState,
    * which can be used for logging or display purposes.
    *
    * @return A string indicating the name of the state (e.g., "Sad").
    */
   string getStateName() const override;
};

#endif // SADSTATE_H
