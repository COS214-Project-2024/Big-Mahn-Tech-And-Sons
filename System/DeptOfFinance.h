#ifndef DEPTOFFINANCE_H
#define DEPTOFFINANCE_H

#include <vector>
#include "Element.h"
#include "TaxManager.h"
#include "Building.h"
#include "Budget.h"
#include "Resource.h"

class DeptOfPR;
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
    void addElement(Element* element);
    void applyTaxes(TaxManager* visitor);
    void increaseTaxes(double percentage);
    void decreaseTaxes(double percentage);
    void allocateBudget(const std::string& department, double amount);
    bool assessEconomicImpact(); // this needs to return something e.g BOOL= is the economy good or not 
    bool checkMoney(); // check if in good financial position
    void collectTaxes();
    void setPR(DeptOfPR* PR);
};

#endif // DEPTOFFINANCE_H
