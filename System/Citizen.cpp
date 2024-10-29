#include "Citizen.h"
#include "Child.h"
#include "Adult.h"
#include "Pensioner.h"

//
#include "AirTrans.h"
#include "Train.h"
#include "Walk.h"
#include "PublicTrans.h"



#include <random>

Citizen::Citizen(const std::string &nam, double happiness, Building *location, Building *work, Building *home, DepartmentOfPR *PR)
{
   name = nam;
   satisfaction = happiness;
   currentLocation = location;
   workLocation = work;
   homeLocation = home;
   this->PR = PR;

   age = 1;
   this->state = new ChildState();

   // Set this->budget to a random double between 15000 and 200000
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_real_distribution<> distr(15000, 200000);
   this->budget = distr(gen);

   this->health = 100.0;
   this->satisfaction = 50.0;

   this->modeOfTransport = NULL;
   this->go =  NULL;
   this->ageThreshhold = 0;
}

Citizen::~Citizen()
{
   if(state) {
      delete state;
   }

   if(modeOfTransport) {
      delete modeOfTransport;
   }

   if(go) {
      delete go;
   }
}

void Citizen::getOlder()
{
   age++;
   if(this->getStateName() == "Pensioner" && age >= ageThreshhold) {
      // kill TODO
      
   }
   ///< @todo update state
   updateState();
}

void Citizen::notifyPR()
{
   if(true) { // problem with finances
      this->PR->notifyTaxman();
   } else if(true) { // problem with utility
      this->PR->notifyUtilities();
   }
}

int Citizen::getAge()
{
   return this->age;
}

double Citizen::getBudget() const
{
   return this->budget;
}

void Citizen::work(double amount)
{
   this->budget += amount;
}

bool Citizen::Spend(double amount)
{
   this->budget -= amount;
}

void Citizen::decreaseHealth(double percentage)
{
   this->health -= percentage;
}

void Citizen::increaseHealth(double percentage)
{
   this->health += percentage;
}

void Citizen::decreaseSatisfaction(double amount)
{
   this->satisfaction -= amount;
}

void Citizen::evacuate()
{
   // leave building
}

void Citizen::returnToCity()
{
}

void Citizen::becomeUnemployed()
{
   this->workLocation = NULL;
}

void Citizen::getNewJob()
{
   ///< @todo search through grid and find space in relevant Building and set that as job
}

void Citizen::setThreshhold(int age)
{
   this->ageThreshhold = age;
}

std::string Citizen::getStateName() const
{
   return this->state->getStateName();
}

void Citizen::setState(CitizenState *state)
{
   if(state) {
      this->state = state;
   }
}

void Citizen::updateState()
{
   this->state->handle(this);
}

ModeOfTrans *Citizen::getModeOfTransport() const
{
   return this->modeOfTransport;
}

void Citizen::setModeOfTransport(ModeOfTrans *mode)
{
   if(mode) {
      this->modeOfTransport =  mode;
   }
}

Building *Citizen::getCurrentLocation() const
{
   return this->currentLocation;
}

void Citizen::setCurrentLocation(Building *location)
{
   if(location) {
      this->currentLocation;
   }
}

void Citizen::travelTo( Building* destination , CityGrid * citi , int x, int y , const std::string &Building) {


   int distance = citi->getDistance(x,y,Building);

    // Determine available transport modes based on distance
    std::vector<ModeOfTrans*> availableModes;
    Walk* walk = new Walk();
    availableModes.push_back(walk); // Always available

    if (distance > 5)
      {  
         PublicTrans* publicT = new PublicTrans();
         availableModes.push_back(publicT);
      }
    if (distance > 15)
    {
         Train* train = new Train();
         availableModes.push_back(train);
    } 
    if (distance > 30)
    { 
      AirTrans* air = new AirTrans();
      availableModes.push_back(air);
    }
    
    
    std::cout << "Available transport modes for distance " << distance << "km:\n";
    for (size_t i = 0; i < availableModes.size(); i++) {
        std::cout << i + 1 << ". " << availableModes[i]->getName() 
                 << " (Cost: R" << availableModes[i]->getCost() << ")\n";
    }
    
    // Get user choice
    int choice;
    std::cout << "Choose transport mode (1-" << availableModes.size() << "): ";
    std::cin >> choice;
    
    if (choice > 0 && choice <= availableModes.size()) {
        ModeOfTrans* selectedMode = availableModes[choice - 1];
        double totalCost = (distance * 4.5) + selectedMode->getCost();
        
        if (this->Spend(totalCost)) {
            // Execute transport
            selectedMode->execute();
            
            // Update locations
            currentLocation->removeTenant(this);
            destination->addTenant(this);
            currentLocation = destination;
            
            std::cout << "Successfully traveled to " << destination->getName() << "\n";
        } else {
            std::cout << "Insufficient funds for travel\n";
        }
    }
    
    // Cleanup
    for (auto mode : availableModes) {
        delete mode;
    }
}
