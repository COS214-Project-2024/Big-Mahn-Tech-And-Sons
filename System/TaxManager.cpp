// TaxManager.cpp
#include "TaxManager.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Budget.h"
#include "Citizen.h"

TaxManager::TaxManager() : collectedTaxes(0), governmentBudget(0),taxRate(0.0) {}

void TaxManager::setTaxRate(double rate) {
    taxRate = rate;
}

double TaxManager::getTaxRate() const {
    return taxRate;
}

void TaxManager::collect(ResidentialBuilding *building)
{
    for (const auto &tenant : building->getTenants())
    {
        collectedTaxes += calculateCitizenTax(tenant);
    }
}

void TaxManager::collect(CommercialBuilding *building)
{
    collectedTaxes += calculateBusinessTax(building);
}

float TaxManager::calculateCitizenTax(Citizen *citizen)
{
    return citizen->getBudget() * taxRates["IncomeTax"];
}

float TaxManager::calculateBusinessTax(CommercialBuilding *building)
{
    return building->getNetWorth() * taxRates["PropertyTax"];
}

void TaxManager::visitResidentialBuilding(ResidentialBuilding *building)
{
    collect(building);
}

void TaxManager::visitCommercialBuilding(CommercialBuilding *building)
{
    collect(building);
}

// Add tax collection to Budget and reset collectedTaxes for a fresh cycle
void TaxManager::visitBudget(Budget *budget)
{
    budget->setTotalBudget(budget->getTotalBudget() + collectedTaxes);
    collectedTaxes = 0; // Reset after updating the budget
}

float TaxManager::getCollectedTaxes() const
{
    return collectedTaxes;
}

float TaxManager::getGovernmentBudget() const
{
    return governmentBudget;
}

void TaxManager::collectTaxes()
{
    collectedTaxes = 0.0; // Reset before collection
    for (double income : incomes){
        collectedTaxes += income * taxRate;
    }
    std::cout << "Total collected taxes: " << collectedTaxes << std::endl;
}

// Improved checkMoney function
bool TaxManager::checkMoney()
{
    double stabilityThreshold = 1000000.0; // Example threshold for financial stability

    if (collectedTaxes >= stabilityThreshold)
    {
        std::cout << "The economy is financially stable." << std::endl;
        return true;
    }
    else
    {
        std::cout << "The economy is NOT financially stable." << std::endl;
        return false;
    }
}

void TaxManager::applyCollectedTaxesToBudget(Budget& budget) {
    double collectedTaxes = getCollectedTaxes(); // Assuming this method exists
    // budget.addFunds(collectedTaxes);
    // resetCollectedTaxes(); // Reset for the next tax cycle
}