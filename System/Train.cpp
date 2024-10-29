#include "Train.h"
#include <iostream>
#include <chrono>
#include <thread>


std::string Train::getName() const
{
    return "Train";
}

double Train::getCost() const
{
    return 50;
}

void Train::execute() const
{
     std::cout<<"Citizen has now climbed onto the Train \n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
