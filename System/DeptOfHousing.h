// Class definition of Factory Method - Client participant
// Class definition of Facade - Subsystem Class participant

#ifndef DEPTOFHOUSING_H
#define DEPTOFHOUSING_H

#include "Building.h"
#include "ResidentialBuildingCreator.h"
#include "CommercialBuildingCreator.h"
#include "IndustrialBuildingCreator.h"
#include "LandmarkBuildingCreator.h"
#include "DeptOfPR.h"
#include <vector>
#include <memory>

/**
 * @class DeptOfHousing
 * @brief Manages the creation and removal of buildings with budget constraints.
 *
 * DeptOfHousing is responsible for managing the lifecycle of buildings,
 * including residential, commercial, industrial, and landmark buildings,
 * while adhering to a set budget. It also facilitates interactions with
 * the DeptOfPR for public relations needs.
 */
class DeptOfHousing
{

private:
    std::vector<Building *> buildings;             /**< List of managed buildings */
    ResidentialBuildingCreator residentialCreator; /**< Creator for residential buildings */
    CommercialBuildingCreator commercialCreator;   /**< Creator for commercial buildings */
    IndustrialBuildingCreator industrialCreator;   /**< Creator for industrial buildings */
    LandmarkBuildingCreator landmarkCreator;       /**< Creator for landmark buildings */

    double budget;      /**< Total budget allocated to the department */
    DeptOfPR *deptOfPR; /**< Reference to the DeptOfPR */

public:
    /**
     * @brief Constructor for DeptOfHousing.
     *
     * @param initialBudget Initial budget allocated to the department.
     */
    DeptOfHousing(double initialBudget);

    /**
     * @brief Sets the Department of Public Relations.
     *
     * @param PR Pointer to the DeptOfPR.
     */
    void setPR(DeptOfPR *PR);

    /**
     * @brief Creates a residential building of a specified type.
     *
     * @param type The type of residential building to create.
     */
    void createResidentialBuilding(const std::string &type);

    /**
     * @brief Creates a commercial building of a specified type.
     *
     * @param type The type of commercial building to create.
     */
    void createCommercialBuilding(const std::string &type);

    /**
     * @brief Creates an industrial building of a specified type.
     *
     * @param type The type of industrial building to create.
     */
    void createIndustrialBuilding(const std::string &type);

    /**
     * @brief Creates a landmark building of a specified type.
     *
     * @param type The type of landmark building to create.
     */
    void createLandmarkBuilding(const std::string &type);

    /**
     * @brief Displays details of all buildings managed by the department.
     */
    void displayAllBuildings() const;

    /**
     * @brief Gets the total number of buildings managed by the department.
     *
     * @return Total number of buildings.
     */
    int getTotalBuildings() const;

    /**
     * @brief Calculates the total price of all buildings.
     *
     * @return Total price of all buildings.
     */
    double getTotalPrice() const;

    /**
     * @brief Gets the remaining budget of the department.
     *
     * @return Remaining budget.
     */
    double getRemainingBudget() const;

    /**
     * @brief Removes a building by name.
     *
     * @param name The name of the building to remove.
     */
    void removeBuildingByName(const std::string &name);

    /**
     * @brief Lists all buildings managed by the department.
     */
    void listBuildings() const;

    /**
     * @brief Gets a list of all managed buildings.
     *
     * @return A vector containing pointers to all buildings.
     */
    std::vector<Building *> getBuildings();

    /**
     * @brief Requests additional funding for the department.
     *
     * @param amount The amount of funding requested.
     * @return True if funding is approved, false otherwise.
     */
    bool requestFunding(double amount);

    /**
     * @brief Gets the name of a building at a specified index.
     *
     * @param index The index of the building.
     * @return The name of the building.
     */
    std::string getBuildingName(int index) const;

    /**
     * @brief Repairs a building of a specified type.
     *
     * @param type The type of building to repair.
     */
    void repairBuilding(const std::string &type);

    /**
     * @brief Adds an amount to the department's budget.
     *
     * @param amount The amount to add to the budget.
     */
    void addBudget(double amount);

private:
    /**
     * @brief Checks if a specified price is within the department's budget.
     *
     * @param price The price to check.
     * @return True if the department can afford the price, false otherwise.
     */
    bool canAfford(double price) const;

    /**
     * @brief Creates a building of a specified type and category.
     *
     * @param type The type of building to create.
     * @param category The category of the building (e.g., residential, commercial).
     */
    void createBuilding(const std::string &type, const std::string &category);

    /**
     * @brief Finds the index of a building by its name.
     *
     * @param name The name of the building.
     * @return The index of the building, or -1 if not found.
     */
    int findBuildingIndex(const std::string &name) const;
};

#endif // DEPTOFHOUSING_H
