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
    std::map<std::string, float> taxRates;
    double collectedTaxes;
    double taxRate; 
    std::vector<double> incomes;
    std::vector<Citizen*> citizenList;
    std::vector<CommercialBuilding*> commercialBuildings;
    std::vector<ResidentialBuilding*> residentialBuildings;
    float governmentBudget;

public:
    /**
     * @brief Default constructor for TaxManager.
     */
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
     bool visitBuildingForCitizen(Building* building); // New method for citizens
    bool visitBuildingForBuilding(Building* building); // New method for buildings
    bool  visitBudget(Budget* budget);
    
    
    void collect(ResidentialBuilding* building);
    void collect(CommercialBuilding* building);
};


#endif // TAXMANAGER_H+