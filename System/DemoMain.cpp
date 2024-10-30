#ifndef COLORS_H
#define COLORS_H

// Reset
#define RESET "\033[0m"

// Regular Colors
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Bright Colors
#define BRIGHT_BLACK "\033[90m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

// Background Colors
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

// Bold and Underline
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

#endif // COLORS_H


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define BRIGHT_GREEN "\033[92m"
#define UNDERLINE "\033[4m"

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "DeptOfTransportation.h"

int main() {

    return 0;
}


void clearTerminal() {
#ifdef _WIN32
    system("cls");  // Clear the screen on Windows
#else
    system("clear");  // Clear the screen on Unix/Linux/macOS
#endif
}


void deptTransportation()
{
    DeptOfTransportation* grid = DeptOfTransportation::getInstance();

    int w,x,y,z;
    string a,b;
    vector<pair<int,int>> pair;
    w=1;
    while (w==1 || w==2 || w==3 || w==4 || w==5 || w==6)
    {
        cout<<UNDERLINE<<".............. MENU ................\n\n\n"<<RESET;
        cout<<"1)  "<< BRIGHT_GREEN<<"ADD "<<YELLOW<<"ROAD\n"<<RESET
            <<"2)  "<<RED<<"REMOVE"<<YELLOW<<" ROAD "<<RESET<<"(streetName only)\n"
            <<"3)  "<<RED<<"REMOVE"<<YELLOW<<" ROAD "<<RESET<<"(standard only)\n"
            <<"4)  PRINT ROADNETWORK\n"<<RESET
            <<"5)  PRINT STREETS\n"<<RESET
            <<"6)  "<< BRIGHT_GREEN<<"ADD "<<CYAN<<"BUILDING\n"<<RESET
            <<"7)  EXIT PROGRAM\n\n"<<RESET
            <<"option: ";
        cin>>w;
        cout<<"\n";
            switch (w)
            {
            case 1:
                clearTerminal();
        cout<<UNDERLINE<<".............. CITY GRID ...........\n\n\n"<<RESET;
                grid->printCityGrid();
                cout<<"\nstart_row:";
                cin>>x;
                cout<<"start_column:";
                cin>>y;
                cout<<"road_length:";
                cin>>z;
                cout<<"road_direction:";
                cin>>a;
                cout<<"street_name:";
                cin>>b;
                grid->add_Road(x,y,z,a,b);

                clearTerminal();
                grid->printCityGrid();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"\nPress any key to continue";
                cin.get();
                clearTerminal();
                break;

            case 2:
        cout<<UNDERLINE<<".............. CITY STREETS ........\n\n\n"<<RESET;
                grid->printCityStreets();
                cout<<"\nstreet_name:";
                cin>>b;
                grid->remove_Road(b);

                clearTerminal();
                grid->printCityStreets();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"\nPress any key to continue";
                cin.get();
                clearTerminal();
                break;

            case 3:
        cout<<UNDERLINE<<".............. ROAD GRID ...........\n\n\n"<<RESET;
                grid->printRoadNetwork();
                cout<<"\nstart_row:";
                cin>>x;
                cout<<"start_column:";
                cin>>y;
                cout<<"road_length:";
                cin>>z;
                cout<<"road_direction:";
                cin>>a;
                grid->remove_Road(x,y,z,a);

                clearTerminal();
                grid->printCityGrid();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"\nPress any key to continue";
                cin.get();
                clearTerminal();
                break;
            
            case 4:
        cout<<UNDERLINE<<".............. ROAD GRID ...........\n\n\n"<<RESET;
                grid->printRoadNetwork();
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"\nPress any key to continue";
                cin.get();
                clearTerminal();
                break;

            case 5:
        cout<<UNDERLINE<<".............. CITY GRID ...........\n\n\n"<<RESET;
                grid->printCityStreets();
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"\nPress any key to continue";
                cin.get();
                clearTerminal();
                break;

            case 6:
        cout<<UNDERLINE<<".............. CITY GRID ...........\n\n\n"<<RESET;
                grid->printCityGrid();

                cout<<"length:";
                cin>>x;
                cout<<"width:";
                cin>>y;
                cout<<"type of building:";
                cin>>a;
                pair=(grid->add_Building(x,y,a));
                cout<<pair[0].first<<"\t"<<pair[0].second<<endl;
                cout<<pair[1].first<<"\t"<<pair[1].second<<endl;
                cout<<pair[2].first<<"\t"<<pair[2].second<<endl;
                cout<<pair[3].first<<"\t"<<pair[3].second<<endl;

                clearTerminal();
                grid->printCityGrid();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"\nPress any key to continue";
                cin.get();
                clearTerminal();
                break;

            case 7:
                break;
            }
    }

}
