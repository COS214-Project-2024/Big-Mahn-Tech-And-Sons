// Class implementation of Factory Method - ConcreteCreator participant

#include "IndustrialBuildingCreator.h"


Building* IndustrialBuildingCreator::createBuilding(const std::string &type) const {
    if (type == "Factory") {
        return new Factory();
    } else if (type == "Warehouse") {
        return new Warehouse();
    } else if (type == "Airport") {
        return new Airport();
    } else if (type == "TrainStation") {
        return new TrainStation();
    } else {
        // Display error message if building type is not recognized
        std::cerr << "Error: Unknown industrial building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}
