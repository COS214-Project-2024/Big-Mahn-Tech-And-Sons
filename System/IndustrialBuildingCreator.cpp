// Class implementation of Factory Method - ConcreteCreator participant

#include "IndustrialBuildingCreator.h"

Building *IndustrialBuildingCreator::createBuilding(const std::string &type) const
{
    if (type == "Factory")
    {
        std::cout << "Factory Method: Creating a Factory building.\n"; // Output indicating Factory Method pattern
        return new Factory();
    }
    else if (type == "Warehouse")
    {
        std::cout << "Factory Method: Creating a Warehouse building.\n"; // Output indicating Factory Method pattern
        return new Warehouse();
    }
    else if (type == "Airport")
    {
        std::cout << "Factory Method: Creating an Airport building.\n"; // Output indicating Factory Method pattern
        return new Airport();
    }
    else if (type == "TrainStation")
    {
        std::cout << "Factory Method: Creating a Train Station building.\n"; // Output indicating Factory Method pattern
        return new TrainStation();
    }
    else
    {
        // Display error message if building type is not recognized
        std::cout << "Error: Unknown industrial building type \"" << type << "\". Returning nullptr.\n";
        return nullptr;
    }
}
