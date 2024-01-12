#include "camel.h"
#include <iostream>
#include <fstream>
#include <algorithm>

int main() {
    string sent;
    bool quit = true;

    while (quit) {
        string a = listen_event_key_press("0", "3");
        if(event_key(a, "9")) {
            sent += " ";
            continue;
        }
        if (!event_key(a, "0")) {
            sent += a;
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
