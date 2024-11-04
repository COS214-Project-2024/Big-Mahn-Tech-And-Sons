#include "Adult.h"
#include "Pensioner.h"
#include <random>

void AdultState::handle(Citizen *citizen)
{
   if(citizen->getAge() >= 65) {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> distr(1, 35);
      citizen->setThreshhold(citizen->getAge() + distr(gen));  
      cout << "Updating citizen age state from Adult to Pensioner\n";

      citizen->setState(new PensionerState());
   }
}

std::string AdultState::getStateName() const
{
   return "Adult";
}
