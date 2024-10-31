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
    int yearEstablished;                 // The year the monument was established

public:
    /**
     * @brief Constructor for Monument.
     * @param name Name of the monument.
     * @param maxCapacity Maximum visitor capacity.
     * @param yearEstablished Year the monument was established.
     * @param heritageStatus Whether the monument is a heritage site.
     */
    Monument(const std::string& name, int maxCapacity, int yearEstablished, 
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


    int getYearEstablished() const;
    void setYearEstablished(int year);

    Building* clone() const override;
};

#endif // MONUMENT_H
