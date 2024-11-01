#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

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


#include "PandemicCommand.h"

TEST_CASE("Citizen initialisation")
{
    // DepartmentOfPR*  pr = new DepartmentOfPR(NULL,NULL, NULL,NULL);
    Citizen *person = new Citizen("one", 50, 10, 10, NULL);

    CHECK(person->getAge() == 1);
    for (int i = 0; i < 20; i++)
    {
        person->getOlder();
    }
    CHECK(person->getStateName() == "Adult");

    person->increaseSatisfaction(20);
    CHECK(person->getSatisfactionLevelName() == "Happy");

    person->decreaseSatisfaction(50);
    CHECK(person->getSatisfactionLevelName() == "Sad");
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

    Citizen citizen("John Doe", 50.0, 10, 20, prDept);

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

    Citizen citizen("Alice Smith", 50.0, 15, 25, prDept);

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

    Citizen citizen("Bob Brown", 50.0, 10, 20, prDept);
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
      DeptOfHousing *housingDept = new DeptOfHousing(100000);
    Water *water = new Water("Sparkling", 10000);
    DeptOfUtilities *utilitiesDept = new WaterSupply("Water", 5000.02, 100000, water);
    TaxManager *taxMan = new TaxManager();
    DeptOfFinance *financeDept = new DeptOfFinance(taxMan);
    DeptOfPR prDept(housingDept, utilitiesDept, financeDept);
    // Create mock citizens
    Citizen* citizen1 = new Citizen("Alice",50, 2, 4,&prDept);
    Citizen* citizen2 = new Citizen("Bob", 45, 2, 4,&prDept);
    Citizen* citizen3 = new Citizen("Charlie", 25, 2, 4,&prDept);


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
}


TEST_CASE("Government test") {
    

}