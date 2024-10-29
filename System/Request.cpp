#include "Request.h"
#include "Building.h"

Request(Type type, Building *building, double amount) :  type(type), building(building), amount(amount) {}

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