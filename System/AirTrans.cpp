#include "AirTrans.h"
#include <chrono>
#include <thread>
#include <iostream>

std::string AirTrans::getName() const 
{
    return "AirPlane";
}


double AirTrans::getCost() const 
{
    return 1500.99;
}

void AirTrans::execute() const
{

    std::cout<<"Citizen has now boarded the Plane \n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
}


