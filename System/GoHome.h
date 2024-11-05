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
   Citizen* citizen;
   DeptOfHousing* DOH;
  public:
  GoHome(Citizen *citizen, DeptOfHousing *housing);
  
  bool execute() override;
};

#endif // GOHOME_H
