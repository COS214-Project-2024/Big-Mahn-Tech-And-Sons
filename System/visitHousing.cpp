#include "visitHousing.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Budget.h"
#include <iostream>

void visitHousing::visitResidentialBuilding(ResidentialBuilding* building) {
    double tax = building->getNetWorth() * 0.05;  // Example 5% tax
    collectedTaxes += tax;
    std::cout << "Collected " << tax << " from residential building." << std::endl;
}

void visitHousing::visitCommercialBuilding(CommercialBuilding* building) {
    double tax = building->getNetWorth() * 0.1;  // Example 10% tax
    collectedTaxes += tax;
    std::cout << "Collected " << tax << " from commercial building." << std::endl;
}

void visitHousing::visitBudget(Budget* budget) {
    budget->setTotalBudget(budget->getTotalBudget() + collectedTaxes);
    collectedTaxes = 0; // Reset for next tax cycle
}
