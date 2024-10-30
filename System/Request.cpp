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

Building *Request::getBuilding()
{
    return building;
}

double Request::getAmount()
{
    return amount;
}

