// IncreaseEconomicPerformance.cpp
#include "IncreaseEconomicPerformance.h"
#include "CommercialBuilding.h"
#include <iostream>

IncreaseEconomicPerformance::IncreaseEconomicPerformance(std::vector<Citizen *> *citizens, std::vector<Building *> *buildings)
    : citizensList(citizens), commercialBuildings(buildings) {}

void IncreaseEconomicPerformance::execute()
{
    double increaseAmount = 5000; // Economic boost amount

    // Boost each citizen's budget
    for (Citizen *citizen : *citizensList)
    {
        citizen->work(increaseAmount);
        std::cout << citizen->getName() << " received a budget increase of " << increaseAmount << "\n";
    }

    // Reopen closed commercial buildings
    for (Building *building : *commercialBuildings)
    {
        if (auto *commercial = dynamic_cast<CommercialBuilding *>(building))
        {
            if (commercial->isClosed())
            {
                commercial->reopenBuilding();
                std::cout << "Reopened building: " << commercial->getName() << "\n";
            }
        }
    }
}
