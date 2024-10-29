/**
 * @file PandemicCommand.h
 * @brief Defines the PandemicCommand class responsible for handling events related to a pandemic.
 */

#include "PandemicCommand.h"
#include <iostream>
#include <random>
#include <chrono>

/**
 * @brief Constructs a PandemicCommand object with a list of citizens.
 * @param citizens Vector of pointers to Citizen objects, representing the citizens affected by the pandemic commands.
 */
PandemicCommand::PandemicCommand(const std::vector<Citizen*>& citizens)
    : citizens(citizens) {}

/**
 * @brief Imposes a lockdown by restricting movement and gatherings among citizens.
 * Decreases each citizen's satisfaction and notifies the PR department of dissatisfaction.
 */
void PandemicCommand::imposeLockdown() {
    std::cout << "City Lockdown: Restricting all movement and gatherings.\n";
    for (auto& citizen : citizens) {
        citizen->decreaseSatisfaction(10); // Lockdowns can be frustrating
        citizen->notifyPR(); // Notify the PR department about the dissatisfaction
    }
}

/**
 * @brief Increases healthcare funding, improving citizens' health and satisfaction.
 * Boosts health and satisfaction levels of each citizen to reflect enhanced healthcare services.
 */
void PandemicCommand::increaseHealthcareFunding() {
    std::cout << "Healthcare Boost: Allocating additional funds for citizen healthcare.\n";
    for (auto& citizen : citizens) {
        citizen->increaseHealth(15); // Increase health as a result of better services
        citizen->increaseSatisfaction(5); // Citizens feel more secure with healthcare support
        citizen->notifyPR();
    }
}

/**
 * @brief Distributes vaccines to each citizen with a randomized health boost effect.
 * Increases citizens' health and satisfaction to reflect positive public sentiment on vaccines.
 */
void PandemicCommand::distributeVaccines() {
    std::cout << "Vaccine Distribution: Administering vaccines to citizens.\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distribution(5.0, 20.0);

    for (auto& citizen : citizens) {
        double healthBoost = distribution(gen); // Randomize vaccine effect
        citizen->increaseHealth(healthBoost);
        citizen->increaseSatisfaction(10); // Positive public sentiment on vaccines
        citizen->notifyPR();
    }
}

/**
 * @brief Enforces a quarantine by isolating citizens to prevent the spread of infection.
 * Decreases health and satisfaction of each citizen due to isolation effects and restricted freedom.
 */
void PandemicCommand::quarantineCitizens() {
    std::cout << "Quarantine Enforced: Citizens are quarantined to prevent infection spread.\n";
    for (auto& citizen : citizens) {
        citizen->decreaseHealth(5); // Small negative health impact due to isolation
        citizen->decreaseSatisfaction(20); // Reduced satisfaction due to restricted freedom
        citizen->notifyPR();
    }
}

/**
 * @brief Manages citizen satisfaction by introducing mental health and social support programs.
 * Increases satisfaction of each citizen through support and wellness initiatives.
 */
void PandemicCommand::manageCitizenSatisfaction() {
    std::cout << "Satisfaction Management: Introducing mental health and social support programs.\n";
    for (auto& citizen : citizens) {
        citizen->increaseSatisfaction(15); // Boost satisfaction through support programs
        citizen->notifyPR();
    }
}

/**
 * @brief Tracks infection rates among citizens by calculating the percentage with low health.
 * Displays the infection rate, which can influence future government actions.
 */
void PandemicCommand::trackInfectionRates() {
    int infectedCount = 0;
    for (const auto& citizen : citizens) {
        if (citizen->getHealth() < 50) { // Simple metric: if health is below 50, consider infected
            infectedCount++;
        }
    }
    double infectionRate = (static_cast<double>(infectedCount) / citizens.size()) * 100;
    std::cout << "Tracking Pandemic: Current infection rate is " << infectionRate << "%\n";
}

/**
 * @brief Executes the entire pandemic event sequence.
 * Calls all pandemic management commands in sequence, simulating government actions during a pandemic.
 */
void PandemicCommand::execute() {
    std::cout << "Pandemic Event: Initiating pandemic-related commands.\n";
    imposeLockdown();
    increaseHealthcareFunding();
    distributeVaccines();
    quarantineCitizens();
    manageCitizenSatisfaction();
    trackInfectionRates();
}
