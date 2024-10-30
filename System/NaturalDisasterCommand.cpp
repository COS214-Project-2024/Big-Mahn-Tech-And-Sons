#include "NaturalDisasterCommand.h"
#include "DeptOfTransportation.h"
#include "DeptOfHousing.h"
#include <iostream>
#include <random>


/**
 * @brief Damages a percentage of buildings within the housing department.
 * @param deptOfHousing Reference to the DeptOfHousing object to manage buildings.
 */
void NaturalDisasterCommand::damageBuildings(DeptOfHousing& deptOfHousing) {
    std::cout << "Natural Disaster: Damaging 50% of buildings.\n";

    int totalBuildings = deptOfHousing.getTotalBuildings();
    int buildingsToDamage = totalBuildings / 2;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, totalBuildings - 1);

    for (int i = 0; i < buildingsToDamage; ++i) {
        int index = dist(gen);
        std::string buildingName = deptOfHousing.getBuildingName(index);  // Get name of building at index
        if (!buildingName.empty()) {  // Check if the building name is valid
            deptOfHousing.removeBuildingByName(buildingName);  // Remove by name
        }
    }
    // Hypothetically update GUI to reflect damaged buildings.
}

/**
 * @brief Blocks transport routes affected by the natural disaster.
 * @param deptOfTransport Reference to DeptOfTransport for managing routes.
 */
void NaturalDisasterCommand::blockTransportRoutes(DeptOfTransportation& deptOfTransport) {
    std::cout << "Natural Disaster: Blocking affected transport routes.\n";
    // Logic for determining affected routes could be added here.
    //deptOfTransport.removeroads (); // Ask David if he has the following function has 3 parameters 
}


/**
 * @brief Repairs infrastructure by allocating resources from the housing department.
 * @param deptOfHousing Reference to DeptOfHousing for managing repairs.
 */
void NaturalDisasterCommand::repairInfrastructure(DeptOfHousing& deptOfHousing) {
    std::cout << "Natural Disaster: Starting infrastructure repair.\n";
    
    //Sample repair logic, assuming types of buildings are known:
   // this one usues tjhe cloning(Prototype)
   // Send malaika the implementation to see what is going on here 
    deptOfHousing.repairBuilding("Residential");
    deptOfHousing.repairBuilding("Commercial");
    deptOfHousing.repairBuilding("Industrial");

    std::cout << "Infrastructure repair completed.\n";
}


/**
 * @brief Executes the natural disaster response sequence by calling each stage.
 * @param deptOfHousing Reference to DeptOfHousing for building management.
 * @param deptOfTransport Reference to DeptOfTransport for transport route management.
 */
void NaturalDisasterCommand::execute(DeptOfHousing& deptOfHousing, DeptOfTransportation& deptOfTransport) {
    std::cout << "Natural Disaster: Initiating disaster response sequence.\n";
    damageBuildings(deptOfHousing);
    blockTransportRoutes(deptOfTransport);
    repairInfrastructure(deptOfHousing);
}



