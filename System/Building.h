// Class defintion of Factory Method - Product participant

/**
 * @file Building.h
 * @brief Declaration of the Building class.
 */

#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>
#include <iostream>  // For std::cout
#include <utility>   // For std::pair
#include <algorithm> // For std::find
#include <algorithm> // For std::find

#include "Element.h"

class Citizen; ///< Forward declaration of Citizen class
class TaxManager;

/**
 * @class Building
 * @brief Base class for all types of buildings.
 *
 * This class provides the common attributes and functionalities for all building types,
 * including managing tenants, utilities, and grid placement.
 */
class Building : public Element {

    protected:
        std::string name;               ///< Name of the building
        int maxCapacity;                ///< Maximum capacity of people in the building
        double electricityMeterBox;     ///< Electric meter reading
        double waterMeterBox;           ///< Water meter reading
        double electricityUsage;        ///< Total electricity usage
        double waterUsage;              ///< Total water usage
        double wasteProduction;         ///< Total waste produced
        std::vector<Citizen *> tenants; ///< Vector to store tenants or workers
        int width;                      ///< Width of the building for grid placement
        int length;                     ///< Length of the building for grid placement
        double priceTag;                ///< Price tag of the building
        double netWorth;                ///< Net worth of the building
        bool waterSupply;               ///< Water supply status
        bool powerSupply;               ///< Power supply status
        std::vector<std::pair<int, int>> gridCoordinates; ///< Grid coordinates
        std::string type;               ///< Type of Building
        double citizenTax;              ///< Tax rate for citizens
        double businessTax;             ///< Tax rate for businesses

    public:
        Building();  ///< Default constructor
        virtual ~Building() = default;  ///< Virtual destructor to allow polymorphism

        bool addTenant(Citizen *tenant);            ///< Adds a tenant to the building
        bool removeTenant(Citizen *tenant);         ///< Removes a tenant from the building
        void requestElectricity(double requestedElectricity); ///< Requests electricity usage
        void requestWater(double requestedWater);               ///< Requests water usage
        std::vector<std::pair<int, int>> getGridCoordinates() const; ///< Gets grid coordinates
        void setCoordinates(const std::vector<std::pair<int, int>> &coords); ///< Sets grid coordinates
        virtual void accept(TaxManager *visitor) = 0;    ///< Accepts visitors for the visitor pattern
        virtual double calculateTax() const = 0;  ///< Pure virtual function for tax calculation
        virtual void displayStats() const;                 ///< Displays the statistics of the building

        // Getters
        std::string getName() const;
        int getMaxCapacity() const;
        double getElectricityMeterBox() const;
        double getWaterMeterBox() const;
        double getElectricityUsage() const;
        double getWaterUsage() const;
        double getWasteProduction() const;
        const std::vector<Citizen *> &getTenants() const;
        int getWidth() const;
        int getLength() const;
        double getPriceTag() const;
        double getNetWorth() const;   ///< Getter for net worth
        int getCurrentOccupants() const; ///< Gets the current number of occupants
        std::string getType() const;  ///< Gets the type of the building
        double getWasteAmount() const; ///< Retrieves the current waste amount
        double getCitizenTax() const; ///< Gets the citizen tax rate
        double getBusinessTax() const; ///< Gets the business tax rate

        // Setters
        void setName(const std::string &name);
        void setMaxCapacity(int capacity);
        void setElectricityMeterBox(double reading);
        void setWaterMeterBox(double reading);
        void setElectricityUsage(double usage);
        void setWaterUsage(double usage);
        void setWaste(double waste);
        void setWidth(int width);
        void setLength(int length);
        void setCitizenTax(double taxRate); ///< Sets the citizen tax rate
        void setBusinessTax(double taxRate); ///< Sets the business tax rate

        virtual void consumeWater(double amount);      ///< Consumes water based on the specified amount
        virtual void consumeElectricity(double amount); ///< Consumes electricity based on the specified amount
        virtual void waterCut();                        ///< Cuts off the water supply to the building
        virtual void powerCut();                        ///< Cuts off the power supply to the building
        virtual void clearWaste();                      ///< Clears the waste produced by the building
        virtual Building* repairClone() const = 0;     ///< Creates a clone of the building
};

#endif // BUILDING_H
