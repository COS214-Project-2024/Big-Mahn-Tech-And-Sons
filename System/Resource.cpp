#include "Resource.h"
#include "Budget.h"
#include <iostream>

Resource::Resource(const std::string& name, double amount) 
    : name(name), amount(amount) {} 

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



void Resource::visitCommercialBuilding(CommercialBuilding* building) 
{
    //
}


void Resource::visitResidentialBuilding(Building* building) 
{
    //
}


void Resource::visitBudget(Budget* budget , double amount) 
{
    
}
