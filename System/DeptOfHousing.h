// Class defintion of Factory Method - Client participant
// Class defintion of Facade - Subsystem Class participant

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
        std::vector<Building*> buildings;  // List of managed buildings
        ResidentialBuildingCreator residentialCreator;
        CommercialBuildingCreator commercialCreator;
        IndustrialBuildingCreator industrialCreator;
        LandmarkBuildingCreator landmarkCreator;

        double budget;  // Total budget allocated to the department
        DeptOfPR* deptOfPR;  // Reference to the DeptOfPR

    public:
        DeptOfHousing(double initialBudget);
        
        void setPR(DeptOfPR *PR);
        
        void createResidentialBuilding(const std::string& type);
        void createCommercialBuilding(const std::string& type);
        void createIndustrialBuilding(const std::string& type);
        void createLandmarkBuilding(const std::string& type);
        
        void displayAllBuildings() const;
        int getTotalBuildings() const;
        double getTotalPrice() const;
        double getRemainingBudget() const;

        void removeBuildingByName(const std::string &name);
        void listBuildings() const; 
        bool requestFunding(double amount);
        
        std::string getBuildingName(int index) const;
        void repairBuilding(const std::string& type);
        void addBudget(double amount);
        
    private:
        bool canAfford(double price) const;
        void createBuilding(const std::string& type, const std::string& category);
        int findBuildingIndex(const std::string& name) const;
};

#endif // DEPTOFHOUSING_H