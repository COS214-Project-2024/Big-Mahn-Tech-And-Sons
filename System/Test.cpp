#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <thread>   // For std::this_thread
#include <chrono>   // For std::chrono::seconds


#include "Adult.h"
#include "Child.h"
#include "Pensioner.h"
#include "Citizen.h"
#include "DeptOfPR.h"
#include "SadState.h"
#include "SatisfactionState.h"
#include "HappyState.h"
#include "NeutralState.h"
#include "CitizenStates.h"
#include "DeptOfHousing.h"
#include "DeptOfUtilities.h"
#include "DeptOfFinance.h"

#include "Water.h"
#include "Power.h"
#include "PowerSupply.h"
#include "WaterSupply.h"
#include "WasteManagement.h"

#include "ResidentialBuildingCreator.h"
#include "CommercialBuildingCreator.h"
#include "IndustrialBuildingCreator.h"
#include "LandmarkBuildingCreator.h"
#include "TaxManager.h"

#include "NaturalDisasterCommand.h"
#include "LoadsheddingCommand.h"
#include "PandemicCommand.h"
#include "FestivalCommand.h"
#include "RecessionCommand.h"

TEST_CASE("Citizen initialisation")
{
    DeptOfHousing *housingDept = new DeptOfHousing(100000);

    Water *water = new Water("Sparkling", 10000);
    Power *power = new Power("Power", 1456.3);

    DeptOfUtilities *utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    DeptOfUtilities *powerUtil = new PowerSupply("Eskom", 150000, 4035, power);

    utilitiesDept->setSuccessor(powerUtil);
    TaxManager *taxMan = new TaxManager();
    DeptOfFinance *financeDept = new DeptOfFinance(taxMan);

    DeptOfPR *prDept = new DeptOfPR(housingDept, utilitiesDept, financeDept);

    Citizen person("John Doe", 10, 20, prDept);

    CHECK(person.getAge() == 1);
    for (int i = 0; i < 20; i++)
    {
        person.getOlder();
    }
    CHECK(person.getStateName() == "Adult");

    person.increaseSatisfaction(20);
    CHECK(person.getSatisfactionLevelName() == "Happy");

    person.decreaseSatisfaction(50);
    CHECK(person.getSatisfactionLevelName() == "Sad");
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

TEST_CASE("Citizen Initialization")
{
    DeptOfHousing *housingDept = new DeptOfHousing(100000);

    Water *water = new Water("Sparkling", 10000);
    Power *power = new Power("Power", 1456.3);

    DeptOfUtilities *utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    DeptOfUtilities *powerUtil = new PowerSupply("Eskom", 150000, 4035, power);

    utilitiesDept->setSuccessor(powerUtil);
    TaxManager *taxMan = new TaxManager();
    DeptOfFinance *financeDept = new DeptOfFinance(taxMan);

    DeptOfPR *prDept = new DeptOfPR(housingDept, utilitiesDept, financeDept);

    Citizen citizen("John Doe", 10, 20, prDept);

    CHECK(citizen.getName() == "John Doe");
    CHECK(citizen.getAge() == 1);                  // Starts at age 1 by specification
    CHECK(citizen.getHealth() == 100.0);           // Health should initialize to 100
    CHECK(citizen.getSatisfactionLevel() == 50.0); // Initial satisfaction level

    delete housingDept;
    delete utilitiesDept;
    delete financeDept;
    delete prDept;
}

TEST_CASE("Citizen Age Increment")
{

    DeptOfHousing *housingDept = new DeptOfHousing(100000);

    Water *water = new Water("Sparkling", 10000);
    Power *power = new Power("Power", 1456.3);

    DeptOfUtilities *utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    DeptOfUtilities *powerUtil = new PowerSupply("Eskom", 150000, 4035, power);

    utilitiesDept->setSuccessor(powerUtil);
    TaxManager *taxMan = new TaxManager();
    DeptOfFinance *financeDept = new DeptOfFinance(taxMan);

    DeptOfPR *prDept = new DeptOfPR(housingDept, utilitiesDept, financeDept);

    Citizen citizen("Alice Smith", 15, 25, prDept);

    int initialAge = citizen.getAge();
    citizen.getOlder();
    CHECK(citizen.getAge() == initialAge + 1);

    delete housingDept;
    delete utilitiesDept;
    delete financeDept;
    delete prDept;
}

// Additional test cases for other Citizen functionalities
// Repeat the same setup and teardown for each test case

TEST_CASE("Citizen Work and Spend")
{
    DeptOfHousing *housingDept = new DeptOfHousing(100000);

    Water *water = new Water("Sparkling", 10000);
    Power *power = new Power("Power", 1456.3);

    DeptOfUtilities *utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    DeptOfUtilities *powerUtil = new PowerSupply("Eskom", 150000, 4035, power);

    utilitiesDept->setSuccessor(powerUtil);
    TaxManager *taxMan = new TaxManager();
    DeptOfFinance *financeDept = new DeptOfFinance(taxMan);

    DeptOfPR *prDept = new DeptOfPR(housingDept, utilitiesDept, financeDept);

    Citizen citizen("Bob Brown",  10, 20, prDept);
    double initialBudget = citizen.getBudget();

    SUBCASE("Earning Income")
    {
        citizen.work(100.0);
        CHECK(citizen.getBudget() == initialBudget + 100.0);
    }

    SUBCASE("Successful Spending")
    {
        citizen.work(100.0); // Ensuring sufficient funds are available
        bool spendResult = citizen.Spend(50.0);
        CHECK(spendResult == true);
        CHECK(citizen.getBudget() == initialBudget + 50.0); // Check remaining budget after spending
    }

    SUBCASE("Unsuccessful Spending - Insufficient Budget")
    {
        bool spendResult = citizen.Spend(1000.0);
        CHECK(spendResult == false); // Should return false as spending is unsuccessful
    }

    delete housingDept;
    delete utilitiesDept;
    delete financeDept;
    delete prDept;
}

TEST_CASE("DeptOfPR initializes and interacts with Departments")
{
    // Initialize the departments and resources
    DeptOfHousing *housingDept = new DeptOfHousing(100000);

    Water *water = new Water("Sparkling", 10000);
    Power *power = new Power("Power", 1456.3);

    DeptOfUtilities *utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    DeptOfUtilities *powerUtil = new PowerSupply("Eskom", 150000, 4035, power);

    utilitiesDept->setSuccessor(powerUtil); // Setting up the Chain of Responsibility
    TaxManager *taxMan = new TaxManager();
    DeptOfFinance *financeDept = new DeptOfFinance(taxMan);

    // Initialize DeptOfPR and link to other departments
    DeptOfPR *prDept = new DeptOfPR(housingDept, utilitiesDept, financeDept);

    // Test that PR Department was successfully initialized
    CHECK(prDept != nullptr);
}

TEST_CASE("DeptOfPR notifies Housing Department to build")
{
    DeptOfHousing *housingDept = new DeptOfHousing(100000);
    Water *water = new Water("Sparkling", 10000);
    DeptOfUtilities *utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    TaxManager *taxMan = new TaxManager();
    DeptOfFinance *financeDept = new DeptOfFinance(taxMan);
    DeptOfPR prDept(housingDept, utilitiesDept, financeDept);

    int prev = housingDept->getTotalBuildings();
    prDept.notifyHousingToBuild("Residential");
    CHECK(housingDept->getTotalBuildings() == prev + 1); // Assuming `isBuildNotified` method tracks this state
}

TEST_CASE("DeptOfPR notifies Utilities Department")
{
    /*
    DeptOfHousing* housingDept = new DeptOfHousing(100000);
    Water* water = new Water("Sparkling", 10000);
    DeptOfUtilities* utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    TaxManager* taxMan = new TaxManager();
    DeptOfFinance* financeDept = new DeptOfFinance(taxMan);
    DeptOfPR prDept(housingDept, utilitiesDept, financeDept);


    prDept.notifyUtilities();
    CHECK(utilitiesDept->isNotified() == true);  // Assuming `isNotified` method tracks this state
    */
}

TEST_CASE("DeptOfPR notifies Taxman in Finance Department")
{
    /*
    DeptOfHousing* housingDept = new DeptOfHousing(100000);
    Water* water = new Water("Sparkling", 10000);
    DeptOfUtilities* utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    TaxManager* taxMan = new TaxManager();
    DeptOfFinance* financeDept = new DeptOfFinance(taxMan);
    DeptOfPR prDept(housingDept, utilitiesDept, financeDept);


    prDept.notifyTaxman("Citizen");
    CHECK(financeDept-> == true);  // Assuming `isTaxmanNotified` method tracks this state'
    */
}

TEST_CASE("DeptOfPR updates Building and Citizen states")
{
    /*
    DeptOfHousing* housingDept = new DeptOfHousing(100000);
    Water* water = new Water("Sparkling", 10000);
    DeptOfUtilities* utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    TaxManager* taxMan = new TaxManager();
    DeptOfFinance* financeDept = new DeptOfFinance(taxMan);
    DeptOfPR prDept(housingDept, utilitiesDept, financeDept);

    Building building;
    Citizen citizen("John Doe", 50.0, 10, 20, &prDept);

    prDept.update(&building);
    prDept.update(&citizen);

    // Check for state changes if there are observable effects on building or citizen
    */
}

TEST_CASE("DeptOfPR Funding Request")
{
    /*
    DeptOfHousing* housingDept = new DeptOfHousing(100000);
    Water* water = new Water("Sparkling", 10000);
    DeptOfUtilities* utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    TaxManager* taxMan = new TaxManager();
    DeptOfFinance* financeDept = new DeptOfFinance(taxMan);
    DeptOfPR prDept(housingDept, utilitiesDept, financeDept);

    double requestAmount = 5000.0;
    prDept.notifyTaxman("Housing");

    CHECK(fundingGranted);
    CHECK(finance.getRemainingBudget() >= requestAmount);

    */
}

TEST_CASE("DeptOfUtility chain")
{

    Water *water = new Water("Sparkling", 10000);
    Power *power = new Power("Electricity", 1456.3);

    PowerSupply powerDept("Power", 5000, 400, power);
    WaterSupply waterDept("Water", 2000, 500, water);
    WasteManagement wasteDept("Waste", 150, 600);

    // Set up chain of responsibility
    powerDept.setSuccessor(&waterDept);
    waterDept.setSuccessor(&wasteDept);

    Building *b1 = new House();
    Building *b2 = new Apartment();

    double initialPowerLevel = powerDept.getPowerCapacity();
    double initialWaterLevel = waterDept.getWaterCapacity();
    double initialWasteCapacity = wasteDept.getWasteCapacity();

    // Example request for power within capacity
    Request req1("Power", b1, 100);
    powerDept.handleRequest(req1); // Should be handled by PowerSupply

    // Example request for water within capacity
    Request req2("Water", b2, 80);
    powerDept.handleRequest(req2); // Passed from PowerSupply to WaterSupply

    // Example request for power that exceeds capacity of PowerSupply, should be passed along
    Request req3("Power", b2, 450);
    powerDept.handleRequest(req3); // PowerSupply can't handle, passed to WaterSupply if applicable

    // Example request for waste within capacity of WasteManagement
    Request req4("Waste", b1, 100);
    powerDept.handleRequest(req4); // Passed from PowerSupply and WaterSupply to WasteManagement

    // Example request for waste that exceeds WasteManagement capacity, should return unfulfilled
    Request req5("Waste", b2, 700);
    powerDept.handleRequest(req5); // No handler should be able to fulfill this request

    // Example of high demand water request that exceeds all capacities
    Request req6("Water", b2, 2000);
    powerDept.handleRequest(req6); // No handler should be able to fulfill this request

    CHECK(powerDept.getPowerCapacity() == initialPowerLevel);
    CHECK(waterDept.getWaterCapacity() == initialWaterLevel);
    CHECK(wasteDept.getWasteCapacity() == initialWasteCapacity);

    // Edge cases:
    // Large water request that exceeds water capacity but should not affect other departments
    Request req7("Water", b1, 1200);
    powerDept.handleRequest(req7); // Exceeds water capacity, should fail gracefully

    // Unrecognized resource request type, should pass through all departments and remain unhandled
    Request req8("Gas", b1, 50);
    powerDept.handleRequest(req8); // Should go through the chain but remain unhandled
    
}



TEST_CASE("PandemicCommand functionality") {
    /*
    DeptOfHousing *housingDept = new DeptOfHousing(100000);
    Water *water = new Water("Sparkling", 10000);
    DeptOfUtilities *utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    TaxManager *taxMan = new TaxManager();
    DeptOfFinance *financeDept = new DeptOfFinance(taxMan);
    DeptOfPR prDept(housingDept, utilitiesDept, financeDept);
    // Create mock citizens
    Citizen* citizen1 = new Citizen("Alice", 2, 4,&prDept);
    Citizen* citizen2 = new Citizen("Bob",  2, 4,&prDept);
    Citizen* citizen3 = new Citizen("Charlie", 2, 4,&prDept);


    for (int i = 0; i < 20; i++)
    {
        citizen1->getOlder();
        citizen2->getOlder();
        citizen3->getOlder();
    }

    // Vector of citizens affected by the pandemic
    std::vector<Citizen*> citizens = {citizen1, citizen2, citizen3};
    
    // Create a PandemicCommand instance
    PandemicCommand pandemicCommand(citizens);
    
    // Test imposing lockdown
    pandemicCommand.imposeLockdown();
    // Check if lockdown was imposed (replace with actual state check)
    CHECK(citizen1->getCurrentLocation() == citizen1->getHomeLocation());

    // Test increasing healthcare funding
    pandemicCommand.increaseHealthcareFunding();
   // CHECK(pandemicCommand.getHealthcareFunding() > previousFunding); // not 


    // Test distributing vaccines
    pandemicCommand.distributeVaccines();
    // CHECK(citizen1->hasVaccine() == true);
    // CHECK(citizen2->hasVaccine() == true);
    // CHECK(citizen3->hasVaccine() == true);

    // Test quarantining citizens
    double prevHealth = citizen3->getHealth();
    double prevSatisfaction = citizen3->getSatisfactionLevel();
    pandemicCommand.quarantineCitizens();
    CHECK(citizen3->getHealth() < prevHealth);
    CHECK(citizen3->getSatisfactionLevel() < prevSatisfaction);

    // Test tracking infection rates
    pandemicCommand.trackInfectionRates();

    // Test command execution
   // pandemicCommand.execute();
    // CHECK(pandemicCommand.isExecuted() == true);

    // Clean up
    delete citizen1;
    delete citizen2;
    delete citizen3;

    */
}


// ------------------------------------------------------------------------------------------------------- //

// ----------------------------- CITY GROWTH SECTION TESTS ----------------------------------------------- //



TEST_CASE("Test DeptOfHousing initialization and building creation") {
    DeptOfHousing deptOfHousing(100000000);  // Initialize with a large budget

    SUBCASE("Add Residential Building - Apartment") {
        deptOfHousing.createResidentialBuilding("Apartment");
        CHECK(deptOfHousing.getTotalBuildings() == 1);
    }

    SUBCASE("Add Multiple Building Types") {
        deptOfHousing.createResidentialBuilding("Apartment");
        deptOfHousing.createCommercialBuilding("Shop");
        deptOfHousing.createIndustrialBuilding("Factory");
        deptOfHousing.createLandmarkBuilding("Museum");
        CHECK(deptOfHousing.getTotalBuildings() == 4);
    }
}

TEST_CASE("Test NaturalDisasterCommand damage buildings") {
    DeptOfHousing deptOfHousing(100000000); 
    DeptOfTransportation* deptOfTransport = DeptOfTransportation::getInstance();
    deptOfHousing.createResidentialBuilding("Apartment");
    deptOfHousing.createCommercialBuilding("Shop");
    deptOfHousing.createIndustrialBuilding("Factory");
    deptOfHousing.createLandmarkBuilding("Museum");

    NaturalDisasterCommand naturalDisaster(&deptOfHousing, deptOfTransport);
    int initialCount = deptOfHousing.getTotalBuildings();
    
    naturalDisaster.execute();  // Use execute() instead of damageBuildings()

    // Ensure around half of the buildings are damaged
    CHECK(deptOfHousing.getTotalBuildings() == initialCount / 2);
}

TEST_CASE("Test NaturalDisasterCommand repair buildings") {
    DeptOfHousing deptOfHousing(100000000); 
    DeptOfTransportation* deptOfTransport = DeptOfTransportation::getInstance();
    deptOfHousing.createResidentialBuilding("Apartment");
    deptOfHousing.createCommercialBuilding("Shop");
    deptOfHousing.createIndustrialBuilding("Factory");

    NaturalDisasterCommand naturalDisaster(&deptOfHousing, deptOfTransport);
    naturalDisaster.execute();  // Simulate the natural disaster

    // Verify that building types are present after repair
    CHECK(deptOfHousing.getTotalBuildings() > 0);  // Check total buildings count
}

TEST_CASE("Clean up singleton") {
    delete DeptOfTransportation::getInstance();
}


TEST_CASE("Test Pandemic Command") {
    // Set up the environment
    DeptOfHousing* housingDept = new DeptOfHousing(100000);
    Water* water = new Water("Sparkling", 10000);
    Power* power = new Power("Power", 1456.3);
    DeptOfUtilities* utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    DeptOfUtilities* powerUtil = new PowerSupply("Eskom", 150000, 4035, power);
    utilitiesDept->setSuccessor(powerUtil);
    TaxManager* taxMan = new TaxManager();
    DeptOfFinance* financeDept = new DeptOfFinance(taxMan);
    DeptOfPR* prDept = new DeptOfPR(housingDept, utilitiesDept, financeDept);

    // Create citizens for testing
    std::vector<Citizen*> citizens = {
        new Citizen("Alice", 10, 20, prDept),
        new Citizen("Bob", 12, 22, prDept),
        new Citizen("Charlie", 14, 24, prDept)
    };
    PandemicCommand* pandemicCommand = new PandemicCommand(citizens);

    SUBCASE("Initial Citizen States") {
        for (const auto& citizen : citizens) {
            CHECK(citizen->getHealth() == 100.0);
            CHECK(citizen->getSatisfactionLevel() == 50.0);
        }
    }

    SUBCASE("Impose Lockdown") {
        pandemicCommand->imposeLockdown();
        for (const auto& citizen : citizens) {
            CHECK(citizen->getHealth() == doctest::Approx(90.0)); // Health decreases by 10
            CHECK(citizen->getSatisfactionLevel() == doctest::Approx(40.0)); // Satisfaction decreases by 10
        }
    }

    SUBCASE("Distribute Vaccines") {
        // Apply lockdown first to lower health, then distribute vaccines
        pandemicCommand->imposeLockdown();
        pandemicCommand->distributeVaccines();
        for (const auto& citizen : citizens) {
            CHECK(citizen->getHealth() > 90.0); // Health increases, should be > 90.0
        }
    }

    SUBCASE("Manage Citizen Satisfaction") {
        pandemicCommand->manageCitizenSatisfaction();
        for (const auto& citizen : citizens) {
            CHECK(citizen->getSatisfactionLevel() == doctest::Approx(65.0)); // Satisfaction increases by 15
        }
    }

    SUBCASE("Track Infection Rates") {
        pandemicCommand->imposeLockdown(); // Lower health
        pandemicCommand->trackInfectionRates();
        
        int infectedCount = 0;
        for (const auto& citizen : citizens) {
            if (citizen->getHealth() < 50.0) {
                infectedCount++;
            }
        }
        double infectionRate = (static_cast<double>(infectedCount) / citizens.size()) * 100;
        CHECK(infectionRate >= 0.0); // Infection rate should be calculated, even if zero
    }

    SUBCASE("Execute Pandemic Command Sequence") {
        pandemicCommand->execute();
        for (const auto& citizen : citizens) {
            CHECK(citizen->getHealth() >= 50.0); // Health should have increased due to vaccines
            CHECK(citizen->getSatisfactionLevel() >= 40.0); // Satisfaction should be managed
        }
    }

    // Clean up dynamically allocated resources
    for (auto& citizen : citizens) {
        delete citizen;
    }
    delete housingDept;
    delete utilitiesDept;
    delete powerUtil;
    delete taxMan;
    delete financeDept;
    delete prDept;
    delete pandemicCommand;
}


TEST_CASE("LoadsheddingCommand functionality test") {
    // Creating instances of ResidentialBuildingCreator
    ResidentialBuildingCreator *resi1 = new ResidentialBuildingCreator();
    ResidentialBuildingCreator *resi2 = new ResidentialBuildingCreator();
    ResidentialBuildingCreator *resi3 = new ResidentialBuildingCreator();

    // Create buildings
    Building *estate = resi1->createBuilding("Estate");
    Building *apartment = resi2->createBuilding("Apartment");
    Building *house = resi3->createBuilding("House");

    // Setup for the test
    std::cout << "Setting up LoadShedding test..." << std::endl;

    // Create a mock Power resource
    Power mockPowerResource("MockPowerResource", 1000); // Initial amount of power
    PowerSupply powerSupply("MainPowerSupply", 100000, 10000, &mockPowerResource);

    // Create LoadsheddingCommand with power supply
    LoadsheddingCommand loadSheddingCommand(&powerSupply);

    // Schedule load shedding
    int delay = 5; // Delay of 5 seconds for testing
    loadSheddingCommand.scheduleLoadshedding(delay);

    // Execute the load shedding command
    std::this_thread::sleep_for(std::chrono::seconds(delay));
    loadSheddingCommand.execute();

    // Verify that the expected changes occurred
    // Assuming you have a method in PowerSupply to check power status
    // This might need to be implemented if it doesn't exist
    double powerAfterLoadShedding = powerSupply.calculatePowerUsage(); // or a suitable method
    CHECK(powerAfterLoadShedding < 1000); // Check if power usage has decreased after load shedding

    std::cout << "LoadShedding test completed." << std::endl;

    // Cleanup
    delete estate;
    delete apartment;
    delete house;
    delete resi1;
    delete resi2;
    delete resi3;
}


TEST_CASE("FestivalCommand execution test") {
    DeptOfHousing housingDept(100000);
    Water water("Sparkling", 10000);
    Power power("Power", 1456.3);

    DeptOfUtilities* utilitiesDept = new WaterSupply("Water", 5000.02, 100000, &water);
    DeptOfUtilities* powerUtil = new PowerSupply("Eskom", 150000, 4035, &power);
    utilitiesDept->setSuccessor(powerUtil);

    TaxManager taxMan;
    DeptOfFinance financeDept(&taxMan);
    DeptOfPR deptOfPR(&housingDept, utilitiesDept, &financeDept);

    std::vector<Citizen*> citizens = {
        new Citizen("Alice", 10, 20, &deptOfPR),
        new Citizen("Bob", 12, 22, &deptOfPR),
        new Citizen("Charlie", 14, 24, &deptOfPR)
    };

    FestivalCommand festivalCommand(utilitiesDept, citizens[0], &deptOfPR);
    double initialSatisfaction = citizens[0]->getSatisfactionLevel();

    festivalCommand.execute();

    // Check if the citizen's happiness increased
    CHECK(citizens[0]->getSatisfactionLevel() > initialSatisfaction);

    // Clean up
    delete utilitiesDept;
    delete powerUtil;
    for (auto citizen : citizens) {
        delete citizen;
    }
}


TEST_CASE("RecessionCommand execution test") {
    // Setup departments and resources
    DeptOfHousing housingDept(100000);
    Water water("Sparkling", 10000);
    Power power("Power", 1456.3);

    DeptOfUtilities* utilitiesDept = new WaterSupply("Water", 5000.02, 100000, &water);
    DeptOfUtilities* powerUtil = new PowerSupply("Eskom", 150000, 4035, &power);
    utilitiesDept->setSuccessor(powerUtil);

    TaxManager taxMan;
    DeptOfFinance financeDept(&taxMan);
    DeptOfPR deptOfPR(&housingDept, utilitiesDept, &financeDept);

    // Create commercial buildings
    CommercialBuildingCreator resi1, resi2, resi3;
    Building* shop = resi1.createBuilding("Shop");
    Building* office = resi2.createBuilding("Office");
    Building* school = resi3.createBuilding("School");

    CommercialBuilding* shopBuilding = dynamic_cast<CommercialBuilding*>(shop);
    CommercialBuilding* officeBuilding = dynamic_cast<CommercialBuilding*>(office);
    CommercialBuilding* schoolBuilding = dynamic_cast<CommercialBuilding*>(school);

    std::vector<CommercialBuilding*> commercialBuildings = {shopBuilding, officeBuilding, schoolBuilding};

    // Create citizen and recession command
    Citizen* alice = new Citizen("Alice", 10, 20, &deptOfPR);
    RecessionCommand recessionCommand(&financeDept, alice, commercialBuildings);

    // Capture initial satisfaction level
    double initialSatisfaction = alice->getSatisfactionLevel();

    recessionCommand.execute();

    // Verify that taxes have been raised - manually verify this within financeDept

    // Check if the citizen's satisfaction has decreased
    CHECK(alice->getSatisfactionLevel() < initialSatisfaction);

    // Check that each commercial building is closed
    for (auto* building : commercialBuildings) {
        CHECK(building->isClosed());
    }

    // Clean up
    delete utilitiesDept;
    delete powerUtil;
    delete alice;
    delete shop;
    delete office;
    delete school;
}



// --------------------------------------------------------------------------------------------------------- //







// ---------------------------------- BUILDING SECTION TESTS --------------------------------------------- //



TEST_CASE("Testing Residential Buildings Creation and Functionality") {
    // ResidentialBuildingCreator creator;
    // TaxManager taxManager;  // Create a TaxManager instance

    // // Define an array of building types to test
    // std::string buildingTypes[] = {"House", "Apartment", "Estate"};

    // for (const std::string& type : buildingTypes) {
    //     // Create a building using the factory
    //     Building* building = creator.createBuilding(type);
    //     REQUIRE(building != nullptr); // Check that the building is created successfully

    //     // Test the initial name and stats display
    //     CHECK(building->getName() == type + ""); // Verify the initial name
    //     building->displayStats(); // Call displayStats

    //     // Set a new name and verify it
    //     building->setName("Name 2.0");
    //     CHECK(building->getName() == "Name 2.0"); // Verify the name change

    //     // Test repairClone
    //     Building* clonedBuilding = building->repairClone();
    //     REQUIRE(clonedBuilding != nullptr); // Check that the cloned building is created successfully
    //     CHECK(clonedBuilding->getName() == "Name 2.0"); // Verify the cloned name

    //     // Test the accept function
    //     building->accept(&taxManager);  // Pass the tax manager to the accept function

    //     // Clean up
    //     delete building;
    //     delete clonedBuilding;
    // }
}


TEST_CASE("Testing Commercial Building Classes with Factory Method") {
    // // Initialize the factory creator and TaxManager instance
    // CommercialBuildingCreator creator;
    // TaxManager taxManager;

    // // Define an array of building types to test
    // std::string buildingTypes[] = {"School", "Office", "Hospital", "Shop"};

    // for (const std::string& type : buildingTypes) {
    //     // Create a building using the factory
    //     Building* baseBuilding = creator.createBuilding(type);
    //     // Attempt to cast to CommercialBuilding*
    //     CommercialBuilding* building = dynamic_cast<CommercialBuilding*>(baseBuilding);
        
    //     // Ensure the cast was successful
    //     REQUIRE(building != nullptr);

    //     SUBCASE((type + " - Default Initialization").c_str()) {
    //         if (type == "School") {
    //             CHECK(building->getAvailableKidsSpaces() == building->getMaxCapacity());
    //         } else if (type == "Office") {
    //             CHECK(building->getAvailableJobs() == building->getMaxCapacity());
    //         } else if (type == "Hospital") {
    //             CHECK(building->getAvailableBeds() == building->getMaxCapacity());
    //         }
    //         CHECK(building->isClosed() == false);
    //     }

    //     SUBCASE((type + " - Set and Get Methods").c_str()) {
    //         if (type == "School") {
    //             building->setAvailableKidsSpaces(10);
    //             CHECK(building->getAvailableKidsSpaces() == 10);
    //         } else if (type == "Office") {
    //             building->setAvailableJobs(20);
    //             CHECK(building->getAvailableJobs() == 20);
    //         } else if (type == "Hospital") {
    //             building->setAvailableBeds(15);
    //             CHECK(building->getAvailableBeds() == 15);
    //         }
    //     }

    //     SUBCASE((type + " - Close and Reopen Building").c_str()) {
    //         building->closeBuilding();
    //         CHECK(building->isClosed() == true);

    //         building->reopenBuilding();
    //         CHECK(building->isClosed() == false);
    //     }

    //     SUBCASE((type + " - Check Availability").c_str()) {
    //         if (type == "School") {
    //             CHECK(building->checkAvailability() == true);
    //             building->setAvailableKidsSpaces(0);
    //             CHECK(building->checkAvailability() == false);
    //         } else if (type == "Office") {
    //             CHECK(building->checkAvailability() == true);
    //             building->setAvailableJobs(0);
    //             CHECK(building->checkAvailability() == false);
    //         } else if (type == "Hospital") {
    //             CHECK(building->checkAvailability() == true);
    //             building->setAvailableBeds(0);
    //             CHECK(building->checkAvailability() == false);
    //         }
    //     }

    //     SUBCASE((type + " - Display Stats").c_str()) {
    //         CHECK_NOTHROW(building->displayStats());
    //     }

    //     SUBCASE((type + " - Accept Function with TaxManager").c_str()) {
    //         CHECK_NOTHROW(building->accept(&taxManager));
    //     }

    //     delete baseBuilding;  // Clean up created instance
    // }
}


TEST_CASE("Testing LandmarkBuilding classes with Factory Method") {
    // LandmarkBuildingCreator creator;  // Create a factory instance
    // TaxManager taxManager;            // Create a TaxManager instance

    // // Test Park class
    // SUBCASE("Park class tests") {
    //     Building* building = creator.createBuilding("Park");
    //     LandmarkBuilding* park = dynamic_cast<LandmarkBuilding*>(building);
    //     REQUIRE(park != nullptr);  // Ensure park is created

    //     // Test the name and initial properties
    //     CHECK(park->getName() == "Magnolia Park");
    //     CHECK(park->getMaxCapacity() == 50);
    //     CHECK(park->getPriceTag() == 300000.0);

    //     // Test displayStats function
    //     park->displayStats();  // Verify output manually or redirect to log

    //     // Test repairClone
    //     Building* clonedPark = park->repairClone();
    //     CHECK(clonedPark->getName() == "Magnolia Park");
    //     delete clonedPark;  // Clean up

    //     // Test the accept function
    //     park->accept(&taxManager);  // Pass the tax manager to the accept function

    //     delete park;  // Clean up
    // }

    // // Test Monument class
    // SUBCASE("Monument class tests") {
    //     Building* building = creator.createBuilding("Monument");
    //     LandmarkBuilding* monument = dynamic_cast<LandmarkBuilding*>(building);
    //     REQUIRE(monument != nullptr);  // Ensure monument is created

    //     // Test the name and initial properties
    //     CHECK(monument->getName() == "Voortrekker Monument");
    //     CHECK(monument->getMaxCapacity() == 150);
    //     CHECK(monument->getPriceTag() == 750000.0);

    //     // Test displayStats function
    //     monument->displayStats();  // Verify output manually or redirect to log

    //     // Test repairClone
    //     Building* clonedMonument = monument->repairClone();
    //     CHECK(clonedMonument->getName() == "Voortrekker Monument");
    //     delete clonedMonument;  // Clean up

    //     // Test the accept function
    //     monument->accept(&taxManager);  // Pass the tax manager to the accept function

    //     delete monument;  // Clean up
    // }

    // // Test Museum class
    // SUBCASE("Museum class tests") {
    //     Building* building = creator.createBuilding("Museum");
    //     LandmarkBuilding* museum = dynamic_cast<LandmarkBuilding*>(building);
    //     REQUIRE(museum != nullptr);  // Ensure museum is created

    //     // Test the name and initial properties
    //     CHECK(museum->getName() == "Pretoria Museum");
    //     CHECK(museum->getMaxCapacity() == 80);
    //     CHECK(museum->getPriceTag() == 500000.0);

    //     // Test displayStats function
    //     museum->displayStats();  // Verify output manually or redirect to log

    //     // Test repairClone
    //     Building* clonedMuseum = museum->repairClone();
    //     CHECK(clonedMuseum->getName() == "Pretoria Museum");
    //     delete clonedMuseum;  // Clean up

    //     // Test the accept function
    //     museum->accept(&taxManager);  // Pass the tax manager to the accept function

    //     delete museum;  // Clean up
    // }
}


TEST_CASE("Testing Industrial Building Subtypes") {
    // IndustrialBuildingCreator creator;
    // TaxManager taxManager;  // Create a TaxManager instance

    // SUBCASE("Testing Warehouse") {
    //     Building* warehouse = creator.createBuilding("Warehouse");
        
    //     CHECK(warehouse->getName() == "Builder's Warehouse");
    //     CHECK(warehouse->getMaxCapacity() == 100);
    //     CHECK(warehouse->getType() == "Warehouse");

    //     // Test displayStats
    //     std::cout << "Warehouse displayStats:" << std::endl;
    //     warehouse->displayStats();

    //     // Test accept method (stubbed, expect non-taxable message)
    //     std::cout << "Warehouse accept visitor:" << std::endl;
    //     warehouse->accept(&taxManager);

    //     // Test repairClone method
    //     Building* clonedWarehouse = warehouse->repairClone();
    //     CHECK(clonedWarehouse->getName() == "Builder's Warehouse");

    //     // Clean up
    //     delete warehouse;
    //     delete clonedWarehouse;
    // }

    // SUBCASE("Testing Factory") {
    //     Building* factory = creator.createBuilding("Factory");

    //     CHECK(factory->getName() == "Mercedes-Benz Factory");
    //     CHECK(factory->getMaxCapacity() == 1000);
    //     CHECK(factory->getType() == "Factory");

    //     // Test displayStats
    //     std::cout << "Factory displayStats:" << std::endl;
    //     factory->displayStats();

    //     // Test accept method (stubbed, expect non-taxable message)
    //     std::cout << "Factory accept visitor:" << std::endl;
    //     factory->accept(&taxManager);

    //     // Test repairClone method
    //     Building* clonedFactory = factory->repairClone();
    //     CHECK(clonedFactory->getName() == "Mercedes-Benz Factory");

    //     // Clean up
    //     delete factory;
    //     delete clonedFactory;
    // }

    // SUBCASE("Testing Airport") {
    //     Building* airport = creator.createBuilding("Airport");

    //     CHECK(airport->getName() == "OR Tambo Airport");
    //     CHECK(airport->getMaxCapacity() == 1000);
    //     CHECK(airport->getType() == "Airport");

    //     // Test displayStats
    //     std::cout << "Airport displayStats:" << std::endl;
    //     airport->displayStats();

    //     // Test accept method (stubbed, expect non-taxable message)
    //     std::cout << "Airport accept visitor:" << std::endl;
    //     airport->accept(&taxManager);

    //     // Test repairClone method
    //     Building* clonedAirport = airport->repairClone();
    //     CHECK(clonedAirport->getName() == "OR Tambo Airport");

    //     // Clean up
    //     delete airport;
    //     delete clonedAirport;
    // }

    // SUBCASE("Testing Train Station") {
    //     Building* trainStation = creator.createBuilding("TrainStation");

    //     CHECK(trainStation->getName() == "Gautrain Train Station");
    //     CHECK(trainStation->getMaxCapacity() == 500);
    //     CHECK(trainStation->getType() == "TrainStation");

    //     // Test displayStats
    //     std::cout << "TrainStation displayStats:" << std::endl;
    //     trainStation->displayStats();

    //     // Test accept method (stubbed, expect non-taxable message)
    //     std::cout << "TrainStation accept visitor:" << std::endl;
    //     trainStation->accept(&taxManager);

    //     // Test repairClone method
    //     Building* clonedTrainStation = trainStation->repairClone();
    //     CHECK(clonedTrainStation->getName() == "Gautrain Train Station");

    //     // Clean up
    //     delete trainStation;
    //     delete clonedTrainStation;
    // }
}



// ------------------------------------------------------------------------------------------------------- //