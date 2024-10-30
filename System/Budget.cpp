#include "Budget.h"
#include "Element.h"
#include "TaxManager.h"
#include <iostream>

Budget::Budget(float initialBudget) : totalBudget(initialBudget) {}

// Budget::~Budget() {}

void Budget::reportStatus() const {
    std::cout << "Current budget: " << totalBudget << std::endl;
}

float Budget::getTotalBudget() const {
    return totalBudget;
}

void Budget::setTotalBudget(float budget) {
    totalBudget = budget;
    std::cout << "Updated budget to: " << totalBudget << std::endl;
}

void Budget::accept(TaxManager* visitor) {
    visitor->visitBudget(this);
}
