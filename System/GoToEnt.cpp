#include "GoToEnt.h"

GoToEnt::GoToEnt(Citizen *citizen, DeptOfHousing *housing) : GoToCommand(citizen, housing)
{
    this->citizen = citizen;
    this->DOH = housing;
    
}

bool GoToEnt::execute()
{
    cout << "Citizen " << citizen->getName() << " is going to entertain themselves \n";
    LandmarkBuilding *entertainment = NULL;

    vector<Building *> buildings = DOH->getBuildings();

    std::srand(std::time(0));
    int randomIndex = std::rand() % 3;

    std::string landmark;
    switch (randomIndex)
    {
    case 0:
        landmark = "Park";
        break;
    case 1:
        landmark = "Museum";
        break;
    case 2:
        landmark = "Monument";
        break;
    default:
        landmark = "Park"; // Default case, just in case
    }

    for (auto building : buildings)
    {
        LandmarkBuilding *ids_Build_Landmark = dynamic_cast<LandmarkBuilding *>(building);

        if (ids_Build_Landmark && ids_Build_Landmark->getType() == landmark)
        {
            entertainment = ids_Build_Landmark;
            break;
        }
    }

    if (entertainment)
    {
        citizen->travelTo(entertainment);
        return true;
    }
    else
    {
        cout << "No entertainment found \n";
        return false;
    }
}