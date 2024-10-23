#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Adult.h"
#include "Child.h"
#include "Pensioner.h"
#include "Citizen.h"
#include "DeptPR.h"
#include "SadState.h"
#include "SatisfactionState.h"
#include "HappyState.h"
#include "NeutralState.h"
#include "cStates.h"


TEST_CASE("Citizen initialisation") {
   Citizen* person = new Citizen("one", 50, NULL, NULL, NULL, NULL);
   
   CHECK(person->getAge() == 1);
   for(int i = 0; i < 20; i++) {
      person->getOlder();
   }
   CHECK(person->getStateName() == "Adult");

   person->increaseSatisfaction(20);
   CHECK(person->getSatisfactionLevelName() == "Happy");

   person->decreaseSatisfaction(50);
   CHECK(person->getSatisfactionLevelName() == "Sad");

}