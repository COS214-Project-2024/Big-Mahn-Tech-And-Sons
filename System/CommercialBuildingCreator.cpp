// Class implementation of Factory Method - ConcreteCreator participant
#include "CommercialBuildingCreator.h"

Building *CommercialBuildingCreator::createBuilding(const std::string &type) const
{
    if (type == "Shop")
    {
        std::cout << "Factory Method: Creating a Shop building.\n"; // Output indicating Factory Method pattern
        return new Shop();
    }
    else if (type == "Office")
    {
        std::cout << "Factory Method: Creating an Office building.\n"; // Output indicating Factory Method pattern
        return new Office();
    }
    else if (type == "School")
    {
        std::cout << "Factory Method: Creating a School building.\n"; // Output indicating Factory Method pattern
        return new School();
    }
    else if (type == "Hospital")
    {
        std::cout << "Factory Method: Creating a Hospital building.\n"; // Output indicating Factory Method pattern
        return new Hospital();
    }
    else
    {
        // Display error message if building type is not recognized
        std::cout << "Error: Unknown commercial building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}
