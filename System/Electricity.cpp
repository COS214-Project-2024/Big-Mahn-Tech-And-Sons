#include "Electricity.h"

Electricity::Electricity(std::string& name, double amount) : name(name), amount(amount) {}

double Electricity::getAmount() const
{
    return amount;
}

void Electricity::use(double used)
{
    if (amount > used) {
        amount -= used; // Subtract used amount if enough is available
    } else {
        amount = 0; // Set amount to 0 if not enough is available
    }
}

void Electricity::reportStatus() const
{
    std::cout << "Electricity: " << amount << " units remaining." << std::endl;
}
