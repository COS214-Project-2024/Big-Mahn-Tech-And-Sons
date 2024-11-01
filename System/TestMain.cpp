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
void testResidentialBuildings();
void testCommercialBuildingFunctions();
void testLandmarkBuildings();
void testIndustrialBuildings();
void testHouse();

int main()
{

    std::cout << "Hello World" << std::endl;

    // buildingsTest();
    // testResidentialBuildings();
    // testCommercialBuildingFunctions();
    // testLandmarkBuildings();
    // testIndustrialBuildings();
    testHouse();


    std::cout << "End" << std::endl;

    return 0;
}







// ---------------------------------- BUILDING SECTION TESTS --------------------------------------------- //


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

void testCommercialBuildingFunctions() {
    CommercialBuildingCreator creator;
    TaxManager taxManager; // Create a TaxManager instance for visitor testing

    // Array of commercial building types to test
    std::string buildingTypes[] = {"Office", "School", "Hospital", "Shop"};

    for (const std::string& type : buildingTypes) {
        // Create a commercial building using the factory
        Building* building = creator.createBuilding(type);
        CommercialBuilding* commercialBuilding = dynamic_cast<CommercialBuilding*>(building);

        if (commercialBuilding) {
            std::cout << "Testing " << type << ":\n";

            // Display initial stats
            commercialBuilding->displayStats();

            // Test availability setters and getters
            commercialBuilding->setAvailableJobs(10);
            commercialBuilding->setAvailableKidsSpaces(20);
            commercialBuilding->setAvailableBeds(30);

            std::cout << "Updated Stats:\n";
            std::cout << "Available Jobs: " << commercialBuilding->getAvailableJobs() << std::endl;
            std::cout << "Available Kids' Spaces: " << commercialBuilding->getAvailableKidsSpaces() << std::endl;
            std::cout << "Available Beds: " << commercialBuilding->getAvailableBeds() << std::endl;

            // Test closeBuilding and isClosed functions
            commercialBuilding->closeBuilding();
            std::cout << "Building closed? " << (commercialBuilding->isClosed() ? "Yes" : "No") << std::endl;

            // Test reopenBuilding and recheck isClosed
            commercialBuilding->reopenBuilding();
            std::cout << "Building reopened? " << (!commercialBuilding->isClosed() ? "Yes" : "No") << std::endl;

            // Display stats again after reopening
            commercialBuilding->displayStats();

            // Test the accept function (Visitor Pattern)
            commercialBuilding->accept(&taxManager);

            // Clean up
            delete commercialBuilding;
        } else {
            std::cerr << "Failed to create commercial building of type: " << type << std::endl;
        }

        std::cout << "\n";
    }
}

void testLandmarkBuildings() {
    LandmarkBuildingCreator creator;  // Create a factory instance
    TaxManager taxManager;  // Create a TaxManager instance

    // Define an array of building types to test
    std::string buildingTypes[] = {
        "Park",
        "Monument",
        "Museum"
    };

    for (const std::string& type : buildingTypes) {
        // Create a building using the factory
        Building* building = creator.createBuilding(type);
        // Attempt to cast to LandmarkBuilding*
        LandmarkBuilding* landmarkBuilding = dynamic_cast<LandmarkBuilding*>(building);
        
        if (landmarkBuilding) {
            // Display stats
            landmarkBuilding->displayStats();

            // Set a new name
            landmarkBuilding->setName("New Landmark Name");

            // Test repairClone
            Building* clonedBuilding = landmarkBuilding->repairClone();
            std::cout << "Cloned Building Name: " << clonedBuilding->getName() << std::endl;

            // Test the accept function
            landmarkBuilding->accept(&taxManager);  // Pass the tax manager to the accept function

            // Clean up
            delete landmarkBuilding;
            delete clonedBuilding;
        } else {
            std::cerr << "Failed to create building of type: " << type << std::endl;
            delete building;  // Clean up in case of failed cast
        }
    }
}

void testIndustrialBuildings() {
    IndustrialBuildingCreator creator;
    TaxManager taxManager;  // Create a TaxManager instance

    // Create buildings using the factory method
    Building* warehouse = creator.createBuilding("Warehouse");
    Building* factoryBuilding = creator.createBuilding("Factory");
    Building* airport = creator.createBuilding("Airport");
    Building* trainStation = creator.createBuilding("TrainStation");

    // Display stats for each building
    std::cout << "\nTesting Warehouse:\n";
    warehouse->displayStats();
    
    std::cout << "\nTesting Factory:\n";
    factoryBuilding->displayStats();
    
    std::cout << "\nTesting Airport:\n";
    airport->displayStats();
    
    std::cout << "\nTesting Train Station:\n";
    trainStation->displayStats();

    // Test the repairClone() method
    std::cout << "\nTesting Repair Clone for Warehouse:\n";
    Building* warehouseClone = warehouse->repairClone();
    warehouseClone->displayStats();

    std::cout << "\nTesting Repair Clone for Factory:\n";
    Building* factoryClone = factoryBuilding->repairClone();
    factoryClone->displayStats();

    // Test accept() method, assuming TaxManager is not implemented yet
    std::cout << "\nTesting Accept Method (stubbed) for each building:\n";
    warehouse->accept(&taxManager);
    factoryBuilding->accept(&taxManager);
    airport->accept(&taxManager);
    trainStation->accept(&taxManager);

    // Clean up
    delete warehouse;
    delete factoryBuilding;
    delete airport;
    delete trainStation;
    delete warehouseClone;
    delete factoryClone;
}

void testHouse() {
    ResidentialBuildingCreator creator; // Create a ResidentialBuildingCreator instance
    TaxManager taxManager;              // Create a TaxManager instance

    // Create a House using the factory
    Building* house = creator.createBuilding("House");

    // Test initial state
    std::cout << "Testing House Stats:" << std::endl;
    house->displayStats();

    // Create tenants and test adding them
    Citizen* tenant1 = new Citizen("Jane", 50, 10, 10, NULL);
    Citizen* tenant2 = new Citizen("Peter", 30, 20, 20, NULL);
    std::cout << "\nAdding tenants:" << std::endl;
    house->addTenant(tenant1);
    house->addTenant(tenant2);
    house->displayStats();

    // Test removing a tenant
    std::cout << "\nRemoving a tenant:" << std::endl;
    house->removeTenant(tenant1);
    house->displayStats();

    // Test requesting water and electricity
    std::cout << "\nRequesting water:" << std::endl;
    house->requestWater(50.0);
    house->displayStats();

    std::cout << "\nConsuming water:" << std::endl;
    house->consumeWater(30.0);
    house->displayStats();

    std::cout << "\nRequesting electricity:" << std::endl;
    house->requestElectricity(20.0);
    house->displayStats();

    std::cout << "\nConsuming electricity:" << std::endl;
    house->consumeElectricity(10.0);
    house->displayStats();

    // Test cutting water and power supply
    std::cout << "\nCutting water supply:" << std::endl;
    house->waterCut();
    house->consumeWater(20.0); // Attempt to consume after cut
    house->displayStats();

    std::cout << "\nCutting power supply:" << std::endl;
    house->powerCut();
    house->consumeElectricity(10.0); // Attempt to consume after cut
    house->displayStats();

    // Test clearing waste
    std::cout << "\nSetting waste production and clearing waste:" << std::endl;
    house->setWaste(100.0); // Set some waste production
    house->displayStats();
    house->clearWaste();
    house->displayStats();

    // Clean up
    delete tenant1; // Clean up tenant
    delete tenant2; // Clean up tenant
    delete house;   // Clean up house
}



// ------------------------------------------------------------------------------------------------------- //

