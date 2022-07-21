#include "mob.hpp"
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

// Define Constructor
Mob::Mob(string new_name, int new_health, int new_attack_dmg, int new_attack_interval){
    name = new_name;
    health = new_health;
    attack_dmg = new_attack_dmg;
    attack_interval = new_attack_interval;
}

// Define Attack function
void Mob::attack(Mob& target){ 
        target.take_dmg(attack_dmg);
        cout << "\nThe " << get_name() << " attacked the " << target.get_name() << ", who lost " << get_attack_dmg() << "hp ";
        if(get_attack_dmg() == 1){
            cout << "point...\n";
        }else{cout<<"points...\n";}
        cout << target.get_name() << "'s current health: " << target.get_health() << "\n";
}

// Define Take damage function
void Mob::take_dmg(int dmg_taken){ 
    health = health - dmg_taken;
}

// Define GETTERS
string Mob::get_name(){return name;}
int Mob::get_health(){return health;}
int Mob::get_attack_dmg(){return attack_dmg;}
int Mob::get_attack_interval(){return attack_interval;}