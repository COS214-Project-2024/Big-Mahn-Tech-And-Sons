#include "DeptOfPR.h"
#include "DeptOfFinance.h"
#include "DeptOfUtilities.h"
#include "DeptOfHousing.h"

DeptOfPR::DeptOfPR(DeptOfHousing *housingDept, DeptOfUtilities *utilitiesDept, DeptOfFinance *financeDept)
{
   this->housing = housingDept;     ///< access to the housing department/
   this->utilities = utilitiesDept; ///< access to the utilities department
   this->finance = financeDept;     ///< access to the finance depart
}

void DeptOfPR::update(Building *building)
{
   if (true) { // building asking
      notifyHousingToBuild(building->getType());
   } else if (true)
   {
      notifyUtilities();// check with drey
   }
}

void DeptOfPR::update(Citizen *citizen)
{
   if(citizen->getStateName() == "Pensioner" && citizen->getAge() >= citizen->getThreshold()) {
      // remove citizen from all records

      if(citizen->getCurrentLocation()->removeTenant(citizen) == false) {
         // citizen was not found, thus hunt him down, trying to cheat death
      }

      return;
   } else if((citizen->getSatisfactionLevelName() == "Neutral" || citizen->getSatisfactionLevelName() == "Sad") && citizen->getBudget()/100000 * 100 < 0.6 ) {
      notifyTaxman("Citizen");
   }
   
   
}

void DeptOfPR::notifyHousingToBuild(string type)
{
   if (type == "House" || type == "Apartment" || type == "Estate") {
      this->housing->createResidentialBuilding(type);
   } else if (type == "Shop" || type == "Office" || type == "Hospital" || type == "School")
   {
      this->housing->createCommercialBuilding(type);
   } else if (type == "Factory" || type == "Warehouse" || type == "TrainStation" || type == "Airport")
   {
      this->housing->createIndustrialBuilding(type);
   } else if (type == "Park" || type == "Museum" || type == "Monument")
   {
      this->housing->createLandmarkBuilding(type);
   } else {
      cout << "Building not added\n";
   }
}

void DeptOfPR::notifyHousingToRemove(string type)
{
   this->housing->removeBuildingByName(type);
}

void DeptOfPR::notifyUtilities()
{
   this->utilities->handleRequest(); //check with drey
}

void DeptOfPR::notifyTaxman(string deptName) // add else if checks to make sure only departments are passed in
{
   // Economic conditions
   bool healthyEconomy = this->finance->checkMoney(); // e.g., >2.5% GDP growth

   if(deptName != "Housing" || deptName != "Citizen" || deptName != "Finance" || deptName != "Utility" || deptName != "Building" ) {
      return;
   }

   // Decision making to decrease taxes
   if (deptName == "Citizen" && healthyEconomy) {
      this->finance->decreaseTaxes();
      std::cout << "Taxes have been lowered based on economic conditions and citizen feedback." << std::endl;
      // Decision making to increase taxes
   } else if(deptName == "Housing") { // check dept housing request funding function
      this->finance->increaseTaxes(10);
      bool request = finance->allocateBudget(deptName, 2000000); //<< allocate budget to change to budget
      if(request) {
         housing->addBudget(2000000);
      } else {
         std::cout << "Budget allocation failed." << std::endl;
      }
      
      std::cout << "Taxes have been increased to support government funding needs." << std::endl;
   }
}
