#include <iostream>
#include "Citizen.h"
#include "visitHousing.h"
#include "Budget.h"
#include "LandmarkBuildingCreator.h"
#include "IndustrialBuildingCreator.h"
#include "ResidentialBuildingCreator.h"
#include "CommercialBuildingCreator.h"
#include "DeptOfFinance.h"

void buildingsTest();
void taxManTest();

int main()
{
    std::cout << "------------------------- Starting basic testing -------------------------" << std::endl;
    buildingsTest();
    taxManTest();

    return 0;
}

void buildingsTest()
{
    std::cout << "Testing Residential Buildings :_________________ \n";
    ResidentialBuildingCreator *resident1 = new ResidentialBuildingCreator();
    Building *estate = resident1->createBuilding("Estate");

    std::cout << "\t ============= Testing Functionality of Residential Buildings: ==========\n";
    std::cout << " _~_~_~_Estate_~_~_~_~ \t \n";
    estate->displayStats();
    std::cout << "Occupants: " << estate->getCurrentOccupants() << std::endl;
    std::cout << "MeterBox for Electricity :  " << estate->getElectricityMeterBox() << std::endl;
    std::cout << "MeterBox for Water: " << estate->getWaterMeterBox() << std::endl;
    std::cout << "Their usages:  " << estate->getElectricityUsage() << " , " << estate->getWaterUsage() << std::endl;
    std::cout << "Name of building:  " << estate->getName() << std::endl;
    std::cout << "Building of type: " << estate->getType() << std::endl;
    std::cout << "Networth of :  " << estate->getNetWorth() << std::endl;
    std::cout << "A priceTag of:  " << estate->getPriceTag() << std::endl;
}

void taxManTest()
{
    std::cout << "\t ============= Testing Functionality of Tax Manager: ==========\n";
    // 1. BUDGET SITUATION
    std:: cout << "Setting the Overall City Budget" << std::endl;
    Budget cityBudget(10000);
    cityBudget.reportStatus();

    // 2. BUILDINGS SETUP
    // Test specific building types
    ResidentialBuildingCreator residentCreator;
    Building* estate = residentCreator.createBuilding("Estate");
    Building* apartment = residentCreator.createBuilding("Apartment");

    CommercialBuildingCreator commercialCreator;
    Building* shop = commercialCreator.createBuilding("Shop");
    Building* hospital = commercialCreator.createBuilding("Hospital");
    
    // 3. TAX MANAGER AND FINANCE DEPARTMENT
    TaxManager taxMan;
    DeptOfFinance financeDept(&taxMan);

    // 4. TAXES SITUATION
    // Collect taxes from the Residential and Commercial buildings
    std:: cout << "Collecting taxes from citizens" << std::endl;
    // Should collect from residential
    financeDept.collectTaxes(estate);
    financeDept.collectTaxes(apartment);
    std:: cout << "Done collecting taxes from citizens" << std::endl;
    std:: cout << "Collecting taxes from commercials" << std::endl;
    // Should collect from commercial
    financeDept.collectTaxes(shop);
    financeDept.collectTaxes(hospital);   
    std:: cout << "Done collecting taxes from commercials" << std::endl;

    // 5. BUDGET UPDATE AFTER TAX COLLECTION
    std:: cout << "Updating the Overall City Budget" << std::endl;
    cityBudget.accept(&taxMan); // Pass budget to tax manager for final tax allocation
    cityBudget.reportStatus();  // Report budget status after tax collection
}

