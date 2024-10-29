#include "DepartmentUtilities.h"
#include "DeptPR.h"

/**
 * @brief Constructor for DepartmentUtilities.
 * @param name The name of the department.
 * @param budget The initial budget allocated to the department.
 */
DepartmentUtilities::DepartmentUtilities(string name, double budget) 
    : departmentName(name), budget(budget), resourceUsage(0), successor(nullptr), PR(nullptr) {}

/**
 * @brief Displays the information about the department.
 */
void DepartmentUtilities::displayDepartmentInfo() {
    cout << "Department: " << departmentName << endl;
    cout << "Budget: ZAR" << budget << endl;
    cout << "Resource Usage: " << resourceUsage << endl;
}

void DepartmentUtilities::requestBudget()
{
}

/**
 * @brief Requests PR department assistance.
 */
void DepartmentUtilities::requestPR() {
    if (PR) {
        cout << "Requesting assistance from PR department for " << departmentName << endl;
        PR->notifyUtilities();
    } else {
        cout << "No PR department available." << endl;
    }
}

/**
 * @brief Sets the successor in the chain.
 * @param nextDepartment Pointer to the next department in the chain.
 */
void DepartmentUtilities::setSuccessor(DepartmentUtilities* nextDepartment) {
    successor = nextDepartment;
}
