/** 
 * * @author u21824241_(add yours guys)
 */
#ifndef DEPTOFFINANCE_H
#define DEPTOFFINANCE_H

#include <vector>
#include "Element.h"
#include "TaxManager.h"
#include "Building.h"
#include "Budget.h"

class DeptOfPR;
/**
 * @class DeptOfFinance
 * @brief Client class that interacts with different tax policies.
 */
class DeptOfFinance {
private:
    std::vector<Element*> elements; /**< List of elements in the city */
    TaxManager* taxManager;
    DeptOfPR* PR;
    Budget* budget;
public:
    DeptOfFinance(TaxManager* taxManager);

    void collectTaxes(Building *building);

    //void allocateBudget();

    DeptOfFinance(TaxManager*, Budget*);

    /**
     * @brief Adds an element to the list.
     * 
     * @param element The element to add.
     */ 
    void addElement(Element* element);

    /**
     * @brief Applies tax policies by accepting a visitor.
     * 
     * @param visitor The visitor (TaxManager) that applies tax policies.
     */
    void applyTaxes(TaxManager* visitor);

    /**
     * @brief Increases taxes by a certain percentage.
     * @param percentage The percentage by which taxes are increased.
     */
    void increaseTaxes(double percentage);

    /**
     * @brief Decreases taxes to alleviate financial pressure.
     */
    void decreaseTaxes(double percentage);

    /**
     * @brief Allocates budget to a specific department.
     * @param department The name of the department.
     * @param amount The amount to be allocated.
     */
    void allocateBudget(const std::string& department, double amount);

    /**
     * @brief Assesses the economic impact of an event on the city's finances.
     */
    bool assessEconomicImpact(); // this needs to return something e.g BOOL= is the economy good or not 

    bool checkMoney(); // check if in good financial position

    void collectTaxes();

    void setPR(DeptOfPR* PR);
};

#endif // DEPTOFFINANCE_H
