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
    float totalBudget; /**< The total budget available for management. */

public:
    /**
     * @brief Constructs a Budget with an initial budget amount.
     * @param initialBudget The initial budget value to be set.
     */
    Budget(float initialBudget);

    // ~Budget(); // Uncomment if the destructor is defined in the implementation

    /**
     * @brief Reports the current budget status, displaying relevant budget details.
     */
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

    /**
     * @brief Accepts a visitor for tax management or other visitor pattern operations.
     * @param visitor A pointer to the TaxManager visitor.
     */
    void accept(TaxManager *visitor) override;
};

#endif // BUDGET_H
