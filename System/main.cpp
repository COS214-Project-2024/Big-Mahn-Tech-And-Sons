#include <iostream>
#include "Citizen.h"
#include "ResidentialBuildingCreator.h"
#include "CommercialBuildingCreator.h"
#include "visitHousing.h"
#include "Budget.h"
#include "DeptOfUtilities.h"
#include "PowerSupply.h"
#include "WaterSupply.h"
#include "WasteManagement.h"
#include "Power.h"
#include "Water.h"
#include "Request.h"
#include "Building.h"

#include <iostream>
using namespace std;

int main() {
    
    // Create a budget
    Budget cityBudget(10000);
    cityBudget.reportStatus();

    // Create a residential building and citizen
    ResidentialBuildingCreator resCreator;
    auto house = resCreator.createBuilding("House");
    Citizen john("John Doe", 75, 0, 0, nullptr);
    
    // Add citizen to residential building (mocking some functionality)
    house->addResident(&john);

    // Create tax manager and collect taxes
    visitHousing taxManager;
    house->accept(&taxManager);
    cityBudget.accept(&taxManager);

    // Report budget status after tax collection
    cityBudget.reportStatus();
    

    return 0;
}
