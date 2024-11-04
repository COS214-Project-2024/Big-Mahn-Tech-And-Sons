#include "GoHome.h"

GoHome::GoHome(Citizen *citizen):GoToCommand(citizen , DOH)
{
    citizen=citizen;
}

bool GoHome::execute()
{

    if(citizen)
    {
        citizen->travelTo(citizen->getHomeLocation());
        return true;
    }

    return false;
}
