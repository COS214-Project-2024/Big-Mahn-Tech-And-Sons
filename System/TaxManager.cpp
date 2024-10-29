#include "TaxManager.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Budget.h"

TaxManager::TaxManager() : collectedTaxes(0), governmentBudget(0) {}

// Sets the tax rate for different types of taxes
void TaxManager::setTaxRate(const std::string& type, float rate) {
    taxRates[type] = rate; 
}

void TaxManager::collect(ResidentialBuilding* building) {
    for(int i = 0; i < building->getTenants().size(); i++) {
         collectedTaxes += calculateCitizenTax(building->getTenants().at(i));
    }
}

void TaxManager::collect(CommercialBuilding* building) {
    collectedTaxes += calculateBusinessTax(building);
}


// Calculates the tax for a citizen (for residential building)
float TaxManager::calculateCitizenTax(Citizen* citizen) {
    // Example calculation, assuming income tax
    return citizen->getBudget() * taxRates["IncomeTax"];
}

// Calculates the tax for a commercial building
float TaxManager::calculateBusinessTax(CommercialBuilding* building) {
    // Example calculation, assuming property tax
    return 1 * taxRates["PropertyTax"]; // waiting for getReveue from commercial building
}

// Collects taxes from all citizens and commercial buildings
void TaxManager::collectTaxes() {
    collectedTaxes = 0;
    for (Citizen* citizen : citizenList) {
        collectedTaxes += calculateCitizenTax(citizen);
    }
    for (CommercialBuilding* building : commercialBuildings) {
        collectedTaxes += calculateBusinessTax(building);
    }
    governmentBudget += collectedTaxes;
}

// Distributes budget to different departments
void TaxManager::distributeBudget(const std::string& department, float allocation) {
    // Example distribution logic
    governmentBudget -= allocation;
}

// Visitor method for residential building
void TaxManager::visitResidentialBuilding(ResidentialBuilding* residentialBuilding) {
    for (Citizen* citizen : citizenList) {
        collectedTaxes += calculateCitizenTax(citizen);
    }
}

// Visitor method for commercial building
void TaxManager::visitCommercialBuilding(CommercialBuilding* commercialBuilding) {
    collectedTaxes += calculateBusinessTax(commercialBuilding);
}

// Visitor method for budget resource
void TaxManager::visitBudget(Budget* budget) {
    budget->setTotalBudget(governmentBudget); // Allocate the collected taxes to the budget
}

void TaxManager::applyTaxChanges()
{
}

// Other getter/setter methods
float TaxManager::getCollectedTaxes() const {
    return collectedTaxes;
}

float TaxManager::getGovernmentBudget() const {
    return governmentBudget;
}

void TaxManager::setCitizenList(const std::vector<Citizen*>& citizens) {
    citizenList = citizens;
}

void TaxManager::setCommercialBuildings(const std::vector<CommercialBuilding*>& businesses) {
    commercialBuildings = businesses;
}

void TaxManager::setResidentialBuildings(const std::vector<ResidentialBuilding*>& buildings) {
    residentialBuildings = buildings;
}
