#include "PublicTrans.h"
#include <iostream>
#include <chrono>
#include <thread>

std::string PublicTrans::getName() const
{
    return "Public Transport";
}

double PublicTrans::getCost() const
{
    return 150;
}

void PublicTrans::execute() const
{
    std::cout << "Citizen has now got in public transport \n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
}