#include <string>
using namespace std;

class Mob {
    string name;
    int health;
    int attack_dmg;
    int attack_interval; //in miliseconds

public:
    // Declare Constructor
    Mob(string new_name, int new_health, int new_attack_dmg, int new_attack_interval);

    // Declare Attack and Take DMG methods
    void attack(Mob& target);
    void take_dmg(int dmg_taken);

    string get_name();
    int get_health();
    int get_attack_dmg();
    int get_attack_interval();
};