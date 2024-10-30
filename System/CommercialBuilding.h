// Class defintion and implementation of Factory Method - ConcreteProduct (classification)

/**
 * @file CommercialBuilding.h
 * @brief Declaration of the CommercialBuilding class.
 */

#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "Building.h"
#include "TaxManager.h"

/**
 * @class CommercialBuilding
 * @brief Abstract class representing commercial buildings.
 *
 * This class provides the shared attributes and operations for all commercial buildings,
 * such as available jobs for shops and offices, available kid spaces at schools,
 * and available beds in hospitals, while leaving implementation details to the subtypes.
 */
class CommercialBuilding : public Building {
protected:
    int availableJobs;      ///< Number of available jobs (for shops and offices).
    int availableKidsSpaces; ///< Number of available kids' spaces (for schools).
    int availableBeds;      ///< Number of available beds (for hospitals).
    bool closed;  // Indicates whether the building is closed due to recession


public:
    /**
     * @brief Constructor for CommercialBuilding.
     * @param name Name of the building.
     * @param maxCapacity Maximum capacity of the building.
     */
    CommercialBuilding(const std::string& name, int maxCapacity)
        : Building(name, maxCapacity),
          availableJobs(maxCapacity),          // Initialize available jobs to max capacity
          availableKidsSpaces(maxCapacity),    // Initialize available kids' spaces to max capacity
          availableBeds(maxCapacity) {          // Initialize available beds to max capacity
    }

    /**
     * @brief Displays the stats specific to commercial buildings.
     */
    virtual void displayStats() const {
       // Building::displayStats();  // Call base class method
        std::cout << "Available Jobs: " << availableJobs << std::endl;
        std::cout << "Available Kids' Spaces: " << availableKidsSpaces << std::endl;
        std::cout << "Available Beds: " << availableBeds << std::endl;
    }

    // Getters and Setters
    int getAvailableJobs() const { return availableJobs; }
    void setAvailableJobs(int jobs) { availableJobs = jobs; }

    int getAvailableKidsSpaces() const { return availableKidsSpaces; }
    void setAvailableKidsSpaces(int kidsSpaces) { availableKidsSpaces = kidsSpaces; }

    int getAvailableBeds() const { return availableBeds; }
    void setAvailableBeds(int beds) { availableBeds = beds; }

    virtual std::shared_ptr<Building> clone() const override;

     virtual void repair() override;
    /**
     * @brief Checks the availability of resources depending on the subtype.
     * @return True if resources are available, otherwise false.
     */
    virtual bool checkAvailability() const = 0;

    /**
     * @brief Accepts visitors for the visitor pattern.
     * This method remains virtual, to be overridden in the final building types.
     * @param visitor A pointer to the Taxmanager object.
     */
    virtual void accept(TaxManager* visitor) = 0;

    /**
     * @brief jecks if the buildings are closed due to recession 
     * It just sets the closed variables to true and sets the availavble jobs and beds to zero 
     */
    void closeBuilding() {
        if (!closed) {
            closed = true;
            availableJobs = 0;
            availableKidsSpaces = 0;
            availableBeds = 0;
            std::cout << "CommercialBuilding: " << getName() << " has been closed due to recession." << std::endl;
            // GUI: Mark the building as closed (e.g., gray out the building icon)
            // GUI: Add "Closed" label to indicate status
        } else {
            std::cout << "CommercialBuilding: " <<  getName() << " is already closed." << std::endl;
        }
    }

    void reopenBuilding() {
        if (closed) {
            closed = false;
            availableJobs = maxCapacity;
            availableKidsSpaces = maxCapacity;
            availableBeds = maxCapacity;
            std::cout << "CommercialBuilding: " << getName() << " has been reopened." << std::endl;
            // GUI: Remove "Closed" label and restore normal icon colors
        } else {
            std::cout << "CommercialBuilding: " << getName() << " is already open." << std::endl;
        }
    }

    bool isClosed() const {
        return closed;
    }

};

#endif // COMMERCIALBUILDING_H