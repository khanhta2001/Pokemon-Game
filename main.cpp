#include <iostream>
#include "pokemon.h"
#include "initialize_team.h"
int main() {
    std::map<std::string, int> iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> moves = {"ThunderShock", "Swift", "Thunderbolt", "Mega Punch"};
    std::vector<std::string> types = {"Electric", ""};
    pokemon pokemon1 = pokemon("Pikachu", 81, 35, 55, 30, 50, 40, 90, iv, ev, moves, types);
    initialize_team team1 = initialize_team();
    team1.team(&pokemon1);
    team1.print();

    return 1;
}
