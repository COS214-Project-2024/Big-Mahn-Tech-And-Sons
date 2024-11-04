#include <iostream>
#include <iomanip>
//
#include "Government.h"
#include "Citizen.h"
#include "DeptOfPR.h"
#include "DeptOfHousing.h"
#include "DeptOfUtilities.h"
#include "DeptOfFinance.h"
#include "Water.h"
#include "WaterSupply.h"
#include "PowerSupply.h"

//
#include "visitHousing.h"
#include "Budget.h"
//
#include "LandmarkBuildingCreator.h"
#include "IndustrialBuildingCreator.h"
#include "ResidentialBuildingCreator.h"
#include "CommercialBuildingCreator.h"
//

#include "NaturalDisasterCommand.h"
#include "LoadsheddingCommand.h"
#include "PandemicCommand.h"
#include "FestivalCommand.h"
#include "RecessionCommand.h"
//
#include "GoToCommand.h"
#include "GoTrain.h"
#include "TrainStation.h"
#include "DeptOfPR.h"



void buildingsTest();
void testResidentialBuildings();
void testCommercialBuildingFunctions();
void testLandmarkBuildings();
void testIndustrialBuildings();
void testHouse();
int testDepartment();


void testNaturalDisaster();
void testPandemic();
void testLoadShedding();
void testFestival();
void testRecession();



//
void testGoToTrainStation();



