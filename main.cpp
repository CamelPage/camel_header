#include "camel.h"
#include <iostream>
#include <fstream>
#include <algorithm>

int main() {
    string sent;
    bool quit = true;

    while (quit) {
        string key = listen_event_key_press("0", "3");
        if(event_key(key, "9")) {
            sent += " ";
            continue;
        }
        if (!event_key(key, "0")) {
            sent += key;
        } else {
            quit = false;
        }
    }

    sent.erase(remove(sent.begin(), sent.end(), '\n'), sent.end());

    ofstream result("result.txt");
    result << sent;

    echo("Final Result:" + sent);


    stop_listening();
    return 0;
}
