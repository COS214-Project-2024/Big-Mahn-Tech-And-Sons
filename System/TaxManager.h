// TaxManager.h
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
    float collectedTaxes;
    std::vector<Citizen*> citizenList;
    std::vector<CommercialBuilding*> commercialBuildings;
    std::vector<ResidentialBuilding*> residentialBuildings;
    float governmentBudget;

public:
    TaxManager();
    // virtual ~TaxManager() = default;

    void setTaxRate(const std::string& type, float rate);
    float calculateCitizenTax(Citizen* citizen);
    float calculateBusinessTax(CommercialBuilding* building);
    void collectTaxes();
    void distributeBudget(const std::string& department, float allocation);
    float getCollectedTaxes() const;
    float getGovernmentBudget() const;
    
    // Visitor methods
    virtual void visitResidentialBuilding(ResidentialBuilding* building);
    virtual void visitCommercialBuilding(CommercialBuilding* building);
    virtual void visitBudget(Budget* budget);
    
    void collect(ResidentialBuilding* building);
    void collect(CommercialBuilding* building);
};

#endif // TAXMANAGER_H+