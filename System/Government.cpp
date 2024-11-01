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

Government::Government()
{
   simulationIsActive = true;

   // housing = new DeptOfHousing(100000);
   // Water *water = new Water("Sparkling", 10000);
   // Power *power = new Power("Power", 100000);
   // this->waterSupply = new WaterSupply("Water", 5000.02, 100000, water);
   // this->powerSupply = new PowerSupply("Eskom", 1539, 1335984, power);
   // this->wasteSupply = new WasteManagement("Waste", 1432, 3544.02);

   // waterSupply->setSuccessor(powerSupply);
   // powerSupply->setSuccessor(wasteSupply);

   // TaxManager *taxMan = new TaxManager();
   // finance = new DeptOfFinance(taxMan);
   // PR = new DeptOfPR(housing, waterSupply, finance);

   // initialize starting citizens

   for (int i = 0; i < 100000; i++) {

   }
   /*
   pandemic = new PandemicCommand();
   economicDownturn = new RecessionCommand();
   naturalDisaster = new NaturalDisasterCommand();
   loadshedding = new LoadsheddingCommand();
   festive = new FestivalCommand();
   babyBoom = new BabyBoom();
   increaseEconomy = new IncreaseEconomy();

   */
}

void Government::runSim()
{
   while (simulationIsActive)
   {
   }
}

void Government::handleCitizenNeeds()
{
}

void Government::stopSim()
{
   simulationIsActive = false;
}
