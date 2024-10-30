#include "DeptOfFinance.h"
#include "TaxManager.h"
#include "Building.h"
#include "Budget.h"

DeptOfFinance::DeptOfFinance(TaxManager* taxManager) : taxManager(taxManager) {}

void DeptOfFinance::collectTaxes(Building* building) {
    std::string buildingType = building->getType();

    if (buildingType == "Residential" || buildingType == "Commercial") {
        building->accept(taxManager);  // Visitor visiting the building
    } else {
        std::cout << "Skipping non-taxable building type: " << buildingType << std::endl;
    }
}

void DeptOfFinance::allocateBudget() {
   // budget->accept(taxManager); // Visitor visiting the budget
}

// this is a function to check the state

