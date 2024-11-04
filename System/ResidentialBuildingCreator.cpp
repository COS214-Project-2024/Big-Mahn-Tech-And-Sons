// Class implementation of Factory Method - ConcreteCreator participant


#include "ResidentialBuildingCreator.h"


Building* ResidentialBuildingCreator::createBuilding(const std::string &type) const {
    if (type == "Estate") {
        return new Estate();
    } else if (type == "Apartment") {
        return new Apartment();
    } else if (type == "House") {
        return new House();
    } else {
        // Display error message if building type is not recognized
        std::cerr << "Error: Unknown residential building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}
