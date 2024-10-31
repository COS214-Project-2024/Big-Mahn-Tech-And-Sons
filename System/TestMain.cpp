#include <iostream>
//
#include "Citizen.h"
//
#include "visitHousing.h"
#include "Budget.h"
//
#include "LandmarkBuildingCreator.h"
#include "IndustrialBuildingCreator.h"
#include "ResidentialBuildingCreator.h"
#include "CommercialBuildingCreator.h"
#include "visitHousing.h"
#include "Budget.h"
#include "Power.h"
#include "Water.h"
#include "WaterSupply.h"
#include "PowerSupply.h"

void TestingDptUtilities();

int main() {
    // Create a budget
    Budget cityBudget(10000);
    cityBudget.reportStatus();

    // Create a residential building and citizen
    ResidentialBuildingCreator resCreator;
    auto house = resCreator.createBuilding("House");
    auto housePtr = std::dynamic_pointer_cast<House>(house);
    
    // Create citizen
    Citizen john("John Doe", 75.0, 0, 0, nullptr);
    
    // Add citizen to residential building
    if (housePtr) {
        housePtr->addTenant(&john);
    }

    // Create tax manager and collect taxes
    visitHousing taxManager;
    house->accept(&taxManager);
    cityBudget.accept(&taxManager);

    // Report budget status after tax collection
    cityBudget.reportStatus();

    std::cout << "Hello World" << std::endl;
    buildingsTest();

    return 0;
}

void buildingsTest()
{

    std::cout << "Testing Residential Buildings :_________________ \n";
    // 1. RESIDENTIAL SITUATION
    ResidentialBuildingCreator *resi1 = new ResidentialBuildingCreator();
    ResidentialBuildingCreator *resi2 = new ResidentialBuildingCreator();
    ResidentialBuildingCreator *resi3 = new ResidentialBuildingCreator();
    ResidentialBuildingCreator *resi4 = new ResidentialBuildingCreator();

    Building *esate = 
     resi1->createBuilding("Estate");
    // Building*  aprty = resi2->createBuilding("Apartment");
    // Building*  house  = resi3->createBuilding("House");
    // Building*  errorH = resi4->createBuilding("Lol");

    std::cout << "\t =============Testing Functionality of  Residential Buildings :==========\n";
    std::cout << "\t \t _~_~_~_Estate_~_~_~_~ \t \n";
    /*std::cout << */
    esate->displayStats();
    // some functions dont output and some need jus to be made to make sense
    std::cout << "Occupants: " << esate->getCurrentOccupants() << " \t MeterBox for Electricity :  " << esate->getElectricityMeterBox()
              << " \t MeterBox for Water: " << esate->getWaterMeterBox()
              << " \t their usages:  " << esate->getElectricityUsage() << " , " << esate->getWaterUsage()
              << " \t Name of building:  " << esate->getName()
              << "\n \t building of type: " << esate->getType()
              << "\t networth of :  " << esate->getNetWorth()
              << " \t has a priceTag of:  " << esate->getPriceTag() << "\n";
}
 }

 void TestingDptUtilities() {
    // Initialize Power and Water resources with specific capacities
    Power* powerResource = new Power("City Power", 500);  // 500 units of power available
    Water* waterResource = new Water("City Water", 1000);  // 1000 units of water available

    // Initialize departments with budget and capacity
    PowerSupply powerSupply("Power Department", 20000, 500, powerResource);
    WaterSupply waterSupply("Water Department", 15000, 1000, waterResource);
    WasteManagement wasteManagement("Waste Department", 10000, 300); // Waste capacity in kg

    // Chain setup: set the successor for each department
    powerSupply.setSuccessor(&waterSupply);
    waterSupply.setSuccessor(&wasteManagement);

    // Create buildings with specific utility needs
    Building buildingA("Building A", 50); // Max capacity of 50
    buildingA.setElectricityUsage(50);    // 50 units of power requested
    buildingA.setWaterUsage(100);          // 100 units of water requested
    buildingA.setWaste(20);                // 20 kg of waste produced

    Building buildingB("Building B", 30); // Max capacity of 30
    buildingB.setElectricityUsage(30);    // 30 units of power requested
    buildingB.setWaterUsage(60);           // 60 units of water requested
    buildingB.setWaste(10);                // 10 kg of waste produced

    // Add buildings to each department for management
    powerSupply.addBuilding(&buildingA);
    powerSupply.addBuilding(&buildingB);
    waterSupply.addBuilding(&buildingA);
    waterSupply.addBuilding(&buildingB);
    wasteManagement.addBuilding(&buildingA);
    wasteManagement.addBuilding(&buildingB);

    // Create requests for resources using strings instead of enum
    Request powerRequest("POWER", &buildingA, 80); // Requesting 80 units of power for buildingA
    Request waterRequest("WATER", &buildingB, 150); // Requesting 150 units of water for buildingB
    Request wasteRequest("WASTE", &buildingA, 25);  // Requesting waste processing for 25 kg for buildingA

    std::cout << "Testing power request handling for Building A:" << std::endl;
    powerSupply.handleRequest(powerRequest);

    std::cout << "\nTesting water request handling for Building B:" << std::endl;
    waterSupply.handleRequest(waterRequest);

    std::cout << "\nTesting waste request handling for Building A:" << std::endl;
    wasteManagement.handleRequest(wasteRequest);

    // Demonstrate distribution of resources
    std::cout << "\nDistributing Power:" << std::endl;
    powerSupply.distributePower();

    std::cout << "\nDistributing Water:" << std::endl;
    waterSupply.distributeWater();

    std::cout << "\nWaste Collection:" << std::endl;
    wasteManagement.collectWaste();

    // Testing shutdown and increase functions
    std::cout << "\nTesting power and water shutdown:" << std::endl;
    powerSupply.powerShutDown();
    waterSupply.waterShutDown();

    std::cout << "\nIncreasing resource capacities:" << std::endl;
    powerSupply.increasePowerCapacity();
    waterSupply.increaseWaterCapacity();
    wasteManagement.expandWasteCapacity();

    // Cleanup
    delete powerResource;
    delete waterResource;
} 