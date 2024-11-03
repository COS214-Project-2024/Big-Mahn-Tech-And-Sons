// IncreaseEconomicPerformance.h
#ifndef INCREASE_ECONOMIC_PERFORMANCE_H
#define INCREASE_ECONOMIC_PERFORMANCE_H

#include "EventsCommand.h"
#include "Citizen.h"
#include "Building.h"
#include <vector>

class IncreaseEconomicPerformance : public EventsCommand {
private:
    std::vector<Citizen*>* citizensList;            // List of all citizens to receive the economic boost
    std::vector<Building*>* commercialBuildings;    // List of all commercial buildings

public:
    IncreaseEconomicPerformance() = default;
    IncreaseEconomicPerformance(std::vector<Citizen*>* citizens, std::vector<Building*>* buildings);
    void execute() override;
};
#endif // INCREASE_ECONOMIC_PERFORMANCE_H
