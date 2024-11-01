// Class defintion of Factory Method - ConcreteProduct (subtype)

#ifndef PARK_H
#define PARK_H

#include "LandmarkBuilding.h"
#include "TaxManager.h"
#include <string>

/**
 * @class Park
 * @brief Concrete class representing a public park.
 *
 * Parks are natural spaces designed for recreation and leisure,
 * often containing gardens, playgrounds, or walking paths.
 */
class Park : public LandmarkBuilding {

public:
    /**
     * @brief Constructor for Park.
     */
    Park();

    /**
     * @brief Displays the stats specific to the park.
     */
    void displayStats() const override;

    /**
     * @brief Accepts visitors using the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    void accept(TaxManager* visitor) override;

    /**
     * @brief Sets the green space area.
     * @param area New green space area in square meters.
     */
    void setGreenSpaceArea(double area);

    /**
     * @brief Gets the green space area.
     * @return The area of green space in square meters.
     */
    double getGreenSpaceArea() const;

    /**
     * @brief Sets the number of playgrounds.
     * @param count New playground count.
     */
    void setPlaygroundCount(int count);

    /**
     * @brief Gets the number of playgrounds.
     * @return The number of playgrounds.
     */
    int getPlaygroundCount() const;

    Building* repairClone() const override;
};

#endif // PARK_H