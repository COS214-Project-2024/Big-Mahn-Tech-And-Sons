#include "DeptOfFinance.h"
#include "TaxManager.h"
#include "Building.h"
#include "Budget.h"
#include "DeptOfPR.h"
#include "Resource.h"

DeptOfFinance::DeptOfFinance(TaxManager *taxManager) : taxManager(taxManager) {}

void DeptOfFinance::collectTaxes(Building *building)
{
    std::string buildingType = building->getType();
    if (buildingType == "Estate" || buildingType == "Apartment" || buildingType == "House") {
        std::cout << "Collecting taxes from residential building: " << buildingType << std::endl;
        building->accept(taxManager); // Collect tax for Residential buildings
    } 
    else if (buildingType == "Shop" || buildingType == "Hospital" || buildingType == "Office" || buildingType == "School") {
        std::cout << "Collecting taxes from commercial building: " << buildingType << std::endl;
        building->accept(taxManager); // Collect tax for Commercial buildings
    } 
    else {
        std::cout << "Skipping non-taxable building type: " << buildingType << std::endl;
    }
}

void DeptOfFinance::allocateBudget(const std::string& department, double amount) {
    if (budget->getTotalBudget() >= amount) {
        std::cout << "Allocating " << amount << " to " << department << std::endl;
        budget->setTotalBudget(budget->getTotalBudget() - amount);
    } else {
        std::cerr << "Insufficient funds to allocate to " << department << std::endl;
    }
}

void DeptOfFinance::addElement(Element *element)
{
    elements.push_back(element);
}

void DeptOfFinance::applyTaxes(TaxManager *visitor)
{
    for (auto &element : elements)
    {
        element->accept(visitor);
    }
}

void DeptOfFinance::increaseTaxes(double percentage)
{
    // Convert percentage to a decimal for calculation
    double factor = 1 + (percentage / 100.0);

    taxManager->setTaxRate(taxManager->getTaxRate() * factor);
}

void DeptOfFinance::decreaseTaxes(double percentage)
{
    // TODO: need to add some logic here later
    // Check for valid percentage
    if (percentage < 0 || percentage > 100) {
        
        std:: cout << "Percentage must be between 0 and 100." << std::endl;
    }

    // Convert percentage to a decimal for calculation
    double factor = 1 - (percentage / 100.0);

    // Decrease each tax rate: remember this is now a variable 
    taxManager->setTaxRate(taxManager->getTaxRate() * factor);
}

bool DeptOfFinance::assessEconomicImpact()
{
    // Return true if the economy is in a healthy state
    return budget->getTotalBudget() > 100000; //can adjust later
}

bool DeptOfFinance::checkMoney()
{
    return false;
}

void DeptOfFinance::collectTaxes()
{
}

void DeptOfFinance::display() {
    cout << "Department of Finance statistics\n";
    cout << "--------------------------------\n";
    cout << "Finance budget" << this->taxManager->getGovernmentBudget() << std::endl;
}

void DeptOfFinance::setPR(DeptOfPR *PR)
{
    this->PR = PR;
}

// void DeptOfFinance::collectTaxes() {
//     for (Element* element : elements) {
//         element->accept(taxManager); // Apply visitor to each building
//     }
// }

// void DeptOfFinance::applyTaxes(TaxManager* visitor) {
//     for (auto& element : elements) {
//         element->accept(visitor);
//     }
// }

// void DeptOfFinance::allocateBudget(const std::string& department, double amount) {
//     Resource resource;
//     budget->accept(&resource);  // This will add to budget via the Resource visitor
//     if (budget->getTotalBudget() >= amount) {
//         budget->setTotalBudget(budget->getTotalBudget() - amount);
//     }
// }
