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


/**
     * @brief Promotes the city-wide festival to citizens and other departments.
     */
    void DeptOfPR :: promoteFestival() {
        std::cout << "🎉 The city is excited to announce an upcoming festival! 🎉" << std::endl;
        
        // Notify each citizen about the festival
        for (Citizen* citizen : citizens) {
            citizen->increaseSatisfaction(10);  // Increase satisfaction for attending the festival
            std::cout << "Notifying " << citizen->getName() << " about the festival!" << std::endl;
        }

        // Optionally notify other departments about the festival
        notifyUtilities(); // Ensure utilities are prepared for increased demand
      //   notifyHousingToRemove(nullptr); // You can specify logic if needed, not sure if this is needed 
        
        // Print an overall summary of the festival promotion
        std::cout << "Festival promotion completed successfully!" << std::endl;
    }
