// BabyBoomingEvent.h
#ifndef BABY_BOOMING_EVENT_H
#define BABY_BOOMING_EVENT_H

#include "EventsCommand.h"
#include "Building.h"
#include "Citizen.h"
#include <vector>

class BabyBoomingEvent : public EventsCommand {
private:
    Building* building;                   // Target building to add new citizens
    std::vector<Citizen*>* citizensList;  // Reference to the city's citizens list


public:
    BabyBoomingEvent()= default;
    BabyBoomingEvent(Building* building, std::vector<Citizen*>* citizens);
    void execute() override;
};
#endif // BABY_BOOMING_EVENT_H
