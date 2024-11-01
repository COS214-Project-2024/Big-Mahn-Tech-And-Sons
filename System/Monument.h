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

public:
    /**
     * @brief Constructor for Monument.
     */
    Monument();

    /**
     * @brief Displays the stats specific to the monument.
     */
    void displayStats() const override;

    /**
     * @brief Accepts visitors using the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;

    Building* repairClone() const override;
};

#endif // MONUMENT_H