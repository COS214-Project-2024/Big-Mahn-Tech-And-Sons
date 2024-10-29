#ifndef GOHOME_H
#define GOHOME_H

#include "GoToCommand.h"
#include "Citizen.h"
#include <iostream>
using namespace std;


/**
 * @class  GoHome
 * @brief   This class is a concrete command that allows a citizen to travel from the current position to home
 */


class GoHome : public GoToCommand
{
   private:
      Citizen* citizen;
   public:
      GoHome(Citizen* citizen);
};
#endif
