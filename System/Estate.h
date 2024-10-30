// Class definition of Factory Method - ConcreteProduct (subtype)

/**
 * @file Estate.h
 * @brief Declaration of the Estate class.
 */

#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"

/**
 * @class Estate
 * @brief Represents a residential estate with luxury features.
 */
class Estate : public ResidentialBuilding {
private:
    int numFloors;          ///< Number of floors in the estate.
    bool hasSwimmingPool;   ///< Indicates if the estate has a swimming pool.

public:
    /**
     * @brief Default constructor for Estate.
     * Initializes with unique default values.
     */
    Estate();

    /**
     * @brief Displays the stats specific to the estate.
     */
    void displayStats() const override;

    /**
     * @brief Accepts a visitor for the visitor pattern.
     * @param visitor A pointer to the TaxManager visitor.
     */
    void accept(TaxManager* visitor) override;

    // Getters and Setters
    int getNumFloors() const;
    void setNumFloors(int floors);

    bool getHasSwimmingPool() const;
    void setHasSwimmingPool(bool pool);

    std::shared_ptr<Building> clone() const override;
};

#endif // ESTATE_H