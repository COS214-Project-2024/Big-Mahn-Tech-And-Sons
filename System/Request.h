#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include "Building.h"  // Ensure this header is included

class Request 
{
public:
    enum class Type { WATER, POWER, WASTE };

private:
    Type type;
    Building* building;  // Pointer to Building instance
    double amount;

public:
    // Constructor to initialize Request with a type, building, and amount
    Request(Type type, Building* building, double amount);

    Type getType();
    Building* getBuilding();
    double getAmount();
};

#endif // REQUEST_H