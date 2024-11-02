#include "Water.h"

Water::Water(double amount) : amount(amount) {}

double Water::getWaterAmount()
{
    return amount;
}

void Water::useWater(double used)
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
