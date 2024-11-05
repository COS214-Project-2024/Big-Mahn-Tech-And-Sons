#ifndef SETTINGS_H
#define SETTINGS_H

//Text styles
#define RESET       "\033[0m"  // Reset all styles
#define UNDERLINE   "\033[4m"  // Underline text
#define FAINT       "\033[2m"  //faint text
#define ITALICS     "\033[3m"  //italiics
#define BOLD        "\033[1m"  //bold

// Text colors
#define BLACK      "\033[30m"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define YELLOW     "\033[33m"
#define BLUE       "\033[34m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"

#include <string>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Settings
{
private:
    void clear_error();
    int error_count;

public:
    Settings();
    ~Settings();
    int get_int(int min, int max, string message);
    int get_int(int min, int max);
    string get_string(int min, int max, string rmessage);
    void enter_to_continue();
    void clear_terminal();
    void sleep(int);
};

#endif /* SETTINGS_H */