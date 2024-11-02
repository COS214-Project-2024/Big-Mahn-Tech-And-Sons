#include "Government.h"
#include "DeptOfTransportation.h"
#include "DeptOfFinance.h"
#include "DeptOfPR.h"
#include "DeptOfUtilities.h"
#include "DeptOfHousing.h"

#include "WaterSupply.h"
#include "PowerSupply.h"
#include "WasteManagement.h"
#include "Water.h"
#include "Power.h"

#include "PandemicCommand.h"
#include "IncreaseEconomy.h"
#include "LoadsheddingCommand.h"
#include "NaturalDisasterCommand.h"
#include "RecessionCommand.h"
#include "FestivalCommand.h"
#include "BabyBoom.h"

#include <cstdlib>
#include <ctime>

Government::Government()
{
   simulationIsActive = true;
   transport = DeptOfTransportation::getInstance();
   housing = new DeptOfHousing(2000000);
   Water *water = new Water("Sparkling", 10000);
   Power *power = new Power("Power", 100000);
   DeptOfUtilities*  waterSup = new WaterSupply("Water", 5000.02, 100000, water);
   DeptOfUtilities* powerSup = new PowerSupply("Eskom", 1539, 1335984, power);
  DeptOfUtilities* wasteSup = new WasteManagement("Waste", 1432, 3544.02);

   waterSup->setSuccessor(powerSup);
   powerSup->setSuccessor(wasteSup);

   TaxManager *taxMan = new TaxManager();
   finance = new DeptOfFinance(taxMan);
   PR = new DeptOfPR(housing, NULL, finance);

   string commercialTypes[] = {"Shop", "Office", "School", "Hospital"};
   string residentialTypes[] = {"House", "Apartment", "Estate"};
   string industrialTypes[] = {"Warehouse", "Factory", "Airport", "TrainStation"};
   string landmarkTypes[] = {"Park", "Monument", "Museum"};

   // Seed the random number generator
   srand(time(0));

   housing->createCommercialBuilding(commercialTypes[rand() % 4]);
   housing->createResidentialBuilding(residentialTypes[rand() % 3]);
   housing->createLandmarkBuilding(landmarkTypes[rand() % 3]);
   housing->createIndustrialBuilding(industrialTypes[rand() % 4]);
   // initialize starting citizens
   for (int i = 0; i < 10; i++)
   {
      string name = "ID: " + to_string(i) + " ";
      Citizen *c1 = new Citizen(name, 1, 1, PR);

      housing->getBuildings().at(i % 4)->addTenant(PR->getCitizen(i));
      // transport->add_Building()
   }

   // ADD BUILDINGS TO CITY GRID

   /*
      pandemic = new PandemicCommand(citizens);
      economicDownturn = new RecessionCommand(finance, citizens.at(1), housing.);
      naturalDisaster = new NaturalDisasterCommand()
      loadsheding = new LoadsheddingCommand();
      festive = new FestivalCommand();
      babyBoom = new BabyBoom();
      increaseEconomy = new IncreaseEconomy();

   */
}

void Government::addNewCitizens()
{
   
   int newCitizensCount = rand() % 5 + 1; // Random number of new citizens per year
   for (int i = 0; i < newCitizensCount; i++)
   {
      std::string name = "NewCitizen_" + std::to_string(this->PR->numCitizens());
      Citizen *newCitizen = new Citizen(name, 1, 1, PR);

      // Assign the new citizen to an available building
      if (!housing->getBuildings().empty())
      {
         housing->getBuildings().at(rand() % housing->getBuildings().size())->addTenant(newCitizen);
      }
   }
   
}

void Government::runSim()
{
   
   while (simulationIsActive)
   {
      // Trigger a random event from the available commands
      int eventIndex = rand() % 6; // Adjust based on the number of commands
      /*
      switch (eventIndex) {
          case 0: pandemic->execute(); break;
          case 1: economicDownturn->execute(); break;
          case 2: naturalDisaster->execute(); break;
          case 3: loadshedding->execute(); break;
          case 4: festive->execute(); break;
          case 5: babyBoom->execute(); break;
          case 6: increaseEconomy->execute(); break;
      }
       */
      // Simulate year progression
      for (int i = 0; i < PR->numCitizens(); i++)
      {
         PR->getCitizen(i)->getOlder();
      }

      addNewCitizens();

      // Check for any active simulation exit conditions
      if (/* some condition to end the simulation */ true) {
         stopSim();
      }

   }
}

void Government::handleCitizenNeeds()
{
}

void Government::stopSim()
{
   simulationIsActive = false;
}
