// Request.h
#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include "Building.h"
#include <iostream>
using namespace std;

class Request {
public:
    /**
     * @brief Constructor to initialize Request with a type, building, and amount.
     * @param type The type of request (e.g., "WATER", "POWER", "WASTE").
     * @param building Pointer to the building requesting the resource.
     * @param amount Amount of the requested resource.
     */
    Request(std::string type, Building* building, double amount);

    /**
     * @brief Get the type of the request as a string.
     * @return The request type.
     */
    std::string getTypeAsString();

    /**
     * @brief Get the building associated with the request.
     * @return Pointer to the building.
     */
    Building* getBuilding();

    /**
     * @brief Get the amount of the requested resource.
     * @return The amount of resource requested.
     */
    double getAmount();

    // ~Request();

private:
    std::string type;       /**< The type of request (e.g., "WATER", "POWER", "WASTE"). */
    Building* building;     /**< Pointer to the building instance making the request. */
    double amount;          /**< The amount of the resource requested. */
};

#endif // REQUEST_H