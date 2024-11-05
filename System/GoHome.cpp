#include "GoHome.h"

GoHome::GoHome(Citizen *citizen, DeptOfHousing *housing):GoToCommand(citizen, housing)
{
    this->citizen=citizen;
    this->DOH = housing;
}



bool GoHome::execute()
{

    if (citizen)
    {
        citizen->travelTo(citizen->getHomeLocation());
        return true;
    }

    return false;
}