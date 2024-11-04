// Class implementation of Factory Method - ConcreteProduct participant (classification)

/**
 * @file CommercialBuilding.cpp
 * @brief Implements the CommercialBuilding class.
 */

#include "CommercialBuilding.h"
#include "TaxManager.h"

/**
 * @brief Constructor for CommercialBuilding.
 * Initializes default values for job, kid space, and bed availability.
 */
CommercialBuilding::CommercialBuilding() 
    : Building(), availableJobs(1), availableKidsSpaces(1), availableBeds(1), closed(false), annualRevenue(0.0) {
}

/**
 * @brief Displays the stats specific to commercial buildings.
 */
void CommercialBuilding::displayStats() const {
    Building::displayStats();  // Call base class method
    std::cout << "Available Jobs: " << availableJobs << std::endl;
    std::cout << "Available Kids' Spaces: " << availableKidsSpaces << std::endl;
    std::cout << "Available Beds: " << availableBeds << std::endl;
}

/**
 * @brief Gets the available jobs.
 * @return The number of available jobs.
 */
int CommercialBuilding::getAvailableJobs() const {
    return availableJobs;
}

/**
 * @brief Sets the available jobs.
 * @param jobs Number of available jobs to set.
 */
void CommercialBuilding::setAvailableJobs(int jobs) {
    availableJobs = jobs;
}

/**
 * @brief Gets the available kids' spaces.
 * @return The number of available kids' spaces.
 */
int CommercialBuilding::getAvailableKidsSpaces() const {
    return availableKidsSpaces;
}

/**
 * @brief Sets the available kids' spaces.
 * @param kidsSpaces Number of available kids' spaces to set.
 */
void CommercialBuilding::setAvailableKidsSpaces(int kidsSpaces) {
    availableKidsSpaces = kidsSpaces;
}

/**
 * @brief Gets the available beds.
 * @return The number of available beds.
 */
int CommercialBuilding::getAvailableBeds() const {
    return availableBeds;
}

/**
 * @brief Sets the available beds.
 * @param beds Number of available beds to set.
 */
void CommercialBuilding::setAvailableBeds(int beds) {
    availableBeds = beds;
}

/**
 * @brief Closes the building due to recession.
 */
void CommercialBuilding::closeBuilding() {
    if (!closed) {
        closed = true;
        availableJobs = 0;
        availableKidsSpaces = 0;
        availableBeds = 0;
        std::cout << "CommercialBuilding: " << getName() << " has been closed due to recession." << std::endl;
        // GUI: Mark the building as closed (e.g., gray out the building icon)
        // GUI: Add "Closed" label to indicate status
    } else {
        std::cout << "CommercialBuilding: " << getName() << " is already closed." << std::endl;
    }
}

/**
 * @brief Reopens the building and restores resources to maximum capacity.
 */
void CommercialBuilding::reopenBuilding() {
    if (closed) {
        closed = false;
        availableJobs = maxCapacity;
        availableKidsSpaces = maxCapacity;
        availableBeds = maxCapacity;
        std::cout << "CommercialBuilding: " << getName() << " has been reopened." << std::endl;
        // GUI: Remove "Closed" label and restore normal icon colors
    } else {
        std::cout << "CommercialBuilding: " << getName() << " is already open." << std::endl;
    }
}

/**
 * @brief Checks if the building is closed.
 * @return True if the building is closed, otherwise false.
 */
bool CommercialBuilding::isClosed() const {
    return closed;
}


// Getters and Setters
double CommercialBuilding::getAnnualRevenue() const { 
    return annualRevenue; 
}

void CommercialBuilding::setAnnualRevenue(double revenue) { 
    annualRevenue = revenue; 
}    

double CommercialBuilding::calculateTax() const {
    return annualRevenue * getBusinessTax();
}
