#include "PandemicCommand.h"
#include <iostream>
#include <random>
#include <chrono>

PandemicCommand::PandemicCommand(const std::vector<Citizen *> &citizens)
    : citizens(citizens) {}

void PandemicCommand::imposeLockdown()
{
    std::cout << "City Lockdown: Restricting all movement and gatherings.\n";
    for (auto &citizen : citizens)
    {
        citizen->decreaseHealth(10);
        citizen->decreaseSatisfaction(10); // Lockdowns can be frustrating
        citizen->notifyPR();               // Notify the PR department about the dissatisfaction
    }

    // SET ALL CURRENT LOCATIONS TO HOWE, update gotO
}

void PandemicCommand::distributeVaccines()
{
    std::cout << "Vaccine Distribution: Administering vaccines to citizens.\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distribution(5.0, 15.0);

    for (auto &citizen : citizens)
    {
        double healthBoost = distribution(gen); // Randomize vaccine effect
        citizen->increaseHealth(healthBoost);
        citizen->notifyPR();
    }
}

void PandemicCommand::manageCitizenSatisfaction()
{
    std::cout << "Satisfaction Management: Introducing mental health and social support programs.\n";
    for (auto &citizen : citizens)
    {
        citizen->increaseSatisfaction(15); // Boost satisfaction through support programs
        citizen->notifyPR();
    }
}

void PandemicCommand::trackInfectionRates()
{
    int infectedCount = 0;
    for (const auto &citizen : citizens)
    {
        if (citizen->getHealth() < 50)
        { // Simple metric: if health is below 50, consider infected
            infectedCount++;
        }
    }
    double infectionRate = (static_cast<double>(infectedCount) / citizens.size()) * 100;
    std::cout << "Tracking Pandemic: Current infection rate is " << infectionRate << "%\n";
}

void PandemicCommand::execute()
{
    std::cout << "Pandemic Event: Initiating pandemic-related commands.\n";
    imposeLockdown();
    distributeVaccines();
    manageCitizenSatisfaction();
    trackInfectionRates();
}
