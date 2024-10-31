/**
 * @file FestivalCommand.cpp
 * @brief Implements the FestivalCommand class for organizing and managing city-wide festivals.
 */

#include "FestivalCommand.h"

/**
 * @brief Constructs a FestivalCommand with the specified department receivers.
 * @param u Pointer to DeptOfUtilities, used to manage resource usage during the festival.
 * @param c Pointer to Citizens, representing the population affected by the festival.
 * @param pr Pointer to DeptOfPR, responsible for promoting the festival.
 */
FestivalCommand::FestivalCommand(DeptOfUtilities* u, Citizen* c, DeptOfPR* pr)
    : utilities(u), citizens(c), deptOfPR(pr) {}

/**
 * @brief Executes all festival-related commands in sequence.
 * 
 * This includes promoting the festival, boosting citizen happiness, and increasing utility consumption.
 */
void FestivalCommand::execute() {
    promoteFestival();
    boostCitizenHappiness();
    increaseUtilityConsumption();
}

/**
 * @brief Increases utility consumption during the festival to accommodate higher demand.
 * 
 * Calls the `increaseUsage()` function from the DeptOfUtilities class.
 */
void FestivalCommand::increaseUtilityConsumption() {
    if (utilities) {
        utilities->increaseUsage();
    }
}

/**
 * @brief Boosts citizen happiness by organizing the festival.
 * 
 * Calls the `increaseSatisfaction()` function from the Citizens class to reflect the positive impact.
 */
void FestivalCommand::boostCitizenHappiness() {
    if (citizens) {
        citizens->increaseSatisfaction(10.0); // Assume a fixed boost to citizen satisfaction
    }
}

/**
 * @brief Promotes the city-wide festival through the PR department.
 * 
 * Calls the `promoteFestival()` function from the DeptOfPR to increase awareness.
 */
void FestivalCommand::promoteFestival() {
    if (deptOfPR) {
         deptOfPR->promoteFestival();
    }
}
