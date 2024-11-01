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
#include "WasteManagement.h"

void TestingDptUtilities();

int main() {
    // Create a budget
    /*
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
*/
TestingDptUtilities();

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

    Building *esate = resi1->createBuilding("Estate");
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
 

 void TestingDptUtilities() {

    std::cout <<  "\n\n\n\n" << endl;

    Water *water = new Water("CityWater", 10000);
    Power *power = new Power("CityPower", 1456.3);

    PowerSupply powerDept("PowerManics", 5000, 400, power);
    WaterSupply waterDept("AguaCity", 2000, 500, water);
    WasteManagement wasteDept("WasteMgt", 150, 600);

    Building *b1 = new House();
    Building *b2 = new Apartment();

    //b2->consumeElectricity(20);
    b2->consumeWater(30);
    b1->clearWaste();
    b1->powerCut();
    b1->waterCut();

    powerDept.addBuilding(b1);
    //powerDept.distributePower();
    powerDept.calculatePowerUsage();
    powerDept.increasePowerCapacity();
    powerDept.powerShutDown();
    powerDept.finalCapacity();

    waterDept.addBuilding(b2);
    waterDept.distributeWater();
    cout << "Total usage is at " << waterDept.calculateWaterUsage() << " 000 liters" << endl;
    waterDept.increaseWaterCapacity();
    waterDept.waterShutDown();
    waterDept.finalCapacity();

    wasteDept.addBuilding(b1);
    wasteDept.collectWaste();
    cout << wasteDept.calculateWasteProcessing() << "units of waste  processed" << endl;
    wasteDept.expandWasteCapacity();
    cout << wasteDept.getWasteCapacity() << " is the current waste capacity" << endl;

    waterDept.setSuccessor(&wasteDept);
    wasteDept.setSuccessor(NULL);

    // Example request for power within capacity
    Request req1("P", b1, 100);
    powerDept.handleRequest(req1); // Should be handled by PowerSupply

    // Example request for water within capacity
    Request req2("water", b2, 80);
    powerDept.handleRequest(req2); // Passed from PowerSupply to WaterSupply

    // Example request for power that exceeds capacity of PowerSupply, should be passed along
    Request req3("p", b2, 450);
    powerDept.handleRequest(req3); // PowerSupply can't handle, passed to WaterSupply if applicable

    // Example request for waste within capacity of WasteManagement
    Request req4("WASTE", b1, 100);
    powerDept.handleRequest(req4); // Passed from PowerSupply and WaterSupply to WasteManagement

    cout << " " << endl;

    std::cout << endl << endl << endl;

} 
