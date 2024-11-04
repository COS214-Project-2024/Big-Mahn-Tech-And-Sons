// Class implementation of Factory Method - ConcreteCreator participant
#include "CommercialBuildingCreator.h"


Building* CommercialBuildingCreator::createBuilding(const std::string &type) const {
    if (type == "Shop") {
        return new Shop();
    } else if (type == "Office") {
        return new Office();
    } else if (type == "School") {
        return new School();
    } else if (type == "Hospital") {
        return new Hospital();
    } else {
        // Display error message if building type is not recognized
        std::cerr << "Error: Unknown commercial building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}
