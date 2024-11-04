// visitHousing.h
#ifndef VISITHOUSING_H
#define VISITHOUSING_H


#include "TaxManager.h"

class visitHousing : public TaxManager {
private:
    double collectedTax = 0;
public:
    void visitResidentialBuilding(ResidentialBuilding* building) override {
        //collectedTax += building->calculateTax();
    }

    void visitCommercialBuilding(CommercialBuilding* building) override {
        //collectedTax += building->calculateTax();
    }

    void visitBudget(Budget* budget) override {
        budget->setTotalBudget(budget->getTotalBudget() + collectedTax);
        collectedTax = 0;  // Reset after transfer
    }
    
    double getCollectedTax() const { return collectedTax; }
};


#endif // VISITHOUSING_H