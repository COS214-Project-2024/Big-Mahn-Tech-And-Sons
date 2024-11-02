#include "DeptOfUtilities.h"
#include "Building.h"

DeptOfUtilities::DeptOfUtilities(double budget)
    : budget(budget), resourceUsage(0), successor(nullptr), PR(nullptr) {}

/**
 * @brief Displays the information about the department.
 */
void DeptOfUtilities::displayDepartmentInfo()
{
    cout << "Budget: ZAR" << budget << endl;
    cout << "Resource Usage: " << resourceUsage << endl;
}

void DeptOfUtilities::requestBudget() // Requests additional budget allocation from the government.
{
}

void DeptOfUtilities::trackUsage()
{
}

void DeptOfUtilities::requestPR() // Requests PR department assistance.
{
    if (PR)
    {
        cout << "Requesting assistance from PR department for department utilities" << endl;
        PR->notifyTaxman("Water");
    }
    else
    {
        cout << "No PR department available." << endl;
    }
}

bool DeptOfUtilities::handleRequest(Request &req) // If not handled, passes the request to the successor in the chain.
{
    if (successor)
    {
        successor->handleRequest(req);
        return true;
    }
    else
    {
        std::cout << "Request for " << req.getType() << " could not be handled." << std::endl;
    }
    return false;
}

void DeptOfUtilities::setSuccessor(DeptOfUtilities *nextDepartment)
{
    successor = nextDepartment;
}

void DeptOfUtilities::initiateLoadshedding()
{
    cout << "Initiating loadshedding  " << endl;
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
