/**
 * @file LoadsheddingCommand.h
 * @brief Defines the LoadsheddingCommand class for handling load-shedding events.
 */

#ifndef LOADSHEDDINGCOMMAND_H
#define LOADSHEDDINGCOMMAND_H

#include <ctime>

class PowerSupply;

/**
 * @class LoadsheddingCommand
 * @brief Represents a load-shedding event command that can be executed on specified buildings.
 */
class LoadsheddingCommand {
public:
    /**
     * @brief Constructs a LoadsheddingCommand with the utilities department.
     * @param utilitiesDept Pointer to the DeptOfUtilities handling power resources.
     */
    LoadsheddingCommand(PowerSupply* powerSupply);

    /**
     * @brief Schedules load-shedding to occur after a specified delay.
     * @param delayInSeconds The delay in seconds before load-shedding starts.
     */
    void scheduleLoadshedding(int delayInSeconds);

    /**
     * @brief Executes the load-shedding event by triggering load-shedding in the utilities department.
     */
    void execute();

private:
    PowerSupply* powerSupply;      ///< Manages energy allocation and power resources.
    std::time_t scheduleTime;                ///< Time the load-shedding is scheduled to start.
};

#endif // LOADSHEDDINGCOMMAND_H
