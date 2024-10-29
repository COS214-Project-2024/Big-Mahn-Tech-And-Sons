// Request.h
#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Building;  // Forward declaration of Building

class Request 
{
public:
    enum class Type { WATER, POWER, WASTE };

    // Constructor to initialize Request with a type, building, and amount
    Request(Type type, Building* building, double amount);

    Type getType();
    Building* getBuilding();
    double getAmount();

private:
    Type type;
    Building* building;  // Pointer to Building instance
    double amount;
};

#endif // REQUEST_H
