#include "GoTrain.h"


bool GoTrain::execute()
{
    cout << "Citizen " << citizen->getName() << "is going to the TrainStation \n";
    IndustrialBuilding* TrainStation = NULL;

    vector<Building*> buildings = DOH->getBuildings();

    for (auto building : buildings)
    {
            IndustrialBuilding* idsBuild_Train = dynamic_cast<IndustrialBuilding*>(building);
            if (idsBuild_Train  && idsBuild_Train->getType() == "TrainStation" )
            {
                TrainStation = idsBuild_Train;
                break;
            }
    }

    if(TrainStation)
    {
        citizen->travelTo(TrainStation);    
        return true;
    }
    else
    {
        cout << "No TrainStation found \n";
        return false;
    }

}
