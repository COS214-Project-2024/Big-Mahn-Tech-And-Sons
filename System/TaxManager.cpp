// TaxManager.cpp
#include "TaxManager.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Budget.h"
#include "Citizen.h"

TaxManager::TaxManager() : collectedTaxes(0), governmentBudget(0) {}

void TaxManager::setTaxRate(const std::string& type, float rate) {
    taxRates[type] = rate;
}

void TaxManager::collect(ResidentialBuilding* building) {
    for(const auto& tenant : building->getTenants()) {
        collectedTaxes += calculateCitizenTax(tenant);
    }
}

void TaxManager::collect(CommercialBuilding* building) {
    collectedTaxes += calculateBusinessTax(building);
}

float TaxManager::calculateCitizenTax(Citizen* citizen) {
    return citizen->getBudget() * taxRates["IncomeTax"];
}

float TaxManager::calculateBusinessTax(CommercialBuilding* building) {
    return building->getNetWorth() * taxRates["PropertyTax"];
}

void TaxManager::visitResidentialBuilding(ResidentialBuilding* building) {
    collect(building);
}

void TaxManager::visitCommercialBuilding(CommercialBuilding* building) {
    collect(building);
}

void TaxManager::visitBudget(Budget* budget) {
    budget->setTotalBudget(budget->getTotalBudget() + collectedTaxes);
}

float TaxManager::getCollectedTaxes() const {
    return collectedTaxes;
}

float TaxManager::getGovernmentBudget() const {
    return governmentBudget;
}