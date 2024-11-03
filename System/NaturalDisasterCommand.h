/**
 * @file NaturalDisasterCommand.h
 * @brief Defines the NaturalDisasterCommand class for handling natural disaster events.
 */

#ifndef NATURAL_DISASTER_COMMAND_H
#define NATURAL_DISASTER_COMMAND_H

#include "EventsCommand.h"
#include "DeptOfHousing.h"
#include "DeptOfTransportation.h"

/**
 * @class NaturalDisasterCommand
 * @brief Command class for handling building damage, route blocking, and infrastructure repair during a natural disaster.
 */
class NaturalDisasterCommand : public EventsCommand {
public:
    DeptOfHousing* deptOfHousing;       // Pointer to DeptOfHousing
    DeptOfTransportation* deptOfTransport;  // Pointer to DeptOfTransportation

    // Constructor to initialize the departments
   NaturalDisasterCommand(DeptOfHousing* housing, DeptOfTransportation* transport);

  NaturalDisasterCommand()= default;
  void execute();

private:
    void damageBuildings();
    void repairInfrastructure();
    void blockTransportRoutes();

};

#endif // NATURAL_DISASTER_COMMAND_H
