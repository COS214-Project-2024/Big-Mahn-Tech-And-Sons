#ifndef GOTOENT_H
#define GOTOENT_H

#include "GoToCommand.h"
#include "Citizen.h"
#include "DeptOfHousing.h"

#include <iostream>

using namespace std;

/**
 * @class  GoToEnt
 * @brief   A concrete command that allows a citizen to travel from their current position to a random entertainment node.
 * 
 * This class inherits from GoToCommand and encapsulates the logic required for a citizen
 * to navigate to an entertainment location within the city.
 */
class GoToEnt : public GoToCommand
{
private:
    Citizen* citizen;        ///< Pointer to the citizen who is traveling to an entertainment location.
    DeptOfHousing* DOH;     ///< Pointer to the Department of Housing for accessing housing-related functionalities.

public:
    /**
     * @brief Constructs a GoToEnt command for the specified citizen.
     *
     * Initializes the GoToEnt command with the given citizen and references the Department of Housing.
     *
     * @param citizen A pointer to the Citizen object representing the person going to the entertainment location.
     * @param housing A pointer to the DeptOfHousing object for accessing related functionalities.
     */
    GoToEnt(Citizen* citizen, DeptOfHousing* housing);

    /**
     * @brief Executes the command for the citizen to go to a random entertainment node.
     *
     * This method simulates the action of the citizen navigating the road network to reach
     * a selected entertainment destination.
     *
     * @return True if the navigation to the entertainment location is successful; false otherwise.
     */
    bool execute() override;
};

#endif // GOTOENT_H
