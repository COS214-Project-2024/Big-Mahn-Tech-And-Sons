/**
 * @file DeptOfFinance.h
 * @brief Declaration of the DeptOfFinance class.
 * @author u21824241
 */

#ifndef DEPTOFFINANCE_H
#define DEPTOFFINANCE_H

#include <vector>
#include "Element.h"
#include "TaxManager.h"
#include "Building.h"

class DeptOfPR;

/**
 * @class DeptOfFinance
 * @brief Client class that interacts with different tax policies.
 *
 * Manages financial operations for the city, including tax collection,
 * budget allocation, and economic impact assessment.
 */
class DeptOfFinance
{
private:
    std::vector<Element *> elements; /**< List of elements in the city */
    TaxManager *taxManager;          /**< Pointer to the TaxManager handling tax policies */
    DeptOfPR *PR;                    /**< Pointer to the Department of Public Relations */

public:
    /**
     * @brief Constructor for DeptOfFinance.
     *
     * @param taxManager Pointer to the TaxManager for handling tax-related operations.
     */
    DeptOfFinance(TaxManager *taxManager);

    /**
     * @brief Collects taxes from a specified building.
     *
     * @param building Pointer to the building from which taxes are collected.
     */
    void collectTaxes(Building *building);

    /**
     * @brief Allocates budget to various departments and projects.
     */
    void allocateBudget();

    /**
     * @brief Adds an element to the list of city elements.
     *
     * @param element The element to add.
     */
    void addElement(Element *element);

    /**
     * @brief Applies tax policies to all elements by accepting a visitor.
     *
     * @param visitor The visitor (TaxManager) that applies tax policies.
     */
    void applyTaxes(TaxManager *visitor);

    /**
     * @brief Increases taxes by a specified percentage.
     *
     * @param percentage The percentage by which taxes are increased.
     */
    void increaseTaxes(double percentage);

    /**
     * @brief Decreases taxes to alleviate financial pressure.
     */
    void decreaseTaxes();

    /**
     * @brief Allocates a specified budget amount to a department.
     *
     * @param department The name of the department.
     * @param amount The amount to be allocated.
     */
    void allocateBudget(const std::string &department, double amount);

    /**
     * @brief Cuts funding for a specified department.
     *
     * @param department The name of the department.
     */
    void cutFunding(const std::string &department);

    /**
     * @brief Assesses the economic impact of an event on the city's finances.
     *
     * @return True if the economic impact is positive, false otherwise.
     */
    void assessEconomicImpact();

    /**
     * @brief Checks if the city is in a good financial position.
     *
     * @return True if the financial position is stable, false otherwise.
     */
    bool checkMoney();

    /**
     * @brief Collects taxes from all applicable elements in the city.
     */
    void collectTaxes();

    /**
     * @brief Sets the Department of Public Relations.
     *
     * @param PR Pointer to the DeptOfPR.
     */
    void setPR(DeptOfPR *PR);
};

#endif // DEPTOFFINANCE_H
