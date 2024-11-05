#include "Settings.h"

Settings::Settings()
{
    error_count=0;
}

Settings::~Settings()
{
    //nothing
}

int Settings::get_int(int min, int max, string message)
{
    int value;
    while (true) 
    {
        cout<<message;error_count+=1;
        cin>>value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout<<FAINT<<BRIGHT_YELLOW<<"Invalid input. Please enter an integer!\n"<<RESET;error_count+=1;
        } 
        else
        {
            cin.ignore(1000, '\n');
            if(!(value>=min && value<=max))
            {
                if(value<min){cout<<FAINT<<BRIGHT_YELLOW<<"must be greater than "<<min<<"!\n"<<RESET;error_count+=1;}
                if(value>max){cout<<FAINT<<BRIGHT_YELLOW<<"must be less than "<<max<<"!\n"<<RESET;error_count+=1;}
            }
            if(value>=min && value<=max)
            {
                clear_error();
                cout<<message<<value<<endl;
                return value;
            }
        }
    }
}

int Settings::get_int(int min, int max)
{
    int value;
    while (true) 
    {
        error_count+=1;
        cin>>value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout<<FAINT<<BRIGHT_YELLOW<<"Invalid input. Please enter an integer!\n"<<RESET;error_count+=1;
        } 
        else
        {
            cin.ignore(1000, '\n');
            if(!(value>=min && value<=max))
            {
                if(value<min){cout<<FAINT<<BRIGHT_YELLOW<<"must be greater than "<<min<<"!\n"<<RESET;error_count+=1;}
                if(value>max){cout<<FAINT<<BRIGHT_YELLOW<<"must be less than "<<max<<"!\n"<<RESET;error_count+=1;}
            }
            if(value>=min && value<=max)
            {
                clear_error();
                cout<<value<<endl;
                return value;
            }
        }
    }
}

string Settings::get_string(int min, int max, string message)
{
    string input;
    bool state;
    do
    {
        //if(state==true){error_count+=1;}
        state=false;
        cout<<message;error_count+=1;
        cin>>input;
        for(int i=0; i<input.length(); i++)
        {
            int code = static_cast<int>(input[i]);
            if( !((code>=48 && code<=57) || (code>=65 && code<=90) || (code>=97 && code<=122)))
            {
                cout<<FAINT<<BRIGHT_YELLOW<<"Invalid string. Do not add special characters!\n"<<RESET;error_count+=1;
                state=true;
                break;
            }
        }
        if(!(input.length()>=min && input.length()<=max))
        {
            if(input.length()<min)
            {cout<<FAINT<<BRIGHT_YELLOW<<"String too short. Must be greater than "<<min<<"!\n"<<RESET;error_count+=1;}
            if(input.length()>max)
            {cout<<FAINT<<BRIGHT_YELLOW<<"String to long. Must be less than "<<max<<"!\n"<<RESET;error_count+=1;}
            state=true;
        }
        if(state==false)
        {
            clear_error();
            cout<<message<<input<<endl;
            return input;}
    } 
    while (state = true);

    clear_error();
    cout<<message<<input<<endl;
    return input;
}

void Settings::clear_error()
{
    for(int i= 0; i< error_count; i++)
    {
        std::cout << "\033[2K";   // Clear the current line
        std::cout << "\033[1A";   // Move cursor up by one line
    }

    std::cout << "\033[2K\r";
    error_count=0;
}

void Settings::enter_to_continue()
{
    cout<<"\nPress any key to continue";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void Settings::clear_terminal()
{
    #ifdef _WIN32
    system("cls");  // Clear the screen on Windows
    #else
    system("clear");  // Clear the screen on Unix/Linux/macOS
    #endif
}

void Settings::sleep(int duration)
{
    std::this_thread::sleep_for(std::chrono::seconds(duration));
}