// Class defintion of Factory Method - ConcreteProduct (classification)

/**
 * @file Factory.h
 * @brief Declaration of the Factory class.
 */

#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuilding.h"
#include "TaxManager.h"
#include <string>

/**
 * @class Factory
 * @brief Class representing a factory as a subtype of IndustrialBuilding.
 *
 * This class implements specific attributes and operations for a factory,
 * such as managing production capacity and operational hours.
 */
class Factory : public IndustrialBuilding {

public:
    /**
     * @brief Constructor for Factory.
     */
    Factory();

    /**
     * @brief Displays the stats specific to the factory.
     */
    void displayStats() const override;
    
    Building* repairClone() const override;
    /**
     * @brief Accepts visitors for the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;
};

#endif // FACTORY_H