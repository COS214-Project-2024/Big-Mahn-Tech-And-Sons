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
 * @class DepartmentOfPR
 * @brief Manages the public relations aspect of the city system, observing buildings and citizens, and acting as a mediator to other departments.
 * @author LeboGang
 * The `DepartmentOfPR` serves two main purposes:
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
    DeptOfHousing *housing;                  ///< Reference to the Housing Department.
    DeptOfUtilities *utilities;        ///< Reference to the Utilities Department.
    DeptOfFinance *finance;                  ///< Reference to the Finance Department.
    std::vector<Citizen*> citizens; ///< List of citizens to notify.
    void killCitizen(Citizen* citizen);

    
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
     */
    void update(Building* building); // call check buildings and citizens
    void update(Citizen* citizen);
    // Mediator Functions
    /**
     * @brief Notifies the Housing Department to consider building more residential structures.
     * 
     * This function is used when overcrowding or high demand for housing is detected.
     * It acts as a mediator, relaying the information to the Housing Department for further action.
     */
    void notifyHousingToBuild(string type);

    void addCitizen(Citizen* citizen);


    Citizen* getCitizen(int i);

    int numCitizens();
    /**
     * @brief if building waste is at a certain level, remove it
     */
    void notifyHousingToRemove(string type);

    /**
     * @brief Notifies the Utilities Department to address issues or prepare for increased demand.
     * 
     * This could involve actions like increasing power supply, fixing water supply issues, or improving waste management.
     * The PR Department mediates by sending this notification on behalf of observed buildings or citizens.
     * @note  work on @class Resources to be added
     *      */
    void notifyUtilities();

    /**
     * @brief Notifies the Finance Department (taxman) to adjust financial policies.
     * 
     * If economic issues, tax concerns, or financial imbalances are detected, this function will notify the Finance Department.
     * The PR Department mediates communication, ensuring efficient inter-departmental collaboration.
     * @note Taxman is either notified to try to lower taxes or improve economic health
     */
    bool notifyTaxman(string deptName);
    void promoteFestival();
};

#endif // DEPTOFPR_H