#include "Citizen.h"
#include "Child.h"
#include "Adult.h"
#include "Pensioner.h"
#include "SatisfactionState.h"
#include "NeutralState.h"


#include "AirTrans.h"
#include "Train.h"
#include "Walk.h"
#include "PublicTrans.h"

#include "CityGrid.h"



#include <random>

Citizen::Citizen(const std::string &nam, double happiness,int x , int y, DeptOfPR *PR)
{
   name = nam;
   satisfaction = happiness;
   this->PR = PR;

   age = 1;
   this->state = new ChildState();

   ///< Set this->budget to a random double between 15000 and 200000
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_real_distribution<> distr(15000, 200000);
   this->budget = distr(gen);

   this->health = 100.0;
   this->satisfaction = 50.0;
   this->satisState =  new NeutralState();
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
      this->PR->update(this);
      
   }
   ///< @todo update state
   updateState();
}

void Citizen::notifyPR()
{
   if((getSatisfactionLevelName() == "Neutral" || getSatisfactionLevelName() == "Sad") && getBudget()/100000 * 100 < 0.6 ) { // problem with finances
      this->PR->update(this);
   } else if(this)
}

int Citizen::getAge()
{
   return this->age;
}

double Citizen::getHealth()
{
    return this->health;
}

double Citizen::getSatisfactionLevel()
{
   return this->satisfaction;
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
   this->satisState->handle(this); // check if satisfaction state needs to be changed
}

void Citizen::increaseSatisfaction(double amount)
{
   this->satisfaction += amount;
   this->satisState->handle(this); // check if satisfaction state needs to be changed

}



void Citizen::setThreshhold(int age)
{
   this->ageThreshhold = age;
}

int Citizen::getThreshold()
{
   return this->ageThreshhold;
}

std::string Citizen::getStateName() const
{
   return this->state->getStateName();
}

std::string Citizen::getSatisfactionLevelName() const
{
   return this->satisState->getStateName();
}

void Citizen::setSatisfactionState(SatisfactionState *state)
{
   if(this->satisState) {
      delete this->satisState;
   }

   this->satisState = state;
}

void Citizen::setState(CitizenState *state)
{
   if(this->state) {
      delete this->state;
   }

   this->state = state;
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

void Citizen::travelTo(Building *destination, CityGrid *citi, int x, int y, const std::string &Building)
{
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
