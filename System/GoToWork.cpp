#include "GoToWork.h"
#include "GoHome.h"


GoToWork::GoToWork(Citizen* citizen , DeptOfHousing* housing):GoToCommand(citizen,housing)
{
   this->citizen = citizen;
    this->DOH = housing;
    
}

bool GoToWork::execute()
{
  if (citizen->getStateName() == "Adult" && (citizen->getWorkLocation() != NULL))
  {
    this->citizen->travelTo(this->citizen->getWorkLocation());
    citizen->work(1500);

      GoHome* gohome = new GoHome(citizen, this->DOH);
      gohome->execute();

      return true;
   
    }

    cout << citizen->getName() << " Does not have a job :( \n";

  return false;
}
