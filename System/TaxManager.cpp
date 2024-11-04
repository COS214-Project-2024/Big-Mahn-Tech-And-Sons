// TaxManager.cpp
#include "TaxManager.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Budget.h"
#include "Citizen.h"

TaxManager::TaxManager() : collectedTaxes(0), governmentBudget(0), taxRate(0.0) {}

void TaxManager::setTaxRate(double rate)
{
    taxRate = rate;
}

double TaxManager::getTaxRate() const
{
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

double TaxManager::calculateCitizenTax(Citizen *citizen)
{
    return citizen->getBudget() * 0.05;
}

double TaxManager::calculateBusinessTax(CommercialBuilding *building)
{
    return building->getAnnualRevenue() * 0.10;
}

// void TaxManager::visitResidentialBuilding(ResidentialBuilding *building)
// {
//     collect(building);
// }

// void TaxManager::visitCommercialBuilding(CommercialBuilding *building)
// {
//     collect(building);
// }

void TaxManager::visitBuildingForCitizen(Building *building)
{
    
    ResidentialBuilding *residentialBuilding = dynamic_cast<ResidentialBuilding *>(building);
    if (residentialBuilding)
    {
        for (Citizen *citizen : residentialBuilding->getOccupants())
        {
            if (citizen)
            {
                double tax = calculateCitizenTax(citizen);
                collectedTaxes += tax;
                citizen->Spend(tax);
            }
        }
    }
    else
    {
        std::cerr << "Error: Building is not a residential building." << std::endl;
    }
}

void TaxManager::visitBuildingForBuilding(Building *building)
{
    
    CommercialBuilding *commercialBuilding = dynamic_cast<CommercialBuilding *>(building);
    if (commercialBuilding)
    {
        double tax = calculateBusinessTax(commercialBuilding);
        collectedTaxes += tax;
        commercialBuilding->setAnnualRevenue(commercialBuilding->getAnnualRevenue() - tax); // Deduct from revenue
    }
    else
    {
        std::cerr << "Error: Building is not a commercial building." << std::endl;
    }
}

void TaxManager::visitBudget(Budget *budget)
{

    budget->addFunds(collectedTaxes);
    std::cout << "Added " << collectedTaxes << " to the budget." << std::endl;
    collectedTaxes = 0;
}

// void TaxManager::applyCollectedTaxesToBudget(Budget &budget)
// {
//     budget.addFunds(collectedTaxes);
//     collectedTaxes = 0; // Reset after applying
// }

// Add tax collection to Budget and reset collectedTaxes for a fresh cycle
// void TaxManager::visitBudget(Budget *budget)
// {
//     budget->setTotalBudget(budget->getTotalBudget() + collectedTaxes);
//     collectedTaxes = 0; // Reset after updating the budget
// }

double TaxManager::getCollectedTaxes() const
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
    for (double income : incomes)
    {
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

// void TaxManager::applyCollectedTaxesToBudget(Budget &budget)
// {
//     double collectedTaxes = getCollectedTaxes(); // Assuming this method exists
//     // budget.addFunds(collectedTaxes);
//     // resetCollectedTaxes(); // Reset for the next tax cycle
// }

double TaxManager::setTaxCollected(double collectedTaxes)
{
    collectedTaxes += collectedTaxes;

    return collectedTaxes;
}
