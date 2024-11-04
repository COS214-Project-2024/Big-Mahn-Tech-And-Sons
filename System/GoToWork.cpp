#include "GoToWork.h"
#include "GoHome.h"

GoToWork::GoToWork(Citizen *citizen, DeptOfHousing *housing) : GoToCommand(citizen, DOH)
{
  citizen = citizen;
  housing = DOH;
}

bool GoToWork::execute()
{
  if (citizen->getStateName() == "Adult" && (citizen->getWorkLocation() != NULL))
  {
    this->citizen->travelTo(this->citizen->getWorkLocation());
    citizen->work(1500);

    GoHome *gohome = new GoHome(citizen);
    gohome->execute();

    return true;
  }

  return false;
}
