// visitHousing.h
#ifndef VISITHOUSING_H
#define VISITHOUSING_H

#include "TaxManager.h"

class visitHousing : public TaxManager {
public:
    visitHousing();
    void visitResidentialBuilding(ResidentialBuilding* building) override;
    void visitCommercialBuilding(CommercialBuilding* building) override;
    void visitBudget(Budget* budget) override;
};

#endif // VISITHOUSING_H