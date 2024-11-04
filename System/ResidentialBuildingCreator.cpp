// Class implementation of Factory Method - ConcreteCreator participant


#include "ResidentialBuildingCreator.h"


Building* ResidentialBuildingCreator::createBuilding(const std::string &type) const {
    if (type == "Estate") {
        std::cout << "Factory Method: Creating an Estate building.\n"; // Output indicating Factory Method pattern
        return new Estate();
    } else if (type == "Apartment") {
        std::cout << "Factory Method: Creating an Apartment building.\n"; // Output indicating Factory Method pattern
        return new Apartment();
    } else if (type == "House") {
        std::cout << "Factory Method: Creating a House building.\n"; // Output indicating Factory Method pattern
        return new House();
    } else {
        // Display error message if building type is not recognized
        std::cout << "Error: Unknown residential building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}
