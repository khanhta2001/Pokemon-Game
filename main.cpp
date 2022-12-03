#include <iostream>
#include "pokemon.h"
int main() {
    std::map<std::string, int> iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> moves = {"ThunderShock", "Swift", "Thunderbolt", "Mega Punch"};
    pokemon pokemon1 = pokemon("Pikachu", 81, 35, 55, 30, 50, 40, 90, iv, ev, moves);
    std::cout << pokemon1.hp_stats() << std::endl;
    return 1;
}
