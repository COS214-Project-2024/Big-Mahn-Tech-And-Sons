// visitHousing.h
#ifndef VISITHOUSING_H
#define VISITHOUSING_H

#include "TaxManager.h"

/**
 * @class visitHousing
 * @brief Visitor class for handling tax-related operations on housing structures.
 *
 * The visitHousing class extends the TaxManager to provide specific implementations 
 * for visiting residential and commercial buildings as well as budget-related operations. 
 * This class utilizes the Visitor design pattern to separate tax calculation logic 
 * from the building classes themselves.
 */
class visitHousing : public TaxManager {
public:
    /**
     * @brief Default constructor for visitHousing.
     *
     * Initializes a new instance of the visitHousing class. 
     * This constructor may set default values or prepare any necessary internal 
     * states for visiting housing-related entities.
     */
    visitHousing();

    /**
     * @brief Visits a residential building for tax calculations.
     *
     * This method implements the logic for calculating taxes specific to 
     * a ResidentialBuilding instance. It may take into account various factors 
     * such as property value, occupancy rates, and local tax policies.
     *
     * @param building A pointer to the ResidentialBuilding object to be visited.
     */
    void visitResidentialBuilding(ResidentialBuilding* building) override;

    /**
     * @brief Visits a commercial building for tax calculations.
     *
     * This method implements the logic for calculating taxes specific to 
     * a CommercialBuilding instance. Factors considered may include 
     * business revenue, size, and type of commercial activity.
     *
     * @param building A pointer to the CommercialBuilding object to be visited.
     */
    void visitCommercialBuilding(CommercialBuilding* building) override;

    /**
     * @brief Visits a budget for allocation or analysis.
     *
     * This method allows the visitor to perform operations related to the 
     * city's budget, potentially adjusting allocations or analyzing financial 
     * data based on current taxation policies.
     *
     * @param budget A pointer to the Budget object to be visited.
     */
    void visitBudget(Budget* budget) override;
};

#endif // VISITHOUSING_H
