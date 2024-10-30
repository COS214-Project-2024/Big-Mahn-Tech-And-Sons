// Class implementation of Factory Method - ConcreteProduct (subtype)

#include "Monument.h"
#include <iostream>

/**
 * @brief Constructor for Monument.
 * @param name Name of the monument.
 * @param maxCapacity Maximum visitor capacity.
 * @param significance Historical significance of the monument.
 * @param yearEstablished Year the monument was established.
 * @param heritageStatus Whether the monument is a heritage site.
 */
Monument::Monument(const std::string& name, int maxCapacity, 
                   const std::string& significance, int yearEstablished, 
                   bool heritageStatus)
    : LandmarkBuilding(name, maxCapacity, "Monument", heritageStatus),
      historicalSignificance(significance), 
      yearEstablished(yearEstablished) 
{
    width = 20;            // Default monument width
    length = 20;           // Default monument length
    priceTag = 750000.0;   // Default price tag for a monument
}

/**
 * @brief Displays the stats specific to the monument.
 */
void Monument::displayStats() const {
    LandmarkBuilding::displayStats();  // Call base class method
    std::cout << "Historical Significance: " << historicalSignificance << std::endl;
    std::cout << "Year Established: " << yearEstablished << std::endl;
}

/**
 * @brief Accepts visitors using the visitor pattern.
 * @param visitor A pointer to the visitor object.
 */
void Monument::accept(TaxManager* visitor) { // Malaika STUB!!!
    // visitor->visit(this);  // Visitor pattern implementation
}

/**
 * @brief Gets the historical significance of the monument.
 * @return The historical significance as a string.
 */
std::string Monument::getHistoricalSignificance() const {
    return historicalSignificance;
}

/**
 * @brief Sets the historical significance of the monument.
 * @param significance New historical significance.
 */
void Monument::setHistoricalSignificance(const std::string& significance) {
    historicalSignificance = significance;
}

/**
 * @brief Gets the year the monument was established.
 * @return The year the monument was established.
 */
int Monument::getYearEstablished() const {
    return yearEstablished;
}

/**
 * @brief Sets the year the monument was established.
 * @param year New establishment year.
 */
void Monument::setYearEstablished(int year) {
    if (year > 0) {
        yearEstablished = year;
    } else {
        std::cerr << "Error: Invalid year." << std::endl;
    }
}


std::shared_ptr<Building>Monument:: clone() const  {
        return std::make_shared<Monument>(*this);  // Clone this School
    }
