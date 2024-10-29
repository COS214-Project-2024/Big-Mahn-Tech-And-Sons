#include "DeptOfPR.h"
#include "DeptOfFinance.h"
#include "DeptOfUtilities.h"
#include "DeptOfHousing.h"

DeptOfPR::DeptOfPR(DeptOfHousing *housingDept, DeptOfUtilities *utilitiesDept, DeptOfFinance *financeDept)
{
   this->housing = housingDept; ///< access to the housing department/
   this->utilities = utilitiesDept; ///< access to the utilities department
   this->finance = financeDept; ///< access to the finance departt
}

void DeptOfPR::update(Building* building)
{
  notifyHousingToBuild();
}

void DeptOfPR::update(Citizen* citizen)
{
   notifyTaxman();
}

void DeptOfPR::notifyHousingToBuild() ///call create building w/ string
{
  // this->housing->addBuilding(NULL); ///<
 }

void DeptOfPR::notifyHousingToRemove(Building *building) // same
{
   //this->housing->removeBuilding(building);
}


void DeptOfPR::notifyUtilities()
{
 //  this->utilities->allocateResources(); //drey
}


void DeptOfPR::notifyTaxman()
{
 // Economic conditions
    bool healthyEconomy = this->finance->checkMoney(); // e.g., >2.5% GDP growth

    // Decision making to decrease taxes
    if (healthyEconomy) {
        this->finance->decreaseTaxes();
        std::cout << "Taxes have been lowered based on economic conditions and citizen feedback." << std::endl;


    // Decision making to increase taxes
    } else  { //check dept housing request funding function
        this->finance->increaseTaxes(10);
        std::cout << "Taxes have been increased to support government funding needs." << std::endl;

    }
}
