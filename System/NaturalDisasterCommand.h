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
 * @brief Command class for handling the effects of natural disasters on infrastructure.
 *
 * This class is responsible for managing the impacts of natural disasters, including
 * building damage, route blocking, and infrastructure repairs. It interacts with
 * the Department of Housing and the Department of Transportation to mitigate
 * the effects of disasters on the city's infrastructure and residents.
 */
class NaturalDisasterCommand : public EventsCommand
{
public:
    DeptOfHousing *deptOfHousing;          /**< Pointer to the Department of Housing for managing building damages */
    DeptOfTransportation *deptOfTransport; /**< Pointer to the Department of Transportation for managing transport routes */

    /**
     * @brief Constructor to initialize the departments involved in disaster response.
     *
     * Initializes the NaturalDisasterCommand with pointers to the Department of Housing
     * and the Department of Transportation, allowing access to their functionalities
     * during a natural disaster event.
     *
     * @param housing Pointer to the DeptOfHousing instance for managing housing-related actions.
     * @param transport Pointer to the DeptOfTransportation instance for managing transport-related actions.
     */
    NaturalDisasterCommand(DeptOfHousing *housing, DeptOfTransportation *transport);

    /** @brief Default constructor. */
    NaturalDisasterCommand() = default;

    /**
     * @brief Executes the natural disaster response command.
     *
     * This method orchestrates the response to a natural disaster by invoking methods
     * to damage buildings, block transport routes, and repair infrastructure as necessary.
     */
    void execute();

private:
    /**
     * @brief Damages buildings in the city as a result of the natural disaster.
     *
     * This private method implements the logic for determining which buildings are damaged
     * during the disaster and updates their statuses accordingly.
     */
    void damageBuildings();

    /**
     * @brief Repairs infrastructure affected by the natural disaster.
     *
     * This private method handles the logic for repairing damaged infrastructure,
     * ensuring that the city's transportation and housing systems are restored to functionality.
     */
    void repairInfrastructure();

    /**
     * @brief Blocks transportation routes affected by the natural disaster.
     *
     * This private method identifies and blocks transport routes that have been compromised
     * during the disaster, preventing access and ensuring public safety.
     */
    void blockTransportRoutes();
};

#endif // NATURAL_DISASTER_COMMAND_H
