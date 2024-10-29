/**
 * @file NaturalDisasterCommand.h
 * @brief Defines the NaturalDisasterCommand class for handling natural disaster events.
 */

#ifndef NATURAL_DISASTER_COMMAND_H
#define NATURAL_DISASTER_COMMAND_H

#include "EventsCommand.h"
#include "DeptOfHousing.h"
#include "DeptOfTransport.h"

/**
 * @class NaturalDisasterCommand
 * @brief Command class for handling building damage, route blocking, and infrastructure repair during a natural disaster.
 */
class NaturalDisasterCommand : public EventsCommand {
public:
    /**
     * @brief Damages a percentage of buildings in the DeptOfHousing.
     * @param deptOfHousing Reference to DeptOfHousing object managing the city's buildings.
     */
    void damageBuildings(DeptOfHousing& deptOfHousing);

    /**
     * @brief Blocks affected transport routes in the DeptOfTransport.
     * @param deptOfTransport Reference to DeptOfTransport for route management.
     */
    void blockTransportRoutes(DeptOfTransport& deptOfTransport);

    /**
     * @brief Repairs damaged infrastructure within the DeptOfHousing.
     * @param deptOfHousing Reference to DeptOfHousing for managing repairs.
     */
    void repairInfrastructure(DeptOfHousing& deptOfHousing);

    /**
     * @brief Executes the natural disaster response sequence.
     * @param deptOfHousing Reference to DeptOfHousing for building management.
     * @param deptOfTransport Reference to DeptOfTransport for transport route management.
     */
    void execute(DeptOfHousing& deptOfHousing, DeptOfTransport& deptOfTransport);
};

#endif // NATURAL_DISASTER_COMMAND_H
