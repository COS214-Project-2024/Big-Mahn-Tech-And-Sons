#include "Government.h"
#include "DeptOfTransportation.h"
#include "DeptOfFinance.h"
#include "DeptOfPR.h"
#include "DeptOfUtilities.h"
#include "DeptOfHousing.h"

#include "WaterSupply.h"
#include "PowerSupply.h"
#include "WasteManagement.h"
#include "Water.h"
#include "Power.h"

#include "PandemicCommand.h"
#include "IncreaseEconomy.h"
#include "LoadsheddingCommand.h"
#include "NaturalDisasterCommand.h"
#include "RecessionCommand.h"
#include "FestivalCommand.h"
#include "BabyBoom.h"

#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>

Government::Government()
{
   simulationIsActive = true;
   transport = DeptOfTransportation::getInstance();
   housing = new DeptOfHousing(2000000);
   Water *water = new Water( 10000);
   Power *power = new Power( 100000);
   DeptOfUtilities*  waterSup = new WaterSupply(5000.02, 100000, water);
   DeptOfUtilities* powerSup = new PowerSupply(1539, 1335984, power);
  DeptOfUtilities* wasteSup = new WasteManagement( 1432, 3544.02);

   waterSup->setSuccessor(powerSup);
   powerSup->setSuccessor(wasteSup);

   TaxManager *taxMan = new TaxManager();
   finance = new DeptOfFinance(taxMan);
   PR = new DeptOfPR(housing, waterSup, finance);


   // Seed the random number generator
   srand(time(0));

   // set width and height of building
   int w  = 2;
   int h = 2;

   housing->createCommercialBuilding(commercialTypes[rand() % 4]);
   housing->createResidentialBuilding(residentialTypes[rand() % 3]);
   housing->createLandmarkBuilding(landmarkTypes[rand() % 3]);
   housing->createIndustrialBuilding(industrialTypes[rand() % 4]);
   // initialize starting citizens

   transport->add_Road(0,0,10,"right","R1");
   transport->add_Road(4,0,10,"right","R2");
   transport->add_Road(9,0,10,"right","R3");
   transport->add_Road(0,19,10,"down","R4");
   transport->add_Road(19,0,20,"right","R5");

   transport->printCityGrid();
   for (int i = 0; i < 5; i++)
   {
      string name = "ID: " + to_string(i) + " ";
      Citizen *c1 = new Citizen(name, PR);

      housing->getBuildings().at(i % 4)->addTenant(PR->getCitizen(i));
      // transport->add_Building()

         // ADD BUILDINGS TO CITY GRID
      transport->add_Building(w,h,housing->getBuildings().at(i % 4));
      //std::cout << "added building" <<housing->getBuildings().at(i % 4)->getType() << endl;

   }
  
   auto gridCoordinates =   transport->add_Building(w,h,housing->getBuildings().at(1));
 //transport->printCityGrid();
   std::cout << "Removing " << housing->getBuildings().at(2 % 4)->getType() << endl;
   transport->remove_Building(gridCoordinates);
   //   transport->printCityGrid();

  // Request req("water", housing->getBuildings().at(1 % 4), 100);


   /*
      pandemic = new PandemicCommand(citizens);
      economicDownturn = new RecessionCommand(finance, citizens.at(1), housing.);
      naturalDisaster = new NaturalDisasterCommand()
      loadsheding = new LoadsheddingCommand();
      festive = new FestivalCommand();
      babyBoom = new BabyBoom();
      increaseEconomy = new IncreaseEconomy();

   */

}

void Government::addNewCitizens()
{
   
   int newCitizensCount = rand() % 5 + 1; // Random number of new citizens per year
   for (int i = 0; i < newCitizensCount; i++)
   {
      std::string name = "NewCitizen_" + std::to_string(this->PR->numCitizens());

      Citizen *newCitizen = new Citizen(name, PR);

      // Assign the new citizen to an available building
      if (!housing->getBuildings().empty())
      {
         housing->getBuildings().at(rand() % housing->getBuildings().size())->addTenant(newCitizen);
      }
   }
   
}

