#include "visitHousing.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Resource.h"
#include "Budget.h"
#include <iostream>

double totalTax = 0;
void visitHousing::visitResidentialBuilding(Building *building)
{
    TaxManager::visitBuildingForCitizen(building);
}

void visitHousing::visitCommercialBuilding(CommercialBuilding *building)
{
    
    TaxManager::visitBuildingForBuilding(building);
}

void visitHousing::visitBudget(Budget *budget)
{
    TaxManager::visitBudget(budget);
}