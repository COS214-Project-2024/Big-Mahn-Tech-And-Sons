#include "LoadsheddingCommand.h"
#include "PowerSupply.h"
#include <iostream>
#include <ctime>

LoadsheddingCommand::LoadsheddingCommand(PowerSupply* powerSupply)
    : powerSupply(powerSupply), scheduleTime(0) {}

void LoadsheddingCommand::scheduleLoadshedding(int delayInSeconds) {
    scheduleTime = std::time(0) + delayInSeconds;
    std::cout << "Load-shedding scheduled to start in " << delayInSeconds << " seconds." << std::endl;
}

void LoadsheddingCommand::execute() {
    if (scheduleTime) {
        std::cout << "Executing load-shedding event..." << std::endl;
        powerSupply->powerShutDown();
    } else {
        std::cout << "Load-shedding event not yet scheduled to execute." << std::endl;
    }
}
