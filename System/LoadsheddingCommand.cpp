#include "LoadsheddingCommand.h"
#include "DeptOfUtilities.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>

LoadsheddingCommand::LoadsheddingCommand() : scheduleTime(0), energyAllocated(0) {}

/**
 * @brief Cuts electricity to specific buildings during load-shedding.
 *
 * This method iterates over the buildings that are affected
 * and simulates the action of cutting electricity.
 */
void LoadsheddingCommand::cutElectricityToBuildings() {
    if (buildingsAffected.empty()) {
        std::cout << "No buildings selected for load-shedding." << std::endl;
        return;
    }

    std::cout << "Cutting electricity to the following buildings:" << std::endl;
    for (const auto& building : buildingsAffected) {
        std::cout << "- " << building << std::endl;
    }
}

/**
 * @brief Notifies citizens of upcoming outages.
 *
 * This method sends notifications to the affected buildings
 * about the upcoming load-shedding events, including the scheduled time.
 */
void LoadsheddingCommand::notifyCitizensOfOutages() {
    for (const auto& building : buildingsAffected) {
        std::string notification = "Notice: Load-shedding will occur for " + building + " at " + std::ctime(&scheduleTime);
        notifications[building] = notification;
        std::cout << notification << std::endl;
    }
}

/**
 * @brief Schedules load-shedding events.
 *
 * This method records the current time as the scheduled time for load-shedding.
 */
void LoadsheddingCommand::scheduleLoadshedding() {
    scheduleTime = std::time(nullptr);  // Current time
    std::cout << "Load-shedding scheduled at: " << std::ctime(&scheduleTime) << std::endl;
}

/**
 * @brief Allocates energy resources during load-shedding.
 *
 * This method simulates the allocation of energy resources
 * necessary for managing the load-shedding events.
 */
void LoadsheddingCommand::allocateEnergyResources() {
    energyAllocated = 100;  // Assume we allocate 100 units of energy
    std::cout << energyAllocated << " units of energy allocated for load-shedding." << std::endl;
}

/**
 * @brief Manages complaints related to utility outages.
 *
 * This method allows citizens to submit complaints and tracks their statuses.
 * Complaints can be marked as resolved or unresolved.
 *
 * @param complaintId A unique identifier for the complaint.
 * @param description A description of the complaint.
 */
void LoadsheddingCommand::manageUtilityComplaints(const std::string& complaintId, const std::string& description) //still need more ideas for implemnting the following 
{
    complaints[complaintId] = description;  // Store the complaint with its ID
    std::cout << "Complaint ID: " << complaintId << " received: " << description << std::endl;

    // Here we could implement logic to resolve complaints after some processing
    std::cout << "Status: Unresolved" << std::endl;  // Initial status

    // For simplicity, let's resolve it immediately for demo purposes
    std::cout << "Status: Resolved" << std::endl;
    complaints.erase(complaintId);  // Remove the complaint after resolving
}

/**
 * @brief Executes the load-shedding command.
 *
 * This method orchestrates the entire load-shedding process
 * by calling the necessary methods in the correct order.
 */
void LoadsheddingCommand::execute() 
{
     // Step 1: Schedule the load-shedding
    scheduleLoadshedding();


    // Step 2: Cut electricity to the affected buildings
    if (!buildingsAffected.empty()) {
        cutElectricityToBuildings();
    } else {
        std::cerr << "No buildings affected. Skipping electricity cut." << std::endl;
        return; 
    }

    // Step 3: Allocate energy resources
    allocateEnergyResources();

    // Step 4: Notify citizens of upcoming outages
    notifyCitizensOfOutages();

    // Step 5: Manage any incoming complaints
    // This could be modified to handle complaints based on user input
    //Not sure if this would be necessary 
    if (!complaints.empty()) {
        for (const auto& complaint : complaints) {
            std::cout << "Processing complaint ID: " << complaint.first << ", Description: " << complaint.second << std::endl;
           
        }
    }
    
    std::cout << "Load-shedding command executed successfully." << std::endl; 
}

/**
 * @brief Sets the buildings affected by load-shedding.
 *
 * @param buildings A vector of building names to be affected.
 */
void LoadsheddingCommand::setBuildingsAffected(const std::vector<std::string>& buildings) 
{
    buildingsAffected = buildings;
}
