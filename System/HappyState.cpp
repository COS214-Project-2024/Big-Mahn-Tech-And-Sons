#include "HappyState.h"

#include "SadState.h"
#include "HappyState.h"
#include "NeutralState.h"

void HappyState::handle(Citizen *citizen)
{
   double level = citizen->getSatisfactionLevel();

   if(level < 45) {
      citizen->setSatisfactionState(new SadState());
   } else if(level < 65) {
      citizen->setSatisfactionState(new NeutralState());
   }
}

string HappyState::getStateName() const
{
   return "Happy";
}
