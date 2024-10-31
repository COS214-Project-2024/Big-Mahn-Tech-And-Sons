// Request.cpp
#include "Request.h"
#include "Building.h"

Request::Request(string type, Building *building, double amount) 
{
    this->type = type;
    this->building = building;
    this->amount = amount;
}

string Request::getType()
{
    return this->type;
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
// Request::~Request() {
//     // Clean up resources if needed
// }