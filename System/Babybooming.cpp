// BabyBoomingEvent.cpp
#include "BabyBooming.h"
#include <iostream>

BabyBoomingEvent::BabyBoomingEvent(Building *building, std::vector<Citizen *> *citizens)
    : building(building), citizensList(citizens) {}

void BabyBoomingEvent::execute()
{
    int addedChildren = 5; // Number of children to add

    for (int i = 0; i < addedChildren; ++i)
    {
        // Create a new child citizen
        Citizen *newChild = new Citizen("Child_" + std::to_string(i + 1), nullptr);
        building->addTenant(newChild);     // Add to the building
        citizensList->push_back(newChild); // Add to the city's citizens list
        std::cout << "Added new child: " << newChild->getName() << " to " << building->getName() << "\n";
    }
}
