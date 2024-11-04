#ifndef TAXMANAGER_H
#define TAXMANAGER_H

#include <map>
#include <vector>
#include <string>
#include "Citizen.h"
class visitHousing;
class Budget;

class CommercialBuilding;
class ResidentialBuilding;

/**
 * @class TaxManager
 * @brief Manages taxation policies and visits buildings and resources in the city.
 * 
 * The TaxManager is responsible for managing the taxation system in the city.
 * It collects taxes from citizens and businesses and distributes the city's budget to different departments.
 * The TaxManager also applies tax policies and interacts with buildings and resources using the Visitor pattern.
 */
class TaxManager {
private:
    std::map<std::string, float> taxRates;
    double collectedTaxes;
    double taxRate; 
    std::vector<double> incomes;
    std::vector<Citizen*> citizenList;
    std::vector<CommercialBuilding*> commercialBuildings;
    std::vector<ResidentialBuilding*> residentialBuildings;
    float governmentBudget;

public:
    TaxManager();
    // virtual ~TaxManager() = default;

    void setTaxRate(double rate); // Method to set the tax rate
    double getTaxRate() const;    // Method to get the tax rate
    double calculateCitizenTax(Citizen* citizen);
    double  calculateBusinessTax(CommercialBuilding* building);
    void collectTaxes();
    bool checkMoney();            // Function to check financial stability
    void distributeBudget(const std::string& department, float allocation);
    double getCollectedTaxes() const;
    float getGovernmentBudget() const;
    //void applyCollectedTaxesToBudget(Budget& budget);

    double setTaxCollected(double collectedTaxes);
 
    // Visitor methods
     void visitBuildingForCitizen(Building* building); // New method for citizens
    void visitBuildingForBuilding(Building* building); // New method for buildings
    virtual void visitBudget(Budget* budget);
    
    
    void collect(ResidentialBuilding* building);
    void collect(CommercialBuilding* building);
};


#endif // TAXMANAGER_H+