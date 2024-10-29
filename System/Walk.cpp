#include "Walk.h"
#include <iostream>
#include <chrono>
#include <thread>



std::string Walk::getName() const
{
    return "Walk";
}

double Walk::getCost() const
{
    return 0.0;
}

void Walk::execute() const
{
     std::cout<<"Citizen is going to Walk \n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
