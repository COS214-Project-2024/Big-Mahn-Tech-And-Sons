// Class definition of Factory Method - ConcreteProduct (subtype)

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "IndustrialBuilding.h"
class TaxManager;
/**
 * @class Warehouse
 * @brief Represents a warehouse, a type of industrial building.
 */
class Warehouse : public IndustrialBuilding {

    public:
        /**
         * @brief Default Constructor for Warehouse.
         * Initializes the warehouse with default values.
         */
        Warehouse();

        /**
         * @brief Displays the stats specific to the warehouse.
         */
        void displayStats() const ;

        /**
         * @brief Accepts a visitor for applying the Visitor pattern.
         * @param visitor A pointer to the TaxManager object.
         */
        void accept(TaxManager* visitor) ;

        /**
         * @brief Clones the warehouse for repair purposes.
         * @return A pointer to the cloned Warehouse object.
         */
        Building* repairClone() const ;

         double calculateTax() const ;
};

#endif // WAREHOUSE_H