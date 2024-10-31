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
//

void buildingsTest();

int main()
{

    std::cout << "Hello World" << std::endl;
    // buildingsTest();
    testResidentialBuildings();
    std::cout << "End" << std::endl;

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
    Building*  aprty = resi2->createBuilding("Apartment");
    Building*  house  = resi3->createBuilding("House");
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


void testResidentialBuildings() {
    ResidentialBuildingCreator creator;
    TaxManager taxManager;  // Create a TaxManager instance

    // Define an array of building types to test
    std::string buildingTypes[] = {"House", "Apartment", "Estate"};

    for (const std::string& type : buildingTypes) {
        // Create a building using the factory
        Building* building = creator.createBuilding(type);
        if (building) {
            // Display stats
            building->displayStats();

            // Set a new name
            building->setName("Name 2.0");

            // Test repairClone
            Building* clonedBuilding = building->repairClone();
            std::cout << "Cloned Building Name: " << clonedBuilding->getName() << std::endl;

            // Test the accept function
            building->accept(&taxManager);  // Pass the tax manager to the accept function

            // Clean up
            delete building;
            delete clonedBuilding;
        } else {
            std::cerr << "Failed to create building of type: " << type << std::endl;
        }
    }
}

