#include "DeptOfPR.h"
#include "DeptOfFinance.h"
#include "DeptOfUtilities.h"
#include "DeptOfHousing.h"
#include "Request.h"

DeptOfPR::DeptOfPR(DeptOfHousing *housingDept, DeptOfUtilities *utilitiesDept, DeptOfFinance *financeDept)
{
   this->housing = housingDept;     ///< access to the housing department/
   this->utilities = utilitiesDept; ///< access to the utilities department
   this->finance = financeDept;     ///< access to the finance depart

   housingDept->setPR(this);
   utilitiesDept->setPR(this);
   financeDept->setPR(this);
}

void DeptOfPR::update(Building *building)
{
   if (building->getCurrentOccupants() >= building->getMaxCapacity())
   { // building asking
    //  std::cout << "Building is at maximum capacity. Check to add new building or move to another building\n";

      notifyHousingToBuild(building->getType());
   }
   else if (building->getElectricityMeterBox() == 0)
   {
      notifyUtilities("power", building); 
   }
   else if (building->getWaterMeterBox() == 0)
   {
      notifyUtilities("water", building);
   }
   else if (building->getWasteAmount() > 3000)
   {
      notifyUtilities("waste", building);
   }

}
void DeptOfPR::update(Citizen *citizen)
{
   if ((citizen->getStateName() == "Pensioner" && citizen->getAge() >= citizen->getThreshold()) || citizen->getHealth() == 0)
   {
      // remove citizen from all records
      if (citizen->getCurrentLocation()->removeTenant(citizen) == false)
      {
         // citizen was not found, thus hunt him down, trying to cheat death
        // cout << "Citizen not found, on the run :(\n";
      }
      else
      {
         // citizen was found, thus remove him from all records
         this->killCitizen(citizen);
      }

      return;
   } else if ((citizen->getSatisfactionLevelName() == "Neutral" || citizen->getSatisfactionLevelName() == "Sad") && citizen->getBudget() / 100000 * 100 < 0.6)
   {
      notifyTaxman("Citizen");
   }
   else if (citizen->getBudget() > 100000)
   { // citizen is rich
      notifyHousingToBuild("Park");
   }
}

bool DeptOfPR::notifyHousingToBuild(string type) // change to BOOL
{
   if (type == "House" || type == "Apartment" || type == "Estate")
   {
      cout << "Department of PR Notify Housing to build " << type << " for citizen\n";
      this->housing->createResidentialBuilding(type);
      return true;
   }
   else if (type == "Shop" || type == "Office" || type == "Hospital" || type == "School")
   {
     cout << "Department of PR Notify Housing to build " << type << " for citizen\n";
      this->housing->createCommercialBuilding(type);
      return true;
   }
   else if (type == "Factory" || type == "Warehouse" || type == "TrainStation" || type == "Airport")
   {
      cout << "Department of PR Notify Housing to build " << type << " for citizen\n";
      this->housing->createIndustrialBuilding(type);
      return true;
   }
   else if (type == "Park" || type == "Museum" || type == "Monument")
   {
      cout << "Department of PR Notify Housing to build " << type << " for citizen\n";
      this->housing->createLandmarkBuilding(type);
      return true;
   }
   else
   {
      cout << "Department of PR could not Notify Housing to build " << type << " for citizen\n";
      return false;
   }
}

void DeptOfPR::addCitizen(Citizen *citizen)
{
   this->citizens.push_back(citizen);
}

Citizen *DeptOfPR::getCitizen(int i)
{
   return this->citizens.at(i);
}

int DeptOfPR::numCitizens()
{
   return this->citizens.size();
}

void DeptOfPR::killCitizen(Citizen *citizen)
{
   this->citizens.erase(std::remove(this->citizens.begin(), this->citizens.end(), citizen), this->citizens.end());
}

void DeptOfPR::notifyHousingToRemove(string type) // CHANGE TO BOOL
{
   this->housing->removeBuildingByName(type);
}

bool DeptOfPR::notifyUtilities(string request, Building *building)
{
   Request *req;
   if (request == "water")
   {
      req = new Request(request, building, 1000);

      if (!this->utilities->handleRequest(*req))
      {
         cout << "Unable to handle water request.\n";
         delete req;
         return false;
      }
   } else if (request == "power")
   {
      req = new Request("Power", building, 50000);

      if (!this->utilities->handleRequest(*req))
      {
         cout << "Unable to handle power request.\n";
          delete req;
         return false;
      }
   } else if (request == "waste")
   {
      req = new Request(request, building, 300);

      if (!this->utilities->handleRequest(*req))
      {
         cout << "Unable to handle waste request.\n";
          delete req;
         return false;
      }
   }

   cout << "Department of PR mediated resource request to Department of Utility.\n";

   return true;

}

   bool DeptOfPR::notifyTaxman(string deptName) // add else if checks to make sure only departments are passed in, CHANGE TO BOOL
   {
      // Economic conditions
      bool healthyEconomy = this->finance->checkMoney(); // e.g., >2.5% GDP growth

      if (deptName != "Housing" || deptName != "Citizen" || deptName != "Finance" || deptName != "Utility" || deptName != "Building")
      {
         return false;
      }

      // Decision making to decrease taxes
      if (deptName == "Citizen" && healthyEconomy)
      {
         this->finance->decreaseTaxes();
         cout << "Department of PR mediated decrease tax request to Department of Finance\n";
         return true;
         // Decision making to increase taxes
      }
      else if (deptName == "Housing")
      { // check dept housing request funding function
         this->finance->increaseTaxes(10);
         this->finance->allocateBudget("Housing", 100000);
         cout << "Department of PR mediated funding request of Department of Housing to Department of Finance\n";

         /*
         bool request = finance->allocateBudget(deptName, 2000000); //<< allocate budget to change to budget
         if(request) {
            housing->addBudget(2000000);
         } else {
            std::cout << "Budget allocation failed." << std::endl;
         }
         */
         return true;
      }
      else if (deptName == "Utility")
      {
         this->finance->allocateBudget("Utility", 10000);
         cout << "Department of PR mediated funding request of Department of Utilities to Department of Finance\n";

         return true;
      }

      return false;
   }

   /**
    * @brief Promotes the city-wide festival to citizens and other departments.
    */
   void DeptOfPR::promoteFestival()
   {
      std::cout << "🎉 The city is excited to announce an upcoming festival! 🎉" << std::endl;

      // Notify each citizen about the festival
      for (Citizen *citizen : citizens)
      {
         citizen->increaseSatisfaction(10); // Increase satisfaction for attending the festival
         std::cout << "Notifying " << citizen->getName() << " about the festival!" << std::endl;
      }

      // notify utilities for increased demand
      for(Building* b : this->housing->getBuildings()) {
         notifyUtilities("power", b);
         notifyUtilities("waste", b);
      }
      // Print an overall summary of the festival promotion
      std::cout << "Festival promotion completed successfully!" << std::endl;
   }