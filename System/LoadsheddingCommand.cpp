#include "LoadsheddingCommand.h"
#include "DeptOfUtilities.h"
#include <iostream>
#include <ctime>

LoadsheddingCommand::LoadsheddingCommand(DeptOfUtilities* utilitiesDept)
    : utilitiesDept(utilitiesDept), scheduleTime(0) {}

void LoadsheddingCommand::scheduleLoadshedding(int delayInSeconds) {
    scheduleTime = std::time(0) + delayInSeconds;
    std::cout << "Load-shedding scheduled to start in " << delayInSeconds << " seconds." << std::endl;
}

void LoadsheddingCommand::execute() {
    if (std::time(0) >= scheduleTime) {
        std::cout << "Executing load-shedding event..." << std::endl;
        utilitiesDept->initiateLoadshedding();
    } else {
        std::cout << "Load-shedding event not yet scheduled to execute." << std::endl;
    }
}
