#include "DeptOfUtilities.h"
#include "DeptOfPR.h"
#include "Request.h"
#include "Building.h"
#include "PowerSupply.h"


/**
 * @brief Constructor for DeptOfUtilities.
 * @param name The name of the department.
 * @param budget The initial budget allocated to the department.
 */
DeptOfUtilities::DeptOfUtilities(string name, double budget) 
    : departmentName(name), budget(budget), resourceUsage(0), successor(nullptr), PR(nullptr) {}

/**
 * @brief Displays the information about the department.
 */
void DeptOfUtilities::displayDepartmentInfo() {
    cout << "Department: " << departmentName << endl;
    cout << "Budget: ZAR" << budget << endl;
    cout << "Resource Usage: " << resourceUsage << endl;
}

void DeptOfUtilities::requestBudget()
{
}

void DeptOfUtilities::trackUsage()
{
}

/**
 * @brief Requests PR department assistance.
 */
void DeptOfUtilities::requestPR() {
    if (PR) {
        cout << "Requesting assistance from PR department for " << departmentName << endl;
        PR->notifyTaxman("Water");
    } else {
        cout << "No PR department available." << endl;
    }
}

/**
 * @brief Sets the successor in the chain.
 * @param nextDepartment Pointer to the next department in the chain.
 */
void DeptOfUtilities::setSuccessor(DeptOfUtilities* nextDepartment) {
    successor = nextDepartment;
}

void DeptOfUtilities::initiateLoadshedding()
{
    cout <<"Intiating  loadshedding " <<endl; 
  //  powerSupply->powerShutDown();    
    
}

void DeptOfUtilities::restorePower()
{
}

void DeptOfUtilities::increaseUsage()
{
}

void DeptOfUtilities::reduceUsage()
{
}

void DeptOfUtilities::setPR(DeptOfPR *pr)
{
    this->PR = pr;
}
