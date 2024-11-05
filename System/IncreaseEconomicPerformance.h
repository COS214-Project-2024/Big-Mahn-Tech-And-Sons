// IncreaseEconomicPerformance.h
#ifndef INCREASE_ECONOMIC_PERFORMANCE_H
#define INCREASE_ECONOMIC_PERFORMANCE_H

#include "EventsCommand.h"
#include "Citizen.h"
#include "Building.h"
#include <vector>

/**
 * @class IncreaseEconomicPerformance
 * @brief Represents an event command that boosts economic performance.
 *
 * This class inherits from EventsCommand and is responsible for implementing
 * the logic that increases the economic performance of a city by benefiting
 * its citizens and commercial buildings during a specific event.
 */
class IncreaseEconomicPerformance : public EventsCommand
{
private:
    std::vector<Citizen *> *citizensList;         /**< Pointer to the list of all citizens to receive the economic boost */
    std::vector<Building *> *commercialBuildings; /**< Pointer to the list of all commercial buildings */

public:
    /**
     * @brief Default constructor for the IncreaseEconomicPerformance class.
     */
    IncreaseEconomicPerformance() = default;

    /**
     * @brief Constructs an IncreaseEconomicPerformance event command with specified citizens and buildings.
     *
     * Initializes the event command with the given lists of citizens and commercial buildings,
     * which will be impacted by the economic performance increase.
     *
     * @param citizens A pointer to a vector containing pointers to Citizen objects
     *                 that will receive the economic boost.
     * @param buildings A pointer to a vector containing pointers to Building objects
     *                  that will be affected by the economic performance increase.
     */
    IncreaseEconomicPerformance(std::vector<Citizen *> *citizens, std::vector<Building *> *buildings);

    /**
     * @brief Executes the economic performance increase event.
     *
     * This method implements the logic to boost the economy by affecting the
     * specified citizens and commercial buildings. It may involve updating
     * citizens' financial status or enhancing building performance.
     */
    void execute() override;
};

#endif // INCREASE_ECONOMIC_PERFORMANCE_H
