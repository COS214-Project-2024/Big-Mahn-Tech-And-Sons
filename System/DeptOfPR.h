#ifndef DEPTOFPR_H
#define DEPTOFPR_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Building;
class Citizen;
class DeptOfHousing;
class DeptOfUtilities;
class DeptOfFinance;

/**
 * @class DeptOfPR
 * @brief Manages the public relations aspect of the city system, observing buildings and citizens, and acting as a mediator to other departments.
 *
 * The `DeptOfPR` serves two main purposes:
 *
 * @note 1. **Observer Pattern**:
 *    - It observes buildings and citizens to monitor their state. If issues are detected, it takes necessary actions.
 *    - For example, if a building is overpopulated, it can notify the housing department to plan more buildings.
 *
 * @note 2. **Mediator Pattern**:
 *    - It acts as a mediator by coordinating communication between departments such as Housing, Utilities, and Finance.
 *    - This helps in streamlining requests, ensuring that departments do not need to communicate directly with each other but rather through this central hub.
 */
class DeptOfPR
{
private:
    DeptOfHousing *housing;          ///< Reference to the Housing Department.
    DeptOfUtilities *utilities;      ///< Reference to the Utilities Department.
    DeptOfFinance *finance;          ///< Reference to the Finance Department.
    std::vector<Citizen *> citizens; ///< List of citizens to notify.

    /**
     * @brief Removes a citizen from the city.
     *
     * This function handles the removal of a citizen and any necessary cleanup.
     *
     * @param citizen Pointer to the Citizen to be removed.
     */
    void killCitizen(Citizen *citizen);

public:
    /**
     * @brief Constructs the Department of PR with references to other departments.
     *
     * @param housingDept Pointer to the Housing Department.
     * @param utilitiesDept Pointer to the Utilities Department.
     * @param financeDept Pointer to the Finance Department.
     */
    DeptOfPR(DeptOfHousing *housingDept, DeptOfUtilities *utilitiesDept, DeptOfFinance *financeDept);

    /**
     * @brief Updates the state by checking both buildings and citizens.
     *
     * This function calls @see `checkBuildings()` and @see `checkCitizens()` to monitor
     * and ensure everything is functioning as expected. If any issues are detected,
     * appropriate actions are taken by notifying other departments.
     *
     * @param building Pointer to the Building to be checked.
     */
    void update(Building *building);

    /**
     * @brief Updates the state by checking a citizen's status.
     *
     * This function monitors the citizen and takes necessary actions based on their state.
     *
     * @param citizen Pointer to the Citizen to be checked.
     */
    void update(Citizen *citizen);

    // Mediator Functions

    /**
     * @brief Notifies the Housing Department to consider building more residential structures.
     *
     * This function is used when overcrowding or high demand for housing is detected.
     * It acts as a mediator, relaying the information to the Housing Department for further action.
     *
     * @param type The type of residential building requested.
     * @return True if the notification was successful, false otherwise.
     */
    bool notifyHousingToBuild(string type);

    /**
     * @brief Adds a citizen to the list of citizens monitored by the PR department.
     *
     * @param citizen Pointer to the Citizen to be added.
     */
    void addCitizen(Citizen *citizen);

    /**
     * @brief Retrieves a citizen by index.
     *
     * @param i Index of the citizen.
     * @return Pointer to the specified Citizen.
     */
    Citizen *getCitizen(int i);

    /**
     * @brief Gets the number of citizens being monitored.
     *
     * @return The count of citizens.
     */
    int numCitizens();

    /**
     * @brief Returns a vector of buildings managed by the department.
     *
     * @return A vector containing pointers to all buildings.
     */
    vector<Building *> getBuildings();

    /**
     * @brief Notifies the Housing Department to remove a building type if waste levels are critical.
     *
     * @param type The type of building to be removed.
     */
    void notifyHousingToRemove(string type);

    /**
     * @brief Notifies the Utilities Department to address issues or prepare for increased demand.
     *
     * This could involve actions like increasing power supply, fixing water supply issues, or improving waste management.
     * The PR Department mediates by sending this notification on behalf of observed buildings or citizens.
     *
     * @param request The request string specifying the action required.
     * @param building Pointer to the building related to the request.
     * @return True if the notification was successful, false otherwise.
     * @note Work on @class Resources to be added.
     */
    bool notifyUtilities(string request, Building *building);

    /**
     * @brief Notifies the Finance Department to adjust financial policies.
     *
     * If economic issues, tax concerns, or financial imbalances are detected, this function will notify the Finance Department.
     * The PR Department mediates communication, ensuring efficient inter-departmental collaboration.
     *
     * @param deptName The name of the department requesting financial policy adjustment.
     * @return True if the notification was successful, false otherwise.
     * @note The taxman is either notified to try to lower taxes or improve economic health.
     */
    bool notifyTaxman(string deptName);

    /**
     * @brief Promotes a festival to improve community engagement.
     *
     * This function can be called to organize or promote community events.
     */
    void promoteFestival();
};

#endif // DEPTOFPR_H
