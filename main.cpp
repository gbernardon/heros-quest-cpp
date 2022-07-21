#include <iostream>
#include "mob.cpp"
#include <string>
#include <windows.h>
#include <thread>
using namespace std;

// Creating mobs
Mob player("Hero", 40, 2, 1);
Mob orc("Orc", 7, 1, 1500);
Mob dragon("Dragon", 20, 3, 2000);

bool debug_mode;

void game_start(){
    if (debug_mode == true){
        cout << "Debug Mode Activated. Game starting...\n\n";
    }
    else{
        string start;
        cout << "Welcome to Hero's Quest!\n\n";
        Sleep(1000);
        system("pause"); // "Press any key to continue..."
        cout << "\n\nAs a Hero walking through the forest, you come across an Orc and a Dragon...\n";
        Sleep(3000);
        cout << "After spotting you, they both start running towards your direction, preparing to attack.\n";
        Sleep(3500);
        cout << "You will have to be fast to beat both of them... The Dragon has 20hp and deals 3dmg every 2 seconds.\n";
        Sleep(4500);
        cout << "The Orc has 7hp and deals 1dmg every second.\n";
        Sleep(3000);
        do {
            cout << "\nAre you ready to fight them? Type 'yes' to start: ";
            cin >> start;
            if (start != "yes"){
                cout << "Invalid command... let's try again.";
            } 
        } while(start != "yes");
        cout << "\nType 'o' to attack the Orc, or 'd' to attach the dragon. To confirm your move, press the ENTER key...\n";
        Sleep(1500);
        cout << "\nStarting in 3...";
        Sleep(1000);
        cout << " 2...";
        Sleep(1000);
        cout << " 1...";
        Sleep(1000);
        cout << " GO!\n\n";
    }
}

void orcs_function(){
    while (orc.get_health() > 0){
       orc.attack(player);
        Sleep(orc.get_attack_interval());
    }
    cout << "\nThe Orc has died!\n";
}

void dragons_function(){
    while (dragon.get_health() > 0){
        dragon.attack(player);
        Sleep(dragon.get_attack_interval());
    }
    cout << "\nThe dragon has died!\n";
}

int players_function(){
        char player_action;
        while (true){
            cin >> player_action;
            cout << "\n";
            if (player_action == 'o'){ // ORC
                player.attack(orc);
            }
            else if (player_action == 'd'){ // DRAGON
                player.attack(dragon);
            }
            else{
                cout << "Invalid command, try again...\n";
            }
        }
}

int general_condition_check(){
    while (true){
        if (dragon.get_health() <= 0 && orc.get_health() <= 0){
            Sleep(500);
            cout << "\nThe Hero has killed both enemies YAY!\nYou won!\n";
            return 0;
        }
        if (player.get_health() <= 0) {
            Sleep(500);
            cout << "\nOh no :(\nThe Hero has died... You lost!\n";
            return 0;
        }
    }
}

int main() {
    debug_mode = false;

    thread start(game_start); // Start introduction
    start.join(); // wait for 'yes' from user before continuing
    
    thread player(players_function); // Start checking user's input
    thread orc(orcs_function); // Start Orc's attacks
    Sleep(13); // Wait 13ms so attack outputs don't overwrite each other on the console
    thread dragon(dragons_function); // Start Dragon's attacks

    thread check(general_condition_check); // Starts checking if enemies or hero died
    check.join(); // Wait until enemies die, or player loses
    
    return 0;
}