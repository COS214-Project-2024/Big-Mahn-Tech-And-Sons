#include "GoToCommand.h"
#include "DeptOfHousing.h"

GoToCommand::GoToCommand(Citizen *citizen, DeptOfHousing *DOH)
{
    this->citizen = citizen;
    this->DOH = DOH;
}

