/**
 * @file FestivalCommand.h
 * @brief Defines the FestivalCommand class for organizing and managing city-wide festivals.
 */

#ifndef FESTIVAL_COMMAND_H
#define FESTIVAL_COMMAND_H

#include "EventsCommand.h"
#include "DeptOfUtilities.h"
#include "Citizen.h"
#include "DeptOfPR.h"

/**
 * @class FestivalCommand
 * @brief Concrete command class for handling city festivals and managing their impact on citizens and resources.
 */
class FestivalCommand : public EventsCommand
{
private:
    DeptOfUtilities *utilities; ///< Receiver for managing utility consumption during the festival.
    Citizen *citizens;          ///< Receiver for boosting citizen satisfaction.
    DeptOfPR *deptOfPR;         ///< Receiver for festival promotion and public engagement.

public:
    /**
     * @brief Constructs a FestivalCommand with the necessary department receivers.
     * @param u Pointer to DeptOfUtilities, managing resource usage during the festival.
     * @param c Pointer to Citizens, representing the population whose satisfaction is affected.
     * @param pr Pointer to DeptOfPR, responsible for promoting the festival.
     */
    FestivalCommand(DeptOfUtilities *u, Citizen *c, DeptOfPR *pr);

    /**
     * @brief Executes all festival-related commands in sequence.
     *
     * This includes increasing utility usage, boosting citizen satisfaction, and promoting the festival.
     */
    void execute() override;

private:
    /**
     * @brief Increases utility consumption during the festival to accommodate higher demand.
     *
     * Uses DeptOfUtilities to handle increased power, water, and other resource needs during the event.
     */
    void increaseUtilityConsumption();

    /**
     * @brief Boosts citizen happiness by organizing the festival.
     *
     * This function engages the Citizens class to simulate increased satisfaction from festival activities.
     */
    void boostCitizenHappiness();

    /**
     * @brief Promotes the city-wide festival through the public relations department.
     *
     * Engages the DeptOfPR to raise awareness and excitement about the festival, increasing turnout.
     */
    void promoteFestival();
};

#endif // FESTIVAL_COMMAND_H
