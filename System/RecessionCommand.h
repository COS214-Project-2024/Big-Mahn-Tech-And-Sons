/**
 * @file RecessionCommand.h
 * @brief Defines the RecessionCommand class for handling city-wide recession events.
 */

#ifndef RECESSION_COMMAND_H
#define RECESSION_COMMAND_H

#include "EventsCommand.h"
#include "DeptOfFinance.h"
#include "Citizen.h"
#include "CommercialBuilding.h"
#include <vector>

/**
 * @class RecessionCommand
 * @brief Command class for handling recession events within the city.
 *
 * This class is responsible for managing the economic impact of recession events, including
 * financial adjustments, citizen satisfaction management, and the status of commercial buildings.
 * It coordinates actions across various departments to mitigate the negative effects of a recession.
 */
class RecessionCommand : public EventsCommand {
private:
    DeptOfFinance* finDept;                            /**< Pointer to the Department of Finance for managing financial actions */
    Citizen* citizens;                                  /**< Pointer to the Citizens class for managing citizen-related actions */
    std::vector<CommercialBuilding*> commercialBuildings; /**< Vector of pointers to CommercialBuilding instances affected by the recession */

public:
    /**
     * @brief Constructor to initialize receivers for the recession command.
     *
     * Initializes the RecessionCommand with pointers to the Department of Finance, 
     * Citizens class, and a vector of commercial buildings that will be affected 
     * by the recession.
     *
     * @param finDept Pointer to the Department of Finance responsible for managing financial responses.
     * @param citizens Pointer to the Citizens class for handling citizen-related operations.
     * @param commercialBuildings Vector of pointers to CommercialBuilding instances impacted by the recession.
     */
    RecessionCommand(DeptOfFinance* finDept, Citizen* citizens, std::vector<CommercialBuilding*>& commercialBuildings);

    /**
     * @brief Executes recession-related actions.
     *
     * This method orchestrates the response to a recession event by invoking methods 
     * that handle financial management, citizen dissatisfaction, and the status of commercial buildings.
     */
    void execute() override;

    /**
     * @brief Raises taxes in response to the recession.
     *
     * This method implements the logic for adjusting tax rates as part of the economic response 
     * to the recession, affecting the financial resources of the city.
     */
    void raiseTaxes();

    /**
     * @brief Manages citizen dissatisfaction during the recession.
     *
     * This method addresses citizen concerns and dissatisfaction resulting from the recession, 
     * implementing strategies to maintain public morale and satisfaction.
     */
    void manageCitizenDissatisfaction();

    /**
     * @brief Closes commercial buildings affected by the recession.
     *
     * This method evaluates and implements the closure of commercial buildings that 
     * are no longer viable due to the recession, affecting the local economy and job market.
     */
    void closeCommercialBuildings();
};

#endif // RECESSION_COMMAND_H
