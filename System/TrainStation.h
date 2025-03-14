// TrainStation.h
#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "IndustrialBuilding.h"

class TaxManager;

/**
 * @class TrainStation
 * @brief Represents a train station, a subtype of IndustrialBuilding.
 *
 * The TrainStation class models a train station, which is a specific type of 
 * industrial building in the city's infrastructure. This class includes methods 
 * for displaying statistics specific to the train station, accepting visitors for 
 * tax calculations, and creating a clone of the train station for repair purposes.
 */
class TrainStation : public IndustrialBuilding {
public:
    /**
     * @brief Default constructor for TrainStation.
     *
     * Initializes a new instance of the TrainStation class, setting up 
     * default values for its properties as defined in the IndustrialBuilding class.
     */
    TrainStation();

    /**
     * @brief Displays statistics specific to the train station.
     *
     * This method outputs the current operational statistics of the train station,
     * including metrics such as passenger throughput, cargo capacity, and revenue 
     * generation.
     */
    void displayStats() const;

    /**
     * @brief Accepts visitors for the visitor pattern.
     *
     * This method allows the TaxManager (or any other visitor) to perform operations 
     * on the TrainStation, enabling tax calculations and other visitor-specific 
     * functionalities.
     *
     * @param visitor A pointer to the TaxManager object that will visit the 
     *                TrainStation for tax calculations.
     */
    void accept(TaxManager* visitor);

    /**
     * @brief Creates a clone of the train station for repair purposes.
     *
     * This method generates a deep copy of the TrainStation object, allowing for 
     * the repair of the building without altering the original instance.
     *
     * @return A pointer to the cloned TrainStation object, representing the same 
     *         state as the original at the time of cloning.
     */
    Building* repairClone() const;

    /**
     * @brief Calculates the tax for the train station.
     *
     * This method computes the tax owed by the train station based on its 
     * specific financial metrics and the tax policies in place.
     * 
     * @return The calculated tax amount for the train station.
     */
    double calculateTax() const;
};

#endif // TRAINSTATION_H