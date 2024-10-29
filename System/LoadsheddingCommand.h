/**
 * @file LoadsheddingCommand.h
 * @brief Defines the LoadsheddingCommand class for handling load-shedding events.
 */

#ifndef LOADSHEDDING_COMMAND_H
#define LOADSHEDDING_COMMAND_H

#include "EventsCommand.h"
#include <string>
#include <vector>
#include <map>
#include <map>
#include <ctime>

/**
 * @class LoadsheddingCommand
 * @brief Concrete command class for managing load-shedding and power outages.
 *
 * This class is responsible for executing load-shedding operations,
 * notifying citizens, allocating energy resources, and managing complaints
 * related to utility outages.
 */
class LoadsheddingCommand : public EventsCommand {
private:
    std::vector<std::string> buildingsAffected;  ///< Stores names of buildings affected by load-shedding.
    std::map<std::string, std::string> notifications;  ///< Maps building names to their notification messages.
    std::time_t scheduleTime;  ///< Time when load-shedding is scheduled.
    int energyAllocated;  ///< Energy allocated during the load-shedding.
    std::map<std::string, std::string> complaints;  ///< Maps complaint IDs to their descriptions and statuses.

public:
    LoadsheddingCommand();  ///< Constructor to initialize default values.

    /**
     * @brief Cuts electricity to specific buildings during load-shedding.
     *
     * This method iterates over the buildings that are affected
     * and simulates the action of cutting electricity.
     */
    void cutElectricityToBuildings();

    /**
     * @brief Notifies citizens of upcoming outages.
     *
     * This method sends notifications to the affected buildings
     * about the upcoming load-shedding events, including the scheduled time.
     */
    void notifyCitizensOfOutages();

    /**
     * @brief Schedules load-shedding events.
     *
     * This method records the current time as the scheduled time for load-shedding.
     */
    void scheduleLoadshedding();

    /**
     * @brief Allocates energy resources during load-shedding.
     *
     * This method simulates the allocation of energy resources
     * necessary for managing the load-shedding events.
     */
    void allocateEnergyResources();

    /**
     * @brief Manages complaints related to utility outages.
     *
     * This method simulates the process of managing complaints,
     * allowing citizens to submit complaints and tracking their statuses.
     *
     * @param complaintId A unique identifier for the complaint.
     * @param description A description of the complaint.
     */
    void manageUtilityComplaints(const std::string& complaintId, const std::string& description);

    /**
     * @brief Executes the load-shedding command.
     *
     * This method orchestrates the entire load-shedding process
     * by calling the necessary methods in the correct order.
     */
    void execute();

    /**
     * @brief Sets the buildings affected by load-shedding.
     *
     * @param buildings A vector of building names to be affected.
     */
    void setBuildingsAffected(const std::vector<std::string>& buildings);
};

#endif // LOADSHEDDING_COMMAND_H
