// TaxManager.h
#ifndef TAXMANAGER_H
#define TAXMANAGER_H

#include <map>
#include <vector>
#include <string>
#include "Citizen.h"

class Budget;
class CommercialBuilding;
class ResidentialBuilding;

/**
 * @class TaxManager
 * @brief Manages the taxation system and financial distribution within the city.
 *
 * The TaxManager is responsible for overseeing the city's taxation policies,
 * collecting taxes from citizens and businesses, and allocating the city's budget
 * to various departments. It employs the Visitor design pattern to interact
 * with different building types and resources efficiently.
 */
class TaxManager
{
private:
    std::map<std::string, float> taxRates;                   /**< Map storing tax rates for different categories */
    float collectedTaxes;                                    /**< Total taxes collected by the TaxManager */
    std::vector<Citizen *> citizenList;                      /**< List of citizens for tax calculations */
    std::vector<CommercialBuilding *> commercialBuildings;   /**< List of commercial buildings for tax calculations */
    std::vector<ResidentialBuilding *> residentialBuildings; /**< List of residential buildings for tax calculations */
    float governmentBudget;                                  /**< The overall budget of the government */

public:
    /**
     * @brief Default constructor for TaxManager.
     */
    TaxManager();

    /**
     * @brief Sets the tax rate for a specific type of tax.
     *
     * This method allows setting a tax rate for different categories such as
     * residential, commercial, and other relevant types.
     *
     * @param type The category of tax (e.g., "Residential", "Commercial").
     * @param rate The tax rate to be set for the specified category.
     */
    void setTaxRate(const std::string &type, float rate);

    /**
     * @brief Calculates the tax owed by a citizen.
     *
     * This method computes the tax for a given citizen based on their income
     * and applicable tax rates.
     *
     * @param citizen A pointer to the Citizen object for tax calculation.
     * @return The calculated tax amount for the citizen.
     */
    float calculateCitizenTax(Citizen *citizen);

    /**
     * @brief Calculates the tax owed by a commercial building.
     *
     * This method computes the business tax for a given commercial building
     * based on its revenue and applicable tax rates.
     *
     * @param building A pointer to the CommercialBuilding object for tax calculation.
     * @return The calculated business tax amount for the building.
     */
    float calculateBusinessTax(CommercialBuilding *building);

    /**
     * @brief Collects taxes from all citizens and businesses.
     *
     * This method iterates over all citizens and buildings to collect taxes,
     * updating the total amount of collected taxes.
     */
    void collectTaxes();

    /**
     * @brief Distributes the budget to a specific department.
     *
     * This method allocates a portion of the collected budget to the specified
     * department, ensuring financial support where needed.
     *
     * @param department The name of the department receiving the allocation.
     * @param allocation The amount of budget to allocate to the department.
     */
    void distributeBudget(const std::string &department, float allocation);

    /**
     * @brief Gets the total amount of taxes collected.
     *
     * @return The total collected taxes.
     */
    float getCollectedTaxes() const;

    /**
     * @brief Gets the current government budget.
     *
     * @return The current government budget amount.
     */
    float getGovernmentBudget() const;

    // Visitor methods
    /**
     * @brief Visits a residential building for tax-related operations.
     *
     * This method can be overridden to implement specific operations
     * when interacting with residential buildings.
     *
     * @param building A pointer to the ResidentialBuilding object being visited.
     */
    virtual void visitResidentialBuilding(ResidentialBuilding *building);

    /**
     * @brief Visits a commercial building for tax-related operations.
     *
     * This method can be overridden to implement specific operations
     * when interacting with commercial buildings.
     *
     * @param building A pointer to the CommercialBuilding object being visited.
     */
    virtual void visitCommercialBuilding(CommercialBuilding *building);

    /**
     * @brief Visits the budget for financial operations.
     *
     * This method can be overridden to implement specific operations
     * related to the budget.
     *
     * @param budget A pointer to the Budget object being visited.
     */
    virtual void visitBudget(Budget *budget);

    /**
     * @brief Collects taxes from a residential building.
     *
     * This method is responsible for handling tax collection for
     * residential buildings specifically.
     *
     * @param building A pointer to the ResidentialBuilding object from which to collect taxes.
     */
    void collect(ResidentialBuilding *building);

    /**
     * @brief Collects taxes from a commercial building.
     *
     * This method is responsible for handling tax collection for
     * commercial buildings specifically.
     *
     * @param building A pointer to the CommercialBuilding object from which to collect taxes.
     */
    void collect(CommercialBuilding *building);
};

#endif // TAXMANAGER_H
