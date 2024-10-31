// Class defintion of Factory Method - ConcreteProduct (subtype)

#ifndef MUSEUM_H
#define MUSEUM_H

#include "LandmarkBuilding.h"
#include "TaxManager.h"
#include <string>

/**
 * @brief The Museum class, a specific type of LandmarkBuilding.
 */
class Museum : public LandmarkBuilding {

public:
    /**
     * @brief Constructor for Museum.
     * @param name Name of the museum.
     * @param maxCapacity Maximum visitor capacity.
     * @param exhibitCount Number of exhibits in the museum.
     * @param entryFee Entry fee in local currency.
     * @param heritageStatus Whether the museum is a heritage site.
     */
    Museum();

    /**
     * @brief Displays the stats specific to the museum.
     */
    void displayStats() const override;

    /**
     * @brief Accepts visitors using the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;

    Building* repairClone() const override;


};

#endif // MUSEUM_H
