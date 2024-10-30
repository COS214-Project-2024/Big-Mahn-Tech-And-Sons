// Class defintion of Factory Method - ConcreteProduct (subtype)

#ifndef MONUMENT_H
#define MONUMENT_H

#include "LandmarkBuilding.h"
#include "TaxManager.h"
#include <string>

/**
 * @brief The Monument class, a specific type of LandmarkBuilding.
 */
class Monument : public LandmarkBuilding {
private:
    std::string historicalSignificance;  // The historical significance of the monument
    int yearEstablished;                 // The year the monument was established

public:
    /**
     * @brief Constructor for Monument.
     * @param name Name of the monument.
     * @param maxCapacity Maximum visitor capacity.
     * @param significance Historical significance of the monument.
     * @param yearEstablished Year the monument was established.
     * @param heritageStatus Whether the monument is a heritage site.
     */
    Monument(const std::string& name, int maxCapacity, 
             const std::string& significance, int yearEstablished, 
             bool heritageStatus);

    /**
     * @brief Displays the stats specific to the monument.
     */
    void displayStats() const override;

    /**
     * @brief Accepts visitors using the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;

    // Getters and Setters
    std::string getHistoricalSignificance() const;
    void setHistoricalSignificance(const std::string& significance);

    int getYearEstablished() const;
    void setYearEstablished(int year);

    std::shared_ptr<Building>clone() const override;
};

#endif // MONUMENT_H
