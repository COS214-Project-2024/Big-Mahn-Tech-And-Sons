#include "visitHousing.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Resource.h"
#include "Budget.h"
#include <iostream>

double totalTax = 0;
bool visitHousing::visitResidentialBuilding(Building *building)
{
    if(building)
    {
    TaxManager::visitBuildingForCitizen(building);
    return true;
    }
    return false;
}

bool visitHousing::visitCommercialBuilding(CommercialBuilding *building)
{
    if(building)
    {
    TaxManager::visitBuildingForBuilding(building);
    return true;
    }
    return false;
}

bool visitHousing::visitBudget(Budget *budget)
{
    if(budget)
    {
    TaxManager::visitBudget(budget);
    return true;
    }
    return false;
}