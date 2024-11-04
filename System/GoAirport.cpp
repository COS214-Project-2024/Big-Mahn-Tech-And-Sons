#include "GoAirport.h"

bool GoAirport::execute()
{
    
    cout << "Citizen " << citizen->getName() << "is going to the Airport \n";
    IndustrialBuilding* Airport = NULL;

    vector<Building*> buildings = DOH->getBuildings();

    for (auto building : buildings)
    {
            IndustrialBuilding* idsBuild_Airport = dynamic_cast<IndustrialBuilding*>(building);
            if (idsBuild_Airport  && idsBuild_Airport->getType() == "Airport" )
            {
                Airport = idsBuild_Airport;
                break;
            }
    }

    if(Airport)
    {
        citizen->travelTo(Airport);    
        return true;
    }
    else
    {
        cout << "No Airport found \n";
        return false;
    }
}
