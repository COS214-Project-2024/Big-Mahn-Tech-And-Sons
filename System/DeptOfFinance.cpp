
#include "DeptOfFinance.h"
#include "TaxManager.h"
#include "Building.h"
#include "Budget.h"
#include "DeptOfPR.h"

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
    elements.push_back(element);
}

void DeptOfFinance::applyTaxes(TaxManager *visitor)
{
    for (auto &element : elements) {
        element->accept(visitor);
    }
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

void DeptOfFinance::setPR(DeptOfPR *PR)
{
    this->PR = PR;
}

// this is a function to check the state
