// Budget.h
#ifndef BUDGET_H
#define BUDGET_H

#include "Element.h"
#include <string>

class TaxManager;

class Budget : public Element {
private:
    float totalBudget;
    double funds;

public:
    Budget(float initialBudget);
    ~Budget();
    void reportStatus() const;
    float getTotalBudget() const;
    void addFunds(double amount);
    void setTotalBudget(float budget);
    virtual void accept(TaxManager* visitor) override ;
};

#endif // BUDGET_H