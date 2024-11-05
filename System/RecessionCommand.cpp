#include "RecessionCommand.h"
#include "DeptOfFinance.h"
#include "Citizen.h"
#include "CommercialBuilding.h"
#include "Building.h"
#include <vector>
#include <iostream>

/**
 * @brief Constructor to initialize receivers for the recession command.
 * @param prDept Pointer to the Department of Public Relations.
 * @param citizens Pointer to the Citizens class.
 * @param commercialBuildings Vector of pointers to CommercialBuilding instances affected by the recession.
 */
RecessionCommand::RecessionCommand(DeptOfFinance *finDept, Citizen *citizens, std::vector<CommercialBuilding *> &commercialBuildings)
    : finDept(finDept), citizens(citizens), commercialBuildings(commercialBuildings)
{
    // Constructor implementation
}

/**
 * @brief Raises taxes as part of the recession response.
 */
void RecessionCommand::raiseTaxes()
{
    if (finDept)
    {
        finDept->increaseTaxes(5.0);
    }
    else
    {
        std::cout << "Error: PR Department not initialized.\n";
    }
}

/**
 * @brief Manages citizen dissatisfaction during the recession.
 */
void RecessionCommand::manageCitizenDissatisfaction()
{
    if (citizens)
    {
        citizens->decreaseSatisfaction(7);
    }
    else
    {
        std::cout << "Error: Citizens data not initialized.\n";
    }
}

/**
 * @brief Closes a portion of commercial buildings due to the recession.
 */
void RecessionCommand::closeCommercialBuildings()
{
    for (auto *building : commercialBuildings)
    {
        if (building && !building->isClosed())
        {
            building->closeBuilding();
            // GUI: Visually mark this building as "Closed"
        }
    }
}

/**
 * @brief Executes all recession-related actions in sequence.
 */
void RecessionCommand::execute()
{
    std::cout << "Executing recession response...\n";
    raiseTaxes();
    manageCitizenDissatisfaction();
    closeCommercialBuildings();
    std::cout << "Recession response completed.\n";
}
