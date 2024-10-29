#include "Resource.h"
#include "Budget.h"
#include <iostream>

Resource::Resource(const std::string& resourceName, double resourceAmount)
    : name(resourceName), amount(resourceAmount) {}

std::string Resource::getName() const {
    return name;
}

double Resource::getAmount() const {
    return amount;
}

void Resource::addAmount(double additionalAmount) {
    amount += additionalAmount;
}

void Resource::removeAmount(double removalAmount) {
    if (removalAmount <= amount) {
        amount -= removalAmount;
    } else {
        std::cerr << "Error: Removal amount exceeds available resource." << std::endl;
    }
}

void Resource::visitBudget(Budget* budget) {
    // Transfer a portion of the resource amount to the budget
    double transferAmount = amount * 0.1; // Example: transfer 10%
    budget->setTotalBudget(budget->getTotalBudget() + transferAmount);
    std::cout << "Transferred " << transferAmount << " from " << name << " to budget." << std::endl;
}
