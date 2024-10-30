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
 * @brief Command class for handling recession events.
 */
class RecessionCommand : public EventsCommand {
private:
    DeptOfFinance* finDept;                        ///< Pointer to the Department of Public Relations
    Citizen* citizens;                      ///< Pointer to the Citizens class
    std::vector<CommercialBuilding*> commercialBuildings; ///< Vector of pointers to CommercialBuilding instances

public:
    /**
     * @brief Constructor to initialize receivers for the recession command.
     * @param prDept Pointer to the Department of Public Relations.
     * @param citizens Pointer to the Citizens class.
     * @param commercialBuildings Vector of pointers to CommercialBuilding instances affected by the recession.
     */
    RecessionCommand(DeptOfFinance* finDept, Citizen* citizens, std::vector<CommercialBuilding*>& commercialBuildings);

    /**
     * @brief Executes recession-related actions.
     */
    void execute() override;

    void raiseTaxes();
    void manageCitizenDissatisfaction();
    void closeCommercialBuildings();
};

#endif // RECESSION_COMMAND_H
