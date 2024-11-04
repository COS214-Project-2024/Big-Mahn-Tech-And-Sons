// Class definition of Factory Method - ConcreteProduct participant (subtype)

/**
 * @file Estate.h
 * @brief Declaration of the Estate class, representing a luxury residential estate.
 */

#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"

/**
 * @class Estate
 * @brief Represents a residential estate with luxury features.
 */
class Estate : public ResidentialBuilding
{

public:
    /**
     * @brief Default constructor for Estate, initializing luxury-specific attributes.
     */
    Estate();

    /**
     * @brief Displays the estate's statistics, including specific and inherited details.
     */
    void displayStats() const override;

    /**
     * @brief Accepts a visitor for tax and management operations.
     * @param visitor A pointer to the TaxManager visitor.
     */
    void accept(TaxManager *visitor) override;

    /**
     * @brief Creates a clone of the estate for restoration purposes.
     * @return Building* A pointer to the cloned Estate instance.
     */
    Building *repairClone() const override;
};

#endif // ESTATE_H
