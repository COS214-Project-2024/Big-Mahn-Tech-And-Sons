// Class definition of Factory Method - ConcreteProduct (classification)

/**
 * @file Factory.h
 * @brief Declaration of the Factory class.
 */

#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuilding.h"
class TaxManager;
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
        void displayStats() const ;
        
        /**
         * @brief Clones the factory for repair purposes.
         * @return A pointer to the cloned Factory object.
         */
        Building* repairClone() const ;

        /**
         * @brief Accepts visitors for the visitor pattern.
         * @param visitor A pointer to the visitor object.
         */
        void accept(TaxManager* visitor) ;

         double calculateTax() const ;
};

#endif // FACTORY_H
