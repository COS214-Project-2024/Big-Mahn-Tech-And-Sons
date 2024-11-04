// Class implementation of Factory Method - ConcreteProduct participant (classification)
#include "CommercialBuilding.h"
#include "TaxManager.h"

CommercialBuilding::CommercialBuilding()
    : Building(), availableJobs(1), availableKidsSpaces(1), availableBeds(1), closed(false), annualRevenue(0.0)
{
}

void CommercialBuilding::displayStats() const
{
    Building::displayStats(); // Call base class method
    std::cout << "Available Jobs: " << availableJobs << std::endl;
    std::cout << "Available Kids' Spaces: " << availableKidsSpaces << std::endl;
    std::cout << "Available Beds: " << availableBeds << std::endl;
}

int CommercialBuilding::getAvailableJobs() const
{
    return availableJobs;
}

void CommercialBuilding::setAvailableJobs(int jobs)
{
    availableJobs = jobs;
}

int CommercialBuilding::getAvailableKidsSpaces() const
{
    return availableKidsSpaces;
}

void CommercialBuilding::setAvailableKidsSpaces(int kidsSpaces)
{
    availableKidsSpaces = kidsSpaces;
}

int CommercialBuilding::getAvailableBeds() const
{
    return availableBeds;
}

void CommercialBuilding::setAvailableBeds(int beds)
{
    availableBeds = beds;
}

void CommercialBuilding::closeBuilding()
{
    if (!closed)
    {
        closed = true;
        availableJobs = 0;
        availableKidsSpaces = 0;
        availableBeds = 0;
        std::cout << "CommercialBuilding: " << getName() << " has been closed due to recession." << std::endl;
        // GUI: Mark the building as closed (e.g., gray out the building icon)
        // GUI: Add "Closed" label to indicate status
    }
    else
    {
        std::cout << "CommercialBuilding: " << getName() << " is already closed." << std::endl;
    }
}

void CommercialBuilding::reopenBuilding()
{
    if (closed)
    {
        closed = false;
        availableJobs = maxCapacity;
        availableKidsSpaces = maxCapacity;
        availableBeds = maxCapacity;
        std::cout << "CommercialBuilding: " << getName() << " has been reopened." << std::endl;
        // GUI: Remove "Closed" label and restore normal icon colors
    }
    else
    {
        std::cout << "CommercialBuilding: " << getName() << " is already open." << std::endl;
    }
}

bool CommercialBuilding::isClosed() const
{
    return closed;
}

// Getters and Setters
double CommercialBuilding::getAnnualRevenue() const
{
    return annualRevenue;
}

void CommercialBuilding::setAnnualRevenue(double revenue)
{
    annualRevenue = revenue;
}

double CommercialBuilding::calculateTax() const
{
    return annualRevenue * getBusinessTax();
}
