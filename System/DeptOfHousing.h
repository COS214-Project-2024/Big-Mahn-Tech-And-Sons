// Class defintion of Factory Method - Client
// Class defintion of Facade - Subsystem Class

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
 * @brief DeptOfHousing manages the creation and removal of buildings with budget constraints.
 */
class DeptOfHousing {
private:
    std::vector<std::shared_ptr<Building>> buildings;  // List of managed buildings
    ResidentialBuildingCreator residentialCreator;
    CommercialBuildingCreator commercialCreator;
    IndustrialBuildingCreator industrialCreator;
    LandmarkBuildingCreator landmarkCreator;

    double budget;  // Total budget allocated to the department
    DeptOfPR& deptOfPR;  // Reference to the DeptOfPR

public:
    /**
     * @brief Constructor for DeptOfHousing.
     * @param initialBudget The initial budget allocated to the department.
     */
    DeptOfHousing(double initialBudget, DeptOfPR& pr);

    /**
     * @brief Creates a residential building if within budget.
     * @param type Type of residential building (e.g., House, Apartment).
     */
    void createResidentialBuilding(const std::string& type);

    /**
     * @brief Creates a commercial building if within budget.
     * @param type Type of commercial building (e.g., Shop, Office).
     */
    void createCommercialBuilding(const std::string& type);

    /**
     * @brief Creates an industrial building if within budget.
     * @param type Type of industrial building (e.g., Factory, Warehouse).
     */
    void createIndustrialBuilding(const std::string& type);

    /**
     * @brief Creates a landmark building if within budget.
     * @param type Type of landmark building (e.g., Park, Museum, Monument).
     */
    void createLandmarkBuilding(const std::string& type);

    /**
     * @brief Displays all buildings managed by the department.
     */
    void displayAllBuildings() const;

    /**
     * @brief Gets the total number of managed buildings.
     * @return The number of buildings.
     */
    int getTotalBuildings() const;

    /**
     * @brief Gets the total price of all buildings.
     * @return Total value of all buildings combined.
     */
    double getTotalPrice() const;

    /**
     * @brief Gets the remaining budget of the department.
     * @return The remaining budget.
     */
    double getRemainingBudget() const;

    /**
     * @brief Destructor to clean up resources.
     */
    ~DeptOfHousing() = default;

    int findBuildingIndex(const std::string& name) const; // New method
    std::string findBuildingIndex(int i) const;
    void removeBuildingByName(const std::string &name); // New method
    void listBuildings() const; // New method to list buildings

    bool requestFunding(double amount);  // Modified to request via DeptOfPR
    void addBudget(double); // Normal adding and subtracting. Set amount of R2 million

};

#endif // DEPTOFHOUSING_H
