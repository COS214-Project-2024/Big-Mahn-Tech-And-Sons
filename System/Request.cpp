#include "Request.h"
#include "Building.h"

Request(Type type, Building *building, double amount) 
{
    this->type = type;
    this->building = building;
    this->amount = amount
}

Request::Type Request::getType()
{
    return Type();
}

Building *Request::getBuilding()
{
    return building;
}

double Request::getAmount()
{
    return amount;
}