//
int main()
{

    std::cout << "Hello World" << std::endl;

    // buildingsTest();
    // testResidentialBuildings();
    // testCommercialBuildingFunctions();
    // testLandmarkBuildings();
    // testIndustrialBuildings();

    //testHouse();
    //testDepartment();

    testGoToTrainStation();

    // testHouse();
    // testNaturalDisaster();
    //testPandemic();
    //testLoadShedding();
   // testRecession();
    // Government* gov = new Government();
    // std::cout << "End" << std::endl;

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
    std::cout << "\t \t ~_~_~_Estate~_~_~_~ \t \n";
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
    Citizen* tenant1 = new Citizen("Jane", 10, 10, NULL);
    Citizen* tenant2 = new Citizen("Peter", 20, 20, NULL);
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

int testDepartment() {
    DeptOfHousing *housingDept = new DeptOfHousing(1000000);
    Water *water = new Water("Sparkling", 10000);
    DeptOfUtilities *utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    TaxManager *taxMan = new TaxManager();
    DeptOfFinance *financeDept = new DeptOfFinance(taxMan);
    DeptOfPR prDept(housingDept, utilitiesDept, financeDept);

    // Testing building creation
    std::cout << "=== Testing Building Creation ===" << std::endl;
    housingDept->createResidentialBuilding("House");
    housingDept->createResidentialBuilding("Apartment");
    housingDept->createCommercialBuilding("Shop");
    housingDept->createIndustrialBuilding("Factory");
    housingDept->createLandmarkBuilding("Park");

    // Display all created buildings
    housingDept->displayAllBuildings();

    // Check the total buildings and budget status
    std::cout << "Total Buildings: " << housingDept->getTotalBuildings() << std::endl;
    std::cout << "Total Price of Buildings: " << housingDept->getTotalPrice() << std::endl;
    std::cout << "Remaining Budget: " << housingDept->getRemainingBudget() << std::endl;

    // Testing building removal
    std::cout << "\n=== Testing Building Removal ===" << std::endl;
    housingDept->removeBuildingByName("Family House");
    housingDept->displayAllBuildings();

    // Attempt to remove a non-existing building
    std::cout << "\nAttempting to remove a non-existing building:" << std::endl;
    housingDept->removeBuildingByName("NonExistentBuilding");

    // Testing funding request
    std::cout << "\n=== Testing Funding Request ===" << std::endl;
    double fundingAmount = 200000;  // Example funding request
    if (housingDept->requestFunding(fundingAmount)) {
        std::cout << "Funding request successful. New budget: " << housingDept->getRemainingBudget() << std::endl;
    } else {
        std::cout << "Funding request failed." << std::endl;
    }

    // Listing buildings
    std::cout << "\n=== Listing Buildings ===" << std::endl;
    housingDept->listBuildings();

    // Testing building repairs
    std::cout << "\n=== Testing Building Repairs ===" << std::endl;
    housingDept->repairBuilding("Residential");
    housingDept->displayAllBuildings();

    // Final state
    std::cout << "\n=== Final State of Buildings ===" << std::endl;
    housingDept->displayAllBuildings();

    return 0;
}

void testGoToTrainStation()
{

     DeptOfHousing *housingDept = new DeptOfHousing(1000000);
    Water *water = new Water("Sparkling", 10000);
    Power *power = new Power("Power", 1456.3);
    
    DeptOfUtilities *utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    DeptOfUtilities *powerUtil = new PowerSupply("Eskom", 150000, 4035, power);
    utilitiesDept->setSuccessor(powerUtil);

    TaxManager *taxMan = new TaxManager();

    DeptOfFinance *financeDept = new DeptOfFinance(taxMan);
    DeptOfPR *prDept = new DeptOfPR(housingDept, utilitiesDept, financeDept);



     housingDept->createIndustrialBuilding("TrainStation");
     housingDept->createResidentialBuilding("House");


     std::cout << "Total Buildings: " << housingDept->getTotalBuildings() << std::endl;

    IndustrialBuilding* TrainStation = NULL;
    ResidentialBuilding* houseC = NULL;


    Citizen* citizen = new Citizen("Jane", 10, 10, prDept);


    std::cout<< "Test getALLBUILDINGS VECTOR: "<<"\n";
    vector<Building*> buildings =  housingDept->getBuildings();

    for (auto building : buildings)
{
    if (building == nullptr) continue;

    IndustrialBuilding* TrainStationDest = dynamic_cast<IndustrialBuilding*>(building);
    ResidentialBuilding* House1 = dynamic_cast<ResidentialBuilding*>(building);

    if (TrainStationDest != nullptr && TrainStationDest->getType() == "TrainStation")
    {
        std::cout << "Found the TrainStation: " << TrainStationDest->getName() << "\n";
        TrainStation = TrainStationDest;
    }
    else if (House1 != nullptr && House1->getType() == "House")
    {
        std::cout << "Found the House: " << House1->getName() << "\n";
        houseC = House1;
    }

    if (TrainStation != nullptr && houseC != nullptr)
    {
        break;
    }
}

    houseC->addTenant(citizen);
   std::cout<< "Num ppl in trainStation : " << TrainStation->getCurrentOccupants() << '\n';  
   std::cout << citizen->getBudget() << "\n";
    GoTrain* gotoTrainStasie = new GoTrain(citizen , housingDept);
    gotoTrainStasie->execute();
    std::cout<< "Num ppl at TrainStation : " << TrainStation->getCurrentOccupants() << '\n';
    std::cout << citizen->getBudget() << "\n";

}

// ------------------------------------------------------------------------------------------------------- //

// ------------------------------------------------------------------------------------------------------- //
/*
void testNaturalDisaster()
{
    // Step 1: Initialize the DeptOfHousing and DeptOfTransportation
    DeptOfHousing *deptOfHousing = new DeptOfHousing(100000000);  // Initial budget for testing
    DeptOfTransportation* deptOfTransport = DeptOfTransportation::getInstance();

    // Step 2: Add some buildings to the DeptOfHousing for testing
    std::cout << "Adding buildings to DeptOfHousing...\n";
    deptOfHousing->createResidentialBuilding("Apartment");
    deptOfHousing->createCommercialBuilding("Shop");
    deptOfHousing->createIndustrialBuilding("Factory");
    deptOfHousing->createLandmarkBuilding("Museum");

    // Display all buildings before natural disaster
    std::cout << "\nBuildings before Natural Disaster:\n";
    deptOfHousing->listBuildings();

    // Step 3: Create and execute the NaturalDisasterCommand
    NaturalDisasterCommand* naturalDisasterCommand = new NaturalDisasterCommand(deptOfHousing, deptOfTransport);
    std::cout << "\nExecuting Natural Disaster Command...\n";
    naturalDisasterCommand->execute();

    // Display all buildings after natural disaster to see effects of damage and repair
    std::cout << "\nBuildings after Natural Disaster Command:\n";
    deptOfHousing->listBuildings();

    // Step 4: Clean up singleton
    delete deptOfTransport; 
    delete  naturalDisasterCommand;
}

/*

void testPandemic()
{
   DeptOfPR* prDepartment;

    // Create a vector of citizens for testing
    std::vector<Citizen*> citizens = {
        new Citizen("Alice", 80.0, 10, 20, prDepartment),
        new Citizen("Bob", 70.0, 12, 22, prDepartment),
        new Citizen("Charlie", 60.0, 14, 24, prDepartment)
    };

    // Display initial state of each citizen
    std::cout << "Initial citizen states:\n";
    for (const auto& citizen : citizens) {
        std::cout << "Citizen: " << citizen->getName() 
                  << ", Health: " << citizen->getHealth()
                  << ", Satisfaction: " << citizen->getSatisfactionLevel() << "\n";
    }

    // Create a PandemicCommand instance
    PandemicCommand* pandemicCommand =  new PandemicCommand(citizens);

    // Execute each pandemic command individually for testing
    std::cout << "\n--- Imposing Lockdown ---\n";
    pandemicCommand->imposeLockdown();
    

    std::cout << "\n--- Distributing Vaccines ---\n";
    pandemicCommand->distributeVaccines();
    for (const auto& citizen : citizens) {
        std::cout << "Citizen: " << citizen->getName() 
                  << ", Health: " << citizen->getHealth()
                  << ", Satisfaction: " << citizen->getSatisfactionLevel() << "\n";
    }


    std::cout << "\n--- Managing Citizen Satisfaction ---\n";
    pandemicCommand->manageCitizenSatisfaction();
    for (const auto& citizen : citizens) {
        std::cout << "Citizens, Satisfaction: " << citizen->getSatisfactionLevel() << "\n";
    }

    std::cout << "\n--- Tracking Infection Rates ---\n";
    pandemicCommand->trackInfectionRates();

    // Clean up dynamically allocated citizens
    for (auto& citizen : citizens) {
        delete citizen;
    }
 
}

void testLoadShedding()
{
    //  // Setup for the test
    //     std::cout << "Setting up LoadShedding test..." << std::endl;

    //     // Create a power resource (mock object for testing purposes)
    //     Power mockPowerResource("MockPowerResource", 1000); // Assume Power class exists
    //     PowerSupply powerSupply("MainPowerSupply", 100000, 10000, &mockPowerResource);
    //  DeptOfUtilities* utilitiesDept = new PowerSupply("MainPowerSupply", 100000, 10000, &mockPowerResource);
        
    //    // powerSupply->distributePower();
    //    // Assuming a method to set power supply exists
    //     // Create LoadSheddingCommand with utilities department
    //     LoadsheddingCommand* loadSheddingCommand = new LoadsheddingCommand(utilitiesDept);

    //     // Schedule load shedding
    //     int delay = 5; // Delay of 5 seconds for testing
    //     loadSheddingCommand->scheduleLoadshedding(delay);

        
    //     loadSheddingCommand->execute();

    //     // Clean up
    //     //delete mockPowerResource; // Clean up mock power resource
    //    // delete powerSupply; // Clean up power supply
    //     delete utilitiesDept; // Clean up utilities department

    //     std::cout << "LoadShedding test completed." << std::endl;
}


void testFestival()
{
    Power mockPowerResource("MockPowerResource", 1000);
    DeptOfUtilities* utilitiesDept = new PowerSupply("MainPowerSupply", 100000, 10000, &mockPowerResource);
      DeptOfPR* deptOfPR;
 std::vector<Citizen*> citizens = {
        new Citizen("Alice", 80.0, 10, 20, deptOfPR),
        new Citizen("Bob", 70.0, 12, 22, deptOfPR),
        new Citizen("Charlie", 60.0, 14, 24, deptOfPR)
    };
  
    // Create a FestivalCommand instance
    FestivalCommand* festivalCommand = new FestivalCommand(utilitiesDept, citizens[0], deptOfPR);

    // Execute the festival command, triggering all festival actions
    std::cout << "Executing Festival Command..." << std::endl;
    festivalCommand->execute();

    // Check the results of the command execution
    std::cout << "\n--- Festival Command Results ---" << std::endl;
    std::cout << "Citizen 1 Happiness Level: " << citizens[0]->getSatisfactionLevel() << std::endl;
    std::cout << "Citizen 2 Happiness Level: " << citizens[1]->getSatisfactionLevel() << std::endl;
   
}

void testRecession()
{
   // Create mock finance department
    DeptOfFinance* financeDept;
    DeptOfPR* prDepartment;

    // Create citizens
    std::vector<Citizen*> citizens = {
        new Citizen("Alice", 80.0, 10, 20, prDepartment),
        new Citizen("Bob", 70.0, 12, 22, prDepartment),
        new Citizen("Charlie", 60.0, 14, 24, prDepartment)
    };

     DeptOfHousing *housingDept = new DeptOfHousing(1000000);
    // Create commercial buildings
   housingDept->createCommercialBuilding("Office");
    housingDept->createCommercialBuilding("School");
    housingDept->createCommercialBuilding("Hospital");

    // Create the recession command
    RecessionCommand* recessionCommand;

    // Execute the recession command
    std::cout << "Executing Recession Command...\n";
    recessionCommand->execute();

    // Cleanup
    for(auto& citizens : citizens)
    {
         delete citizens;
    }
   
    delete financeDept;
}

*/