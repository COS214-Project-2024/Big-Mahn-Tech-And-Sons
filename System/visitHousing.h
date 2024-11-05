#ifndef VISITHOUSING_H
#define VISITHOUSING_H

#include "TaxManager.h"
#include "Building.h"
#include "Citizen.h"

class visitHousing : public TaxManager
{
public:
    static double totalTax;
    bool visitBuildingForCitizens(Building *building);
    bool visitBuildingForBuilding(Building *building);
    bool visitBudget(Budget *budget);

    // void visitBudget(Budget *budget, double);
};

#endif // VISITHOUSING_H

