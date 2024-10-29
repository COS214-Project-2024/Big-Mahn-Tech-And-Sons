#include "PowerSupply.h"
#include "WaterSupply.h"
#include "WasteManagement.h"
#include "Request.h"
#include "Building.h"
#include "Electricity.h"
#include "Water.h"

int main() {
    // Create resources and buildings
    Electricity *powerResource;
    Water *waterResource;
    Building *buildingA;
    Building *buildingB;

    // Create departments
    PowerSupply powerDept("Power Department", 10000, 5000, powerResource);
    WaterSupply waterDept("Water Department", 8000, 3000, waterResource);
    WasteManagement wasteDept("Waste Management", 5000, 200);

    // Set up the chain of responsibility
    powerDept.setSuccessor(&waterDept);
    waterDept.setSuccessor(&wasteDept);

    // Create requests
    Request powerRequest(Request::Type::POWER, buildingA, 200);
    Request waterRequest(Request::Type::WATER, buildingB, 150);

    // Process requests
    powerDept.handleRequest(powerRequest);
    powerDept.handleRequest(waterRequest);

    return 0;
}
