// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "TrainStation.h"
#include <iostream>


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


void TrainStation::displayStats() const {
    IndustrialBuilding::displayStats();  // Call base class method.
}


void TrainStation::accept(TaxManager* visitor) {
    std::cout << "No tax applied to train station: " << getName() 
              << ". Train stations are non-taxable." << std::endl;
}


Building* TrainStation::repairClone() const {
    std::cout << "Prototype: Cloning a Train Station building.\n"; // Output indicating Prototype pattern
    std::cout << "Repairing industrial building (Train Station): " << getName() << "\n";
    return new TrainStation(*this);
}

double TrainStation::calculateTax() const
{
   return 0.0;
}
