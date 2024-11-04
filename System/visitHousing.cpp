#include "visitHousing.h"
#include "ResidentialBuilding.h"
#include "Budget.h"
#include <iostream>

// void visitHousing::visitBuilding(Building* building) {
//     ResidentialBuilding* residential = dynamic_cast<ResidentialBuilding*>(building);
//     if (residential) {
//         // Tax collection logic for residential buildings
//         double tax = residential->getNetWorth() * 0.05; // Assume 5% tax on net worth
//         std::cout << "Collected " << tax << " from residential building." << std::endl;
//         // This tax would then be transferred to the budget in the visitBudget method
//     }
// }

// void visitHousing::visitBudget(Budget* budget) {
//     // Add the collected taxes to the budget
//     budget->setTotalBudget(budget->getTotalBudget() + 500); // Example addition
//     std::cout << "Added taxes to budget." << std::endl;
// }

visitHousing::visitHousing() : collectedTax(0)
{
}

void visitHousing::visitResidentialBuilding(ResidentialBuilding *building)
{
    double tax = residential.getNetWorth() * 0.05;
    residential.applyTax(tax);
    collectedTax += tax; // Accumulate collected tax
}

void visitHousing::visitCommercialBuilding(CommercialBuilding *building)
{
    // No action here, as this visitor is for residential buildings
}

void visitHousing::visitBudget(Budget *budget)
{
    // this should add the taxes to the budget
    budget.allocateFunds(collectedTax);
}

double visitHousing::getCollectedTax() const {
        return collectedTax;
    }