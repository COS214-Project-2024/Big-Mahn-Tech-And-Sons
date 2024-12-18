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
#include "Building.h"
#include "CityGrid.h"
#include "GoToCommand.h"

#include <random>

Citizen::Citizen(const std::string &nam, DeptOfPR *PR)
{
   name = nam;
   satisfaction = 50;
   this->PR = PR;
   this->PR->addCitizen(this);
   age = 1;
   this->state = new ChildState();

   ///< Set this->budget to a random double between 15000 and 200000
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_real_distribution<> distr(15000, 200000);
   this->budget = distr(gen);

   this->health = 100.0;
   this->satisState = new NeutralState();
   this->modeOfTransport = NULL;
   this->ageThreshold = 0;

   this->homeLocation = NULL;
   this->workLocation = NULL;
   this->currentLocation = NULL;
}

Citizen::~Citizen()
{
   if (state)
   {
      delete state;
   }

   if (satisState)
   {
      delete satisState;
   }
}

void Citizen::getOlder()
{
   age++;
   if ((this->getStateName() == "Pensioner" && age >= ageThreshold) || this->getHealth() <= 0)
   {
      // kill TODO
      this->PR->update(this);
      return;
   }
   updateState();
}

void Citizen::notifyPR()
{
   this->PR->update(this);
}

int Citizen::getAge()
{
   return this->age;
}

std::string Citizen::getName() const
{
   return this->name;
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
   if (amount > this->budget)
   {
      return false;
   }
   this->budget -= amount;
   return true;
}

void Citizen::display()
{
   std::cout << "====                ====" << std::endl;
   std::cout << "Name: " << this->name << std::endl;
   std::cout << "Age: " << this->age << std::endl;
   std::cout << "Health: " << this->health << std::endl;
   std::cout << "Satisfaction: " << this->getSatisfactionLevelName() << std::endl;
   std::cout << "Budget: " << this->budget << std::endl;
   std::cout << "====                ====" << std::endl;
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

void Citizen::setThreshold(int age)
{
   this->ageThreshold = age;
}

int Citizen::getThreshold()
{
   return this->ageThreshold;
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
   if (this->satisState)
   {
      delete this->satisState;
   }

   this->satisState = state;
}

void Citizen::setState(CitizenState *state)
{
   if (this->state)
   {
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
   if (mode)
   {
      this->modeOfTransport = mode;
   }
}

Building *Citizen::getCurrentLocation() const
{
   return currentLocation;
}

Building *Citizen::getHomeLocation() const
{
   return homeLocation;
}

Building *Citizen::getWorkLocation() const
{
   return workLocation;
}

void Citizen::setWork(Building *building)
{
   if (building)
   {
      this->workLocation = building;
   }
}

void Citizen::setHome(Building *building)
{
   if (building)
   {
      this->homeLocation = building;
   }
}

void Citizen::setCurrent(Building *building)
{
   if (building)
   {
      this->currentLocation = building;
   }
}

void Citizen::travelTo(Building *destination)
{
   DeptOfTransportation *dept = DeptOfTransportation::getInstance();
   int distance = dept->get_distance(currentLocation,destination);
   
   // come operate here.
   //
   if(distance == 0) {
      cout << "There is no road to " << destination->getName() << std::endl;
      return;
   }
   if(distance == -1) {
      cout<< " Current building does not exist \n";
      return;
   }
   if(distance== -2) {
      cout<< " Destination building does not exist \n";
      return;
   }
   

   std::vector<ModeOfTrans *> availableModes;
   Walk *walk = new Walk();
   availableModes.push_back(walk); // Always available
   if (distance > 5)
   {
      PublicTrans *publicT = new PublicTrans();
      availableModes.push_back(publicT);
   }
   if (distance > 15)
   {
      Train *train = new Train();
      availableModes.push_back(train);
   }
   if (distance > 30)
   {
      AirTrans *air = new AirTrans();
      availableModes.push_back(air);
   }

   std::cout << "Available transport modes for distance " << distance << "km:\n";
   for (size_t i = 0; i < availableModes.size(); i++)
   {
      std::cout << i + 1 << ". " << availableModes[i]->getName()
                << " (Cost: R" << availableModes[i]->getCost() << ")\n";
   }

   // Get user choice
   int choice;
   std::cout << "Choose transport mode (1-" << availableModes.size() << "): ";
   std::cin >> choice;

   if (choice > 0 && choice <= availableModes.size())
   {
      ModeOfTrans *selectedMode = availableModes[choice - 1];
      if (selectedMode->getName() == "Walk")
      {
         double totalCost = selectedMode->getCost();
      }
      else
      {
         double totalCost = (distance * 4.5) + selectedMode->getCost();

         if (this->Spend(totalCost))
         {
            // Execute transport
            selectedMode->execute();

            // Update locations
            currentLocation->removeTenant(this);

            destination->addTenant(this);
            currentLocation = destination;

            std::cout << "Successfully traveled to " << destination->getName() << "\n";
         }
         else
         {
            std::cout << "Insufficient funds for travel\n";
         }
      }
   }
}

void Citizen::setCurrentLocation(Building *b)
{
   currentLocation = b;
}
