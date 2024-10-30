
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

void DeptOfFinance::addElement(Element *element)
{
}

void DeptOfFinance::applyTaxes(TaxManager *visitor)
{
}

void DeptOfFinance::increaseTaxes(double percentage)
{
}

void DeptOfFinance::decreaseTaxes()
{
}

void DeptOfFinance::allocateBudget(const std::string &department, double amount)
{
}

void DeptOfFinance::cutFunding(const std::string &department)
{
}

void DeptOfFinance::assessEconomicImpact()
{
}

bool DeptOfFinance::checkMoney()
{
    return false;
}

void DeptOfFinance::collectTaxes()
{
}

// this is a function to check the state
