#include "GoHos.h"
#include "CommercialBuilding.h"
#include "DeptOfHousing.h"

bool GoHos::execute()
{

    cout << "Citizen " << citizen->getName() << "is going to the Hospital\n";
    CommercialBuilding *Hosipital = NULL;

    vector<Building *> buildings = DOH->getBuildings();

    for (auto building : buildings)
    {
        CommercialBuilding *idsBuild_Hospital = dynamic_cast<CommercialBuilding *>(building);
        if (idsBuild_Hospital && idsBuild_Hospital->getType() == "Hospital")
        {
            Hosipital = idsBuild_Hospital;
            break;
        }
    }

    if (Hosipital)
    {
        citizen->travelTo(Hosipital);
        return true;
    }
    else
    {
        cout << "No Hospital found \n";
        return false;
    }
}