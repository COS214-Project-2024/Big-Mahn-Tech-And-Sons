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
#include "Settings.h"

#include "GoAirport.h"
#include "GoHome.h"
#include "GoTrain.h"
#include "GoHos.h"
#include "GoSchool.h"
#include "GoToCommand.h"
#include "GoToEnt.h"

#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>
#include "GoToWork.h"

Government::Government()
{
   simulationIsActive = true;
   transport = DeptOfTransportation::getInstance();
   housing = new DeptOfHousing(200000000);
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


housing->createLandmarkBuilding("Park");
   // initialize starting citizens

   transport->add_Road(0,0,10,"right","R1");
   transport->add_Road(4,0,10,"right","R2");
   transport->add_Road(9,0,10,"right","R3");
   transport->add_Road(0,19,10,"down","R4");
   transport->add_Road(19,0,20,"right","R5");

 //  transport->printCityGrid();
   for (int i = 0; i < 5; i++)
   {
      string name = "ID: " + to_string(i) + " ";
      Citizen *c1 = new Citizen(name, PR);

      transport->add_Building(w,h,housing->getBuildings().at(i % 3));

      housing->getBuildings().at(i % 3)->addTenant(PR->getCitizen(i));
      // transport->add_Building()

         // ADD BUILDINGS TO CITY GRID
      //std::cout << "added building" <<housing->getBuildings().at(i % 4)->getType() << endl;

   }
  
//    auto gridCoordinates =   transport->add_Building(w,h,housing->getBuildings().at(1));
 //transport->printCityGrid();
//    std::cout << "Removing " << housing->getBuildings().at(2 % 4)->getType() << endl;
//    transport->remove_Building(gridCoordinates);
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

void Government::runSim() // main_menu
{
    Settings settings;
    int option;
    cityname = settings.get_string(2,20,"Enter a city Name:");
    while(option!=2)
    {
        option = main_menu(settings);
        
    }

    cout<<"\n\nEnd of "<<cityname<<" simulation\n\n";
}

int Government::main_menu(Settings settings)
{
    settings.clear_terminal();
    cout<<UNDERLINE<<BRIGHT_YELLOW<<BOLD<<"\n"<<cityname<<"\n\n"<<RESET;
    int option;
    cout<<"1) START CITY BUILDER SIMULATION\n"
        <<"2) EXIT SIMULATION\n";
    option = settings.get_int(1,2,"select option: ");
    switch (option)
    {
    case 1:
        do
        {
            option = pov_menu(settings);
            // 3 options in pov menu
        }
        while(option!=3);
        option=-1;
        break;

    case 2:
        option = 2;
        break;
    }
    return option;
}

int Government::pov_menu(Settings settings)
{
    settings.clear_terminal();
    cout<<UNDERLINE<<BRIGHT_YELLOW<<BOLD<<"\n"<<cityname<<"\n\n"<<RESET;
    int option;
    cout<<"1) VIEW CITIZEN POV\n"
        <<"2) VIEW GOVERNMENT POV\n"
        <<"3) EXIT\n";
    option = settings.get_int(1,3,"select option: ");
    switch (option)
    {
    case 1:
        do
        {
            option = citizen_pov_menu(settings);
        }
        while(option!=8);
        option=-1;
        break;

    case 2:
        do
        {
            option = government_pov_menu(settings); 
        }
        while(option!=3);
        option=-1;
        break;

    case 3:
        option = 3;
        break;
    }
    return option;
}

int Government::city_grid_menu(Settings settings)
{
    settings.clear_terminal();
    cout<<UNDERLINE<<BRIGHT_YELLOW<<BOLD<<"\n"<<cityname<<"\n\n"<<RESET;
    int option,x,y,z;
    string buildingType,a,b;
    string buildingname;
    Building* building;

    cout<<BOLD<<BRIGHT_GREEN<<"1) ADD "<<RESET<<"ROAD"<<endl
        <<BOLD<<BRIGHT_GREEN<<"2) ADD "<<RESET<<"BUILDING"<<endl<<endl
        <<BOLD<<BRIGHT_RED<<"3) REMOVE "<<RESET<<"ROAD - "<<ITALICS<<" by street name"<<RESET<<endl
        <<BOLD<<BRIGHT_RED<<"4) REMOVE "<<RESET<<"ROAD - "<<ITALICS<<" by co-ordinate"<<RESET<<endl
        <<BOLD<<BRIGHT_RED<<"5) REMOVE "<<RESET<<"BUILDING"<<endl<<endl
        <<"6) PRINT CITYGRID - "<<ITALICS<<" buildings and roads"<<RESET<<endl
        <<"7) PRINT ROAD NETWORK - "<<ITALICS<<" roads only"<<RESET<<endl
        <<"8) PRINT CITY STREETS - "<<ITALICS<<" streets only"<<RESET<<endl
        <<"9) EXIT\n";

    option = settings.get_int(1,9,"select option: ");
    
    switch (option)
    {
    case 1:
        transport->printRoadNetwork();
        x = settings.get_int(0,1000,"Enter row co-ordinate: ");
        y = settings.get_int(0,1000,"Enter column co-ordinate: ");
        z = settings.get_int(0,1000,"Enter Road Length: ");
        a = settings.get_string(2,5,"Enter direction the road should go [up,down,left,right]: ");
        b = settings.get_string(1,2,"Enter street name: ");

        transport->add_Road(x,y,z,a,b);

        transport->printCityGrid();
        settings.enter_to_continue();
        option=-1;
        break;

    case 2:
        buildingType = settings.get_string(8,13,"Enter building type [Commercial, Residential, Industrial, Landmark]");
        if(buildingType=="Commercial")
        {housing->createCommercialBuilding(commercialTypes[rand()%4]);}
        else if(buildingType=="Residential")
        {housing->createResidentialBuilding(residentialTypes[rand()%3]);}
        else if(buildingType=="Industrial")
        {housing->createIndustrialBuilding(industrialTypes[rand()%4]);}
        else if(buildingType=="Landmark")
        {housing->createLandmarkBuilding(landmarkTypes[rand()%3]);}
        else
        {cout<<"Invalid building type\n"; option=-1; break;}

        building = housing->getBuildings().back();
        x = settings.get_int(1,30,"Enter building length: ");
        y = settings.get_int(1,30,"Enter building width: ");
        transport->add_Building(x,y,building);
        transport->printCityGrid();
        settings.enter_to_continue();

        option=-1;
        break;

    case 3:
        a = settings.get_string(0,2,"Enter street name: ");
        transport->remove_Road(a);

        transport->printCityGrid();
        settings.enter_to_continue();
        option=-1;
        break;

    case 4:
        x = settings.get_int(-1000,1000,"Enter row co-ordinate: ");
        y = settings.get_int(0,1000,"Enter column co-ordinate: ");
        z = settings.get_int(0,30,"Enter road legnth: ");
        a = settings.get_string(2,5,"Enter the roads direction [up,down,left,right]");
        transport->remove_Road(x,y,z,a);

        transport->printRoadNetwork();
        settings.enter_to_continue();

        option=-1;
        break;

    case 5:
        this->housing->listBuildings();
        buildingname = settings.get_string(0,30,"Choose building to delete from building list\n");        
        this->housing->removeBuildingByName(buildingname);
        building = this->housing->getBuildingByName(buildingname);
        this->transport->remove_Building(building->getGridCoordinates());

        transport->printCityGrid();
        settings.enter_to_continue();
        option=-1;
        break;

    case 6:
        transport->printCityGrid();
        settings.enter_to_continue();
        option=-1;
        break;

    case 7:
        transport->printRoadNetwork();
        settings.enter_to_continue();
        option=-1;
        break;

    case 8:
        transport->printCityStreets();
        settings.enter_to_continue();
        option=-1;
        break;

    case 9:
        option = 9;
        break;
    }
    
    return option;
}

int Government::government_pov_menu(Settings settings)
{
    settings.clear_terminal();
    cout<<UNDERLINE<<BRIGHT_YELLOW<<BOLD<<"\n"<<cityname<<"\n\n"<<RESET;
    int option;
    cout<<"1) VIEW CITY GRID\n"
        <<"2) VIEW DEPARTMENT STATISTICS\n"
        <<"3) EXIT\n";
    option = settings.get_int(1,3,"select option: ");
    switch (option)
    {
    case 1:
        do
        {
            option = city_grid_menu(settings);
        }
        while(option!=9);
        option=-1;
        break;

    case 2:
        do
        {
            option = government_stats_menu(settings);
        }
        while(option!=4);
        option=-1;
        break;

    case 3:
        option = 3;
        break;
    }
    return option;
}

int Government::government_stats_menu(Settings settings)
{
    settings.clear_terminal();
    cout<<UNDERLINE<<BRIGHT_YELLOW<<BOLD<<"\n"<<cityname<<"\n\n"<<RESET;
    int option;
    cout<<"1) DISPLAY DEPARTMENT OF FINANCE STATS\n"
        <<"2) DISPLAY DEPARTMENT OF HOUSING STATS\n"
        <<"3) DISPLAY DEPARTMENT OF PR STATS\n"
        <<"4) EXIT\n";
    option = settings.get_int(1,4,"select option: ");
    switch (option)
    {
    case 1:
        this->finance->display();

        settings.enter_to_continue();

        option=-1;
        break;

    case 2:
        this->housing->displayAllBuildings();
        
        settings.enter_to_continue();


        option=-1;
        break;

    case 3:
        
        this->PR->displayStats();
        
        settings.enter_to_continue();

        option=-1;
        break;

    case 4:
        option = 4;
        break;
    }
    return option;
}

int Government::citizen_pov_menu(Settings settings)
{
    settings.clear_terminal();
    cout<<UNDERLINE<<BRIGHT_YELLOW<<BOLD<<"\n"<<cityname<<"\n\n"<<RESET;
    int option;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> commandDist(0, this->PR->numCitizens()-1); // 0-4 for different commands, including "stay home"
    int i = commandDist(gen);
    string name= this->PR->getCitizen(i)->getName();
    Citizen* c =  this->PR->getCitizen(i);
    GoAirport* airport = new GoAirport(c,this->housing);
    GoHome* home = new GoHome(c, this->housing);
    GoToWork* work = new GoToWork(c, this->housing);
    GoSchool* school = new GoSchool(c, this->housing);
    GoToEnt* fun = new GoToEnt(c, this->housing);
    GoTrain* goTrain = new GoTrain(c, this->housing);


    cout<<ITALICS<<" This is a random citizen (you can interact with) :\n"<<RESET<<name<<RESET
        <<"\n1) GO TO TRAINSTATION\n"
        <<"2) GO TO WORK\n"
        <<"3) GO HAVE FUN\n"
        <<"4) GO TO AIRPORT\n"
        <<"5) GO TO HOME\n"
        <<"6) GO TO SCHOOL\n"
        <<"7) VIEW CITIZEN STATS\n"
        <<"8) EXIT SIMULATION\n";
    option = settings.get_int(1,8,"select option: ");
    switch (option)
    {
    case 1:
        goTrain->execute();

        settings.enter_to_continue();
        option=-1;
        break;

    case 2:
        
        work->execute();

        settings.enter_to_continue();
        option=-1;
        break;

    case 3:
        
        fun->execute();
        settings.enter_to_continue();
        
        option=-1;
        break;

    case 4:
        
        airport->execute();
        settings.enter_to_continue();
        
        option=-1;
        break;

    case 5:
        
        home->execute();
        settings.enter_to_continue();
        
        option=-1;
        break;

    case 6:
        
        school->execute();
        settings.enter_to_continue();
        
        option=-1;
        break;

    case 7:
        c->display();

        settings.enter_to_continue();

        option=-1;
        break;

    case 8:
        option = 8;
        break;
    }
    return option;
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