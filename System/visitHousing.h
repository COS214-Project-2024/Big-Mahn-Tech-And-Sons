#ifndef VISITHOUSING_H
#define VISITHOUSING_H

#include "TaxManager.h"
#include "Building.h"
#include "Citizen.h"

class visitHousing : public TaxManager
{
public:
    static double totalTax;
    void visitResidentialBuilding(Building *building);
    void visitCommercialBuilding(CommercialBuilding *building);

    void visitBudget(Budget *budget);

    // void visitBudget(Budget *budget, double);
};

#endif // VISITHOUSING_H
