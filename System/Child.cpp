#include "Child.h"
#include "Adult.h"

void ChildState::handle(Citizen *citizen)
{
   if (citizen->getAge() > 18 && citizen->getAge() < 65) {
      cout << "Updating citizen age state from Child to Adult\n";
      citizen->setState(new AdultState());
   }
}

std::string ChildState::getStateName() const
{
   return "Child";
}