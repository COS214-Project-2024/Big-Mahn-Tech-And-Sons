/**
 * @file Apartment.h
 * @brief Declaration of the Apartment class, representing a multi-unit residential building.
 */

#ifndef APARTMENT_H
#define APARTMENT_H

#include "ResidentialBuilding.h"
#include "TaxManager.h"

/**
 * @class Apartment
 * @brief Represents an apartment building with multiple residential units.
 */
class Apartment : public ResidentialBuilding
{

public:
  /**
   * @brief Default constructor for Apartment, initializing unique apartment attributes.
   */
  Apartment();

  /**
   * @brief Displays the statistics of the apartment, including specific and inherited details.
   */
  void displayStats() const override;

  /**
   * @brief Accepts a visitor for tax management or other visitor pattern operations.
   * @param visitor A pointer to the TaxManager visitor.
   */
  void accept(TaxManager *visitor) override;

  /**
   * @brief Creates a clone of the Apartment for repair purposes.
   * @return A pointer to a new Building object that is a clone of this Apartment.
   */
  Building *repairClone() const;

  // Getters and Setters

  /**
   * @brief Gets the number of units in the apartment building.
   * @return The number of residential units.
   */
  int getNumUnits() const;

  /**
   * @brief Sets the number of units in the apartment building.
   * @param units The number of residential units to be set.
   */
  void setNumUnits(int units);

  /**
   * @brief Checks if the apartment building has an elevator.
   * @return True if the building has an elevator, false otherwise.
   */
  bool getHasElevator() const;

  /**
   * @brief Sets the elevator availability in the apartment building.
   * @param elevator A boolean indicating the presence of an elevator.
   */
  void setHasElevator(bool elevator);
};

#endif // APARTMENT_H
