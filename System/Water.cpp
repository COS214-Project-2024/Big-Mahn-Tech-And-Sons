#include "Water.h"

Water::Water(string name, double amount) : name(name), amount(amount) {}

double Water::getAmount() const
{
    return amount;
}

void Water::use(double used)
{
    if (amount > used) 
    {
        amount -= used; // Subtract used amount if enough is available
    } 
    else 
    {
        amount = 0; // Set amount to 0 if not enough is available
    }
}

void Water::reportStatus() const
{
    std::cout << "Water: " << amount << " kiloliters" << std::endl;
}
