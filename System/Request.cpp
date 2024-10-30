// Request.cpp
#include "Request.h"

/**
 * @brief Constructor to initialize Request with a type, building, and amount.
 * @param type The type of request (e.g., "WATER", "POWER", "WASTE").
 * @param building Pointer to the building requesting the resource.
 * @param amount Amount of the requested resource.
 */
Request::Request(std::string type, Building* building, double amount) 
    : type(type), building(building), amount(amount) {}

/**
 * @brief Get the type of the request as a string.
 * @return The request type.
 */
std::string Request::getTypeAsString() {
    return type;
}

/**
 * @brief Get the building associated with the request.
 * @return Pointer to the building.
 */
Building* Request::getBuilding() {
    return building;
}

/**
 * @brief Get the amount of the requested resource.
 * @return The amount of resource requested.
 */
double Request::getAmount() {
    return amount;
}

/**
 * @brief Destructor for Request.
 */
Request::~Request() {
    // Clean up resources if needed
}