void Government::runSim()
{
 int year = 2024;
    bool simulationRunning = true;

    while (simulationRunning) {
        std::cout << "\n--- Year " << year << " ---\n";
        std::cout << "Select an option:\n1. Add Building\n2. Add Road\n3. Run Simulation for this Year\n4. View City\n5. Exit\nChoice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addBuilding();
                break;
            case 2:
                addRoad();
                break;
            case 3:
                // Execute yearly simulation actions
                simulateYear();
                year++; // Increment year after the simulation completes
                break;
            case 4:
                std::cout << "Displaying city...\n";
                displayCity();
                break;
            case 5:
               std::cout << "Exiting simulation...\n";
                simulationRunning = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void Government::simulateYear() {
    // Trigger a random event from the available commands
    int eventIndex = rand() % 7; // Adjust based on the number of commands
    /*
    switch (eventIndex) {
        case 0: pandemic->execute(); break;
        case 1: economicDownturn->execute(); break;
        case 2: naturalDisaster->execute(); break;
        case 3: loadshedding->execute(); break;
        case 4: festive->execute(); break;
        case 5: babyBoom->execute(); break;
        case 6: increaseEconomy->execute(); break;
    }
*/
    // Age all citizens by one year
    for (int i = 0; i < PR->numCitizens(); i++) {
        PR->getCitizen(i)->getOlder();
        PR->getCitizen(i)->Spend(1200);
        
    }

    // Add new citizens at the end of each year
    addNewCitizens();

    std::cout << "Yearly simulation complete.\n";


}
void Government::handleCitizenNeeds()
{
}

void Government::simulateDailyOperations() {
    // Seed for randomness
    /*
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> commandDist(0, 4); // 0-4 for different commands, including "stay home"
    std::uniform_int_distribution<> delayDist(0, 2);   // 0-2 hours delay to stagger citizen actions

    // Possible commands for the day
    /*
    std::vector<std::function<void(Citizen*)>> commands = {
        [](Citizen* c) { c->setGoToCommand(new GoToWork()); },
        [](Citizen* c) { c->setGoToCommand(new GoToEnt()); },
        [](Citizen* c) { c->setGoToCommand(new GoToLeisureCommand()); }, // Leisure activity
        [](Citizen* c) { c->setGoToCommand(new GoHomeCommand()); },
        nullptr // Represents staying home for the day
    };
*/

/*
    // Iterate through each citizen with varied activities
    for (int i = 0; i < PR->numCitizens();i++) {
        int commandIndex = commandDist(gen); // Randomly select a command
        int delay = delayDist(gen);          // Random delay
        Citizen* citizen = PR->getCitizen(i);

        if (commands[commandIndex] != nullptr) {
            // Assign the selected command and execute it after a delay
            commands[commandIndex](citizen);
            // Simulate delay before execution
            std::this_thread::sleep_for(std::chrono::hours(delay));
            citizen->go()->execute(citizen);
            
            // Cleanup if commands are dynamically allocated
           // delete citizen->getGoTo();
        } else {
            // Citizen stays home; no command assigned
            std::cout << citizen->getName() << " is staying home today.\n";
        }
    }
    */
}

void Government::stopSim()
{
   simulationIsActive = false;
}  


int get_int() {
    int value;
    while (true) {
        cout << "Enter an option: ";
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter an integer: ";
        } else {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

void clearTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int DeptOfTransportation_menu(DeptOfTransportation* dept) {
    int option = 0;
    bool status;
    int a, b, c;
    std::string x, y;
    
    while (option != 5) {
        clearTerminal();
        cout << ".............. DEPARTMENT OF TRANSPORTATION ..............\n\n";
        cout << "1 - ADD ROAD\n";
        cout << "2 - ADD BUILDING\n";
        cout << "3 - REMOVE ROAD\n";
        cout << "4 - REMOVE BUILDING\n";
        cout << "5 - RETURN TO MAIN MENU\n\n";
        
        option = get_int();
        switch (option) {
            case 1:
                dept->printCityGrid();
                cout << "start row: ";
                cin >> a;
                cout << "start column: ";
                std::cin >> b;
                cout << "road length: ";
                cin >> c;
                cout << "road direction: ";
                cin >> x;
                cout << "road name: ";
                cin >> y;
                status = dept->add_Road(a, b, c, x, y);
                clearTerminal();
                dept->printCityGrid();
                cout << (status ? "Road added!\n" : "Road not added!\n");
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Press any key to continue";
                cin.get();
                break;
            case 2:
                cout << "Adding building feature...\n";
                break;
            case 3:
                cout << "Removing road feature...\n";
                break;
            case 4:
                cout << "Removing building feature...\n";
                break;
            case 5:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid option. Choose between 1 and 5.\n";
                break;
        }
    }
    return 0;
}

/*
void deptTransportation() {
    int w = 1, x, y, z;
    string a, b;
    
    while (w != 7) {
        clearTerminal();
        cout << ".............. CITY GRID MENU ..............\n\n";
        cout << "1) ADD ROAD\n";
        cout << "2) REMOVE ROAD (streetName only)\n";
        cout << "3) REMOVE ROAD (standard way)\n";
        cout << "4) PRINT ROAD NETWORK\n";
        cout << "5) PRINT STREETS\n";
        cout << "6) ADD BUILDING\n";
        cout << "7) EXIT TO MAIN MENU\n\n";
        
        w = get_int();
        
        switch (w) {
            case 1:
                cout << "\nstart_row: "; cin >> x;
                cout << "start_column: "; cin >> y;
                cout << "road_length: "; cin >> z;
                cout << "road_direction: "; cin >> a;
                cout << "street_name: "; cin >> b;
                grid.addRoad(x, y, z, a, b);
                clearTerminal();
                grid.printCityGrid();
                break;
            case 2:
                cout << "Remove road by street name\n";
                break;
            case 3:
                cout << "Remove road (standard way)\n";
                break;
            case 4:
                grid.printCityRoadNetwork();
                break;
            case 5:
                grid.printCityStreets();
                break;
            case 6:
                cout << "Adding building to grid\n";
                break;
            case 7:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid option. Choose between 1 and 7.\n";
                break;
        }
    }
}
*/

void Government::addBuilding() {
    string buildingType;
    int x, y;
    
    cout << "Enter building type (Commercial, Residential, Industrial, Landmark): ";
    cin >> buildingType;

    // Determine the type of building to create and add it to housing
    if (buildingType == "Commercial") {
        housing->createCommercialBuilding(commercialTypes[rand() % 4]);
    } else if (buildingType == "Residential") {
        housing->createResidentialBuilding(residentialTypes[rand() % 3]);
    } else if (buildingType == "Industrial") {
        housing->createIndustrialBuilding(industrialTypes[rand() % 4]);
    } else if (buildingType == "Landmark") {
        housing->createLandmarkBuilding(landmarkTypes[rand() % 3]);
    } else {
        cout << "Invalid building type.\n";
        return;
    }

    // Get the last created building and add it to the grid
    auto building = housing->getBuildings().back();
    cout << "Enter coordinates (x y) for the building: ";
    cin >> x >> y;

    int w = 2, h = 2; // Set building dimensions
    transport->add_Building(w, h, building);
    cout << "Added " << building->getType() << " at (" << x << ", " << y << ")\n";

    // Optionally display the grid after adding
    transport->printCityGrid();
}

void Government::displayCity() {
    transport->printCityGrid();
    this->housing->listBuildings();
}

void Government::addRoad() {
    int x, y, roadLength;
    string roadDirection, roadID;

    cout << "Enter road ID: ";
    cin >> roadID;
    cout << "Enter starting coordinates (x y): ";
    cin >> x >> y;
    cout << "Enter road length: ";
    cin >> roadLength;
    cout << "Enter direction (right or down): ";
    cin >> roadDirection;

    if (roadDirection == "right" || roadDirection == "down") {
        transport->add_Road(x, y, roadLength, roadDirection, roadID);
        cout << "Added road " << roadID << " starting at (" << x << ", " << y 
             << ") going " << roadDirection << " for " << roadLength << " units.\n";
    } else {
        cout << "Invalid direction.\n";
    }

    // Optionally display the grid after adding
    transport->printCityGrid();
}