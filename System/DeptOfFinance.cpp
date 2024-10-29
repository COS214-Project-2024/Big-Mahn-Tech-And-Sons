#include "DeptOfFinance.h"
#include "TaxManager.h"
#include "Building.h"
#include "Budget.h"

DeptOfFinance::DeptOfFinance(TaxManager* taxManager) : taxManager(taxManager) {}

void DeptOfFinance::collectTaxes(Building* building) {
    building->accept(taxManager); // Visitor visiting the building
    taxManager->collect(building);
}

void DeptOfFinance::allocateBudget() {
    budget->accept(taxManager); // Visitor visiting the budget
}

// this is a function to check the state
