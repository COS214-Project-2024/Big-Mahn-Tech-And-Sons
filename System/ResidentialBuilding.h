// Class defintion and implementation of Factory Method - ConcreteProduct (classification)

/**
 * @file ResidentialBuilding.h
 * @brief Declaration of the ResidentialBuilding class.
 */

#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "Building.h"
#include "TaxManager.h"


/**
 * @class ResidentialBuilding
 * @brief Abstract class representing residential buildings.
 *
 * This class provides the shared attributes and operations for all residential buildings,
 * such as utilities and waste management, while leaving implementation details to the subtypes.
 */
class ResidentialBuilding : public Building {
protected:
    bool hasBackyard;  ///< Indicates if the residential building has a backyard

public:
    /**
     * @brief Constructor for ResidentialBuilding.
     * @param name Name of the building.
     * @param maxCapacity Maximum capacity of the building.
     * @param backyard Indicates whether the building has a backyard.
     */
    ResidentialBuilding(const std::string& name, int maxCapacity, bool backyard)
        : Building(name, maxCapacity), hasBackyard(backyard) {}


    /**
     * @brief Displays the stats specific to residential buildings.
     */
    void displayStats() const {
        //Building::displayStats();  // Call base class method
        std::cout << "Has Backyard: " << (hasBackyard ? "Yes" : "No") << std::endl;
    }

    // Getter and Setter for Backyard
    bool getHasBackyard() const { return hasBackyard; }
    void setHasBackyard(bool backyard) { hasBackyard = backyard; }

   
    /**
     * @brief Accepts visitors for the visitor pattern.
     * This method remains virtual, to be overridden in the final building types.
     * @param visitor A pointer to the visitor object.
     */
    virtual void accept(TaxManager* visitor) = 0;


    /**
 * @brief Clones the ResidentialBuilding to create a new instance with identical properties.
 * 
 * This implementation supports the Prototype pattern by creating a copy of the building.
 * 
 * @return A shared pointer to the cloned ResidentialBuilding instance.
 */
 virtual Building* clone() const override {
        
    };
/**
 * @brief Repairs the residential building.
 * 
 * This method provides specific repair actions for a ResidentialBuilding instance.
 */
void repair() override {
    std::cout << "Repairing residential building: " << getName() << "\n";
}
};
 
#endif // RESIDENTIALBUILDING_H