#ifndef GOHOME_H
#define GOHOME_H

#include "GoToCommand.h"
#include "Citizen.h"
#include <iostream>
using namespace std;

/**
 * @class GoHome
 * @brief This class is a concrete command that allows a citizen to travel from their current position to home.
 *
 * The GoHome command encapsulates the action of a citizen returning home,
 * providing a mechanism to execute this command within the system's command pattern.
 */
class GoHome : public GoToCommand
{
private:
  Citizen *citizen; ///< Pointer to the Citizen object representing the citizen who will execute the command.

public:
  /**
   * @brief Constructs a GoHome command for a specified citizen.
   *
   * @param citizen Pointer to the Citizen object who will go home.
   */
  GoHome(Citizen *citizen);

  /**
   * @brief Executes the command to move the citizen home.
   *
   * This method initiates the action of the citizen traveling to their home.
   *
   * @return True if the command was successfully executed, false otherwise.
   */
  bool execute() override;
};

#endif // GOHOME_H
