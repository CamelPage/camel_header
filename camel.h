#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

void echo(std::string message) {

    std::cout << message;

}

void print(std::string message) {

    std::cout << message;

}


/// @brief The listen_event_key_press C++ function captures a key press event using the choice command. It constructs a command string with user-defined default key and time parameters, executes the command using system(), and reads the output from a temporary file named "temp.tmp." The content of the file is returned as a string. Note the need for consistent filename usage and potential inclusion of error handling.
/// @param default_key 1 Character | Acharacter representing the default choice if no input is received within the specified time.
/// @param time Number. Max 99 | A number representing the time in seconds during which the user can make a choice.
/// @return The Key Chosen By The User Or The 'Default_key'. 
string listen_event_key_press(const char default_key[1], const char time[2]) {
    char command[1024];

    strcpy(command, "choice /c ");
    strcat(command, "qwertyuiopasdfghjklzxcvbnm1234567890");
    strcat(command, " /n /t ");
    strcat(command, time);
    strcat(command, " /D ");
    strcat(command, default_key);
    strcat(command, " > temp.tmp");

    system(command);

    ifstream file("temp.tmp");

    if (file.is_open()) {
        string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));

        file.close();
        // system("del temp.txt");
        return content;
    }

    return "error";
}

/// @param input_key string | Inputed Key 
/// @param wanted_key string | Whar Key Is Wanted
/// @return True/False
int event_key(string input_key, string wanted_key) {

    wanted_key+="\n";

    if(input_key==wanted_key) {

        return 1;
    }

    return 0;
}

/// @brief Deletes temp.tpm
void stop_listening() {

    system("del temp.tmp");

}

/// @brief Executes Cmd / Batch Commands
/// @param command char* | Execute Command
void batch(const char* command) {

    system(command);

}