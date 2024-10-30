#include "Citizen.h"
#include "Child.h"
#include "Adult.h"
#include "Pensioner.h"
#include "SatisfactionState.h"
#include "NeutralState.h"

//
#include "AirTrans.h"
#include "Train.h"
#include "Walk.h"
#include "PublicTrans.h"



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
  // this->go =  NULL;
   this->ageThreshhold = 0;
}


// Citizen::~Citizen()
// {
//    // if(state) {
//    //    delete state;
//    // }

//    // if(modeOfTransport) {
//    //    delete modeOfTransport;
//    // }

//    // // if(go) {
//    // //    delete go;
//    // // }
// }

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
   if((getSatisfactionLevelName() == "Neutral" || getSatisfactionLevelName() == "Sad") && getBudget()/100000 * 100 < 0.6 ) { // problem with finances
      this->PR->update(this);
   } 
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

void Citizen::evacuate()
{
   // leave building
}

void Citizen::returnToCity()
{
}

void Citizen::becomeUnemployed()
{
   //this->workLocation = NULL;
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

// Node *Citizen::getCurrentLocation() const
// {
//    return this->currentLocation;
// }

// void Citizen::setCurrentLocation(Node *location)
// {
//    if(location) {
//       this->currentLocation;
//    }
// }

// void Citizen::travelTo(Node *destination)
// {
//    //this->modeOfTransport->execute(this, destination); //<TODO
// }

// void Citizen::travelWithStrategy(RoadNetWork *roadNetwork)
// {
//    //this->modeOfTransport->
// }
