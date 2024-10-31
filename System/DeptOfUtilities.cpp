#include "DeptOfUtilities.h"
#include "Building.h"
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

/**
 * @brief Requests additional budget allocation from the government.
 */
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
        PR->notifyUtilities();
    } else {
        cout << "No PR department available." << endl;
    }
}

/**
 * @brief Base handleRequest function, to be overridden by each department.
 *        If not handled, passes the request to the successor in the chain.
 * @param req The request to be handled.
 */
void DeptOfUtilities::handleRequest(Request& req) {
    if (successor) {
        successor->handleRequest(req);
    } else {
        std::cout << "Request for " << req.getTypeAsString() << " could not be handled." << std::endl;
    }
}

void DeptOfUtilities::initiateLoadshedding()
{
    if(this->departmentName == "Power") {
        cout << "Initiating loadshedding for " << departmentName << endl;
        
    }
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

void DeptOfUtilities::setPR(DeptOfPR* pr)
{
    this->PR = pr;
}
