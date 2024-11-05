/**
 * @file Budget.h
 * @brief Declaration of the Budget class, representing the financial budget for tax and expenditure management.
 */

#ifndef BUDGET_H
#define BUDGET_H

#include "Element.h"
#include <string>

class TaxManager;

/**
 * @class Budget
 * @brief Represents the budget for a building, allowing financial management through tax calculations and visitor pattern operations.
 */
class Budget : public Element
{
private:
    float totalBudget;
    double funds;

public:
    /**
     * @brief Constructs a Budget with an initial budget amount.
     * @param initialBudget The initial budget value to be set.
     */
    Budget(float initialBudget);
    ~Budget();
    void reportStatus() const;

    /**
     * @brief Gets the total budget amount.
     * @return The current total budget.
     */
    float getTotalBudget() const;

    /**
     * @brief Sets the total budget amount.
     * @param budget The new budget amount to be set.
     */
    void setTotalBudget(float budget);
    virtual void accept(TaxManager* visitor) override ;
};

#endif // BUDGET_H