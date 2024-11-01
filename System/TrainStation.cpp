// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "TrainStation.h"
#include <iostream>

/**
 * @brief Default Constructor for TrainStation.
 * Initializes the train station with specific default values.
 */
TrainStation::TrainStation()
    : IndustrialBuilding() {
    name = "Gautrain Station";
    maxCapacity = 500;
    width = 50;                   ///< Example width of the station.
    length = 150;                 ///< Example length of the station.
    electricityMeterBox = 500.0;  ///< Initial electricity meter reading.
    waterMeterBox = 300.0;        ///< Initial water meter reading.
    electricityUsage = 0.0;       ///< Initial electricity usage.
    waterUsage = 0.0;             ///< Initial water usage.
    wasteProduction = 0.0;        ///< Initial waste production.
    priceTag = 750000.0;          ///< Default price tag for a train station.
    type = "TrainStation";
}

/**
 * @brief Displays stats specific to the train station.
 */
void TrainStation::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method.
}

/**
 * @brief Accepts a visitor for applying the Visitor pattern.
 * @param visitor A pointer to the TaxManager object.
 * Displays that train stations are non-taxable.
 */
void TrainStation::accept(TaxManager* visitor) {
    std::cout << "No tax applied to train station: " << getName() 
              << ". Train stations are non-taxable." << std::endl;
}

/**
 * @brief Clones the train station for repair purposes.
 * @return A pointer to the cloned TrainStation object.
 */
Building* TrainStation::repairClone() const {
    std::cout << "Repairing industrial building (Train Station): " << getName() << "\n";
    return new TrainStation(*this);
}
