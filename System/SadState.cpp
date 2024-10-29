#include "SadState.h"
#include "HappyState.h"
#include "NeutralState.h"

void SadState::handle(Citizen *citizen)
{
   double level = citizen->getSatisfactionLevel();
   
   if(level >= 65) {
      citizen->setSatisfactionState(new HappyState());
   } else if(level >= 45) {
      citizen->setSatisfactionState(new NeutralState());
   }
}

string SadState::getStateName() const
{
   return "Sad";
}
