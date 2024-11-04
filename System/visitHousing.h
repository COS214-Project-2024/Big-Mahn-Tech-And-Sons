#ifndef VISITHOUSING_H
#define VISITHOUSING_H

#include "TaxManager.h"
#include "Building.h"

class visitHousing : public TaxManager {
public:
    void visitResidentialBuilding(ResidentialBuilding* building);
    void visitCommercialBuilding(CommercialBuilding* building);
    void visitBudget(Budget* budget);
};

#endif // VISITHOUSING_H
