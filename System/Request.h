// Request.h
#ifndef REQUEST_H
#define REQUEST_H

#include <string>
class Building;

using namespace std;
class Request {
private:

    double amount;
    string type;
    Building* building;
public:
    // Constructor to initialize Request with a type, building, and amount
    Request(string type,Building* building, double amount);

    string getType();
    Building* getBuilding();

    /**
     * @brief Get the amount of the requested resource.
     * @return The amount of resource requested.
     */
    double getAmount();

    // ~Request();

};
#endif // REQUEST_H
