#include "NaturalDisasterCommand.h"
#include "DeptOfTransportation.h"
#include "DeptOfHousing.h"
#include <iostream>
#include <random>

 NaturalDisasterCommand::NaturalDisasterCommand(DeptOfHousing* housing, DeptOfTransportation* transport): deptOfHousing(housing), deptOfTransport(transport) {};

void NaturalDisasterCommand::damageBuildings() {
    std::cout << "Natural Disaster: Damaging 50% of buildings.\n";

   if (!deptOfHousing) return;

    std::cout << "Natural Disaster: Damaging 50% of buildings.\n";
    int totalBuildings = deptOfHousing->getTotalBuildings();
    int buildingsToDamage = totalBuildings / 2;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, totalBuildings - 1);

    for (int i = 0; i < buildingsToDamage; ++i) {
        int index = dist(gen);
        std::string buildingName = deptOfHousing->getBuildingName(index);
        if (!buildingName.empty()) {
            deptOfHousing->removeBuildingByName(buildingName);
        }
    }
    // Hypothetically update GUI to reflect damaged buildings.
}


void NaturalDisasterCommand::repairInfrastructure() {
    std::cout << "Natural Disaster: Starting infrastructure repair.\n";
    
    //Sample repair logic, assuming types of buildings are known:
   // this one usues tjhe cloning(Prototype)
   // Send malaika the implementation to see what is going on here 
    deptOfHousing->repairBuilding("Residential");
    deptOfHousing->repairBuilding("Commercial");
    deptOfHousing->repairBuilding("Industrial");

    std::cout << "Infrastructure repair completed.\n";
}


void NaturalDisasterCommand::blockTransportRoutes()
{
    
}


void NaturalDisasterCommand::execute() {
    std::cout << "Natural Disaster: Initiating disaster response sequence.\n";
    damageBuildings();
    repairInfrastructure();
}



