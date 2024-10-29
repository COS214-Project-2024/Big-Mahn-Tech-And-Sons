#include "DeptOfPR.h"
#include "DeptOfFinance.h"
#include "DepartmentUtilities.h"
#include "HousingDept.h"

DepartmentOfPR::DepartmentOfPR(HousingDept *housingDept, DepartmentUtilities *utilitiesDept, DeptOfFinance *financeDept)
{
   this->housing = housingDept; ///< access to the housing department/
   this->utilities = utilitiesDept; ///< access to the utilities department
   this->finance = financeDept; ///< access to the finance department
}

void DepartmentOfPR::update(Building* building)
{
  notifyHousingToBuild();
}

void DepartmentOfPR::update(Citizen* citizen)
{
   notifyTaxman();
}

void DepartmentOfPR::notifyHousingToBuild()
{
   this->housing->addBuilding(NULL); ///< TODO
}

void DepartmentOfPR::notifyHousingToRemove(Building *building)
{
   this->housing->removeBuilding(building);
}

void DepartmentOfPR::notifyUtilities()
{
   this->utilities->allocateResources();
}

void DepartmentOfPR::notifyTaxman()
{
 // Economic conditions
    bool healthyEconomy = this->finance->checkMoney(); // e.g., >2.5% GDP growth

    // Decision making to decrease taxes
    if (healthyEconomy) {
        this->finance->decreaseTaxes();
        std::cout << "Taxes have been lowered based on economic conditions and citizen feedback." << std::endl;

    // Decision making to increase taxes
    } else  {
        this->finance->increaseTaxes(10);
        std::cout << "Taxes have been increased to support government funding needs." << std::endl;

    }
}
