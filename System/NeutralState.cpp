#include "NeutralState.h"

#include "SadState.h"
#include "HappyState.h"
#include "NeutralState.h"

void NeutralState::handle(Citizen *citizen)
{
   double level = citizen->getSatisfactionLevel();
   if (level < 45)
   {
      citizen->setSatisfactionState(new SadState());
   }
   else if (level >= 65)
   {
      citizen->setSatisfactionState(new HappyState());
   }
}

string NeutralState::getStateName() const
{
   return "Neutral";
}
