#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Adult.h"
#include "Child.h"
#include "Pensioner.h"
#include "Citizen.h"
#include "DeptOfPR.h"
#include "SadState.h"
#include "SatisfactionState.h"
#include "HappyState.h"
#include "NeutralState.h"
#include "CitizenStates.h"



TEST_CASE("Citizen initialisation") {
  // DepartmentOfPR*  pr = new DepartmentOfPR(NULL,NULL, NULL,NULL);
   Citizen* person = new Citizen("one", 50, 10, 10 ,NULL);
   
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