#include "DeptOfUtilities.h"
#include "Building.h"
#include "DeptOfPR.h"
#include "PowerSupply.h"
#include "WaterSupply.h"
#include "WasteManagement.h"
#include "Request.h"

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

void DeptOfUtilities::increaseUsage()
{
    resourceUsage += 0;
}

void DeptOfUtilities::setSuccessor(DeptOfUtilities *nextDepartment)
{
    successor = nextDepartment;
}

void DeptOfUtilities::setPR(DeptOfPR *pr)
{
    this->PR = pr;
}
