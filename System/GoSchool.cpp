#include "GoSchool.h"
#include "CommercialBuilding.h"
#include "DeptOfHousing.h"

GoSchool::GoSchool(Citizen *citizen, DeptOfHousing *housing) : GoToCommand(citizen,housing)
{
      this->citizen = citizen;
    this->DOH = housing;
}

bool GoSchool::execute()
{
  cout << "Citizen " << citizen->getName() << "is going to the School\n";

    CommercialBuilding* School = NULL;
    vector<Building*> buildings = DOH->getBuildings();


    for (auto building : buildings)
    {
            CommercialBuilding* idsBuild_School = dynamic_cast<CommercialBuilding*>(building);
            if (idsBuild_School  && idsBuild_School->getType() == "School" )
            {
                School = idsBuild_School;
                break;
            }
    }

    if(School)
    {
        citizen->travelTo(School);    
        return true;
    }
    else
    {
        cout << "No School found \n";
        return false;
    }
}