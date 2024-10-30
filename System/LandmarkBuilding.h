// Class defintion and implementation of Factory Method - ConcreteProduct (classification)

#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H

#include "Building.h"
#include "TaxManager.h"
#include <iostream>
#include <string>

/**
 * @class LandmarkBuilding
 * @brief Abstract base class representing landmark buildings.
 *
 * Landmark buildings are symbolic or special-purpose structures with 
 * cultural, historical, or architectural significance.
 */
class LandmarkBuilding : public Building {
protected:
    std::string significance;  ///< Description of the building's significance.
    int visitorsPerYear;       ///< Number of visitors per year.
    bool heritageStatus;       ///< Heritage status of the building.

public:
    /**
     * @brief Constructor for LandmarkBuilding.
     * @param name Name of the building.
     * @param maxCapacity Maximum visitor capacity.
     * @param significance Description of its significance.
     * @param heritageStatus Indicates if it is a heritage site.
     */
    LandmarkBuilding(const std::string& name, int maxCapacity, 
                     const std::string& significance, bool heritageStatus)
        : Building(name, maxCapacity),
          significance(significance), 
          visitorsPerYear(0), 
          heritageStatus(heritageStatus) 
    {
        width = 10;    // Default width for landmarks
        length = 15;   // Default length for landmarks
        priceTag = 1000000.0;  // Default price tag for a landmark
    }

    /**
     * @brief Virtual destructor for LandmarkBuilding.
     */
    // virtual ~LandmarkBuilding() = default;

    /**
     * @brief Displays the stats specific to a landmark building.
     */
    void displayStats() const override {
        Building::displayStats();  // Call the base class method
        std::cout << "Significance: " << significance << std::endl;
        std::cout << "Visitors per Year: " << visitorsPerYear << std::endl;
        std::cout << "Heritage Status: " 
                  << (heritageStatus ? "Yes" : "No") << std::endl;
    }

    /**
     * @brief Sets the number of visitors per year.
     * @param visitors Number of yearly visitors.
     */
    void setVisitorsPerYear(int visitors) {
        visitorsPerYear = visitors;
    }

    /**
     * @brief Gets the number of visitors per year.
     * @return The number of yearly visitors.
     */
    int getVisitorsPerYear() const {
        return visitorsPerYear;
    }

    /**
     * @brief Abstract method to accept a visitor for the visitor pattern.
     * @param visitor A pointer to the visitor object.
     */
    virtual void accept(TaxManager* visitor) = 0;

    virtual void repair() override {
        
    };

    virtual std::shared_ptr<Building> clone() const override {
       // return std::make_shared<LandmarkBuilding>(*this);
    }
};

#endif // LANDMARKBUILDING_H
