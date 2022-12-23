#include <iostream>
#include "pokemon.h"
#include "initialize_team.h"
int main() {
    std::map<std::string, int> pokemon1_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon1_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon1_moves = {"ThunderShock", "Swift", "Thunderbolt", "Mega Punch"};
    std::vector<std::string> pokemon1_types = {"Electric", ""};
    pokemon pokemon1 = pokemon("Pikachu", 81, 35, 55, 30, 50, 40, 90, pokemon1_iv, pokemon1_ev, pokemon1_moves, pokemon1_types);

    std::map<std::string, int> pokemon2_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon2_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon2_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon2_types = {"Electric", ""};
    pokemon pokemon2 = pokemon("Mew", 81,100,100,100,100,100,100, pokemon2_iv, pokemon2_ev, pokemon2_moves,pokemon2_types);

    std::map<std::string, int> pokemon3_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon3_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon3_moves = {"Confusion", "Psychic", "Swift"};
    std::vector<std::string> pokemon3_types = {"Psychic", ""};
    pokemon pokemon3 = pokemon("Mewtwo", 81, 106,110,90,154,90,130, pokemon3_iv, pokemon3_ev, pokemon3_moves, pokemon3_types);

    std::map<std::string, int> pokemon4_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon4_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon4_moves = {"Water Gun", "Bite", "Hydro Pump", "Ice Beam"};
    std::vector<std::string> pokemon4_types = {"Water", ""};
    pokemon pokemon4 = pokemon("Blastoise", 81, 79,83,100,85,105,78, pokemon4_iv,pokemon4_ev, pokemon4_moves, pokemon4_types);

    std::map<std::string, int> pokemon5_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon5_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon5_moves = {"Tackle", "Vine Whip", "Razor Leaf", "Solar Beam"};
    std::vector<std::string> pokemon5_types = {"Grass", "Poison"};
    pokemon pokemon5 = pokemon("Bulbasaur", 81,45,49,49,65,65,45, pokemon5_iv, pokemon5_ev,pokemon5_moves, pokemon5_types);

    std::map<std::string, int> pokemon6_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon6_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon6_moves = {"Scratch", "Ember", "Rage", "Slash", "Flamethrower", "Fire Spin"};
    std::vector<std::string> pokemon6_types = {"Fire", ""};
    pokemon pokemon6 = pokemon("Charmander", 81, 39,52,43,60,50,65, pokemon6_iv, pokemon6_ev, pokemon6_moves, pokemon6_types);

    initialize_team team1 = initialize_team();
    team1.team(&pokemon1);
    team1.team(&pokemon2);
    team1.team(&pokemon3);
    team1.team(&pokemon4);
    team1.team(&pokemon5);
    team1.team(&pokemon6);

    initialize_team team2 = initialize_team();
    team2.team(&pokemon1);
    team2.team(&pokemon2);
    team2.team(&pokemon3);
    team2.team(&pokemon4);
    team2.team(&pokemon5);
    team2.team(&pokemon6);

    team1.print();

    return 1;
}

void all_pokemon(){
}
