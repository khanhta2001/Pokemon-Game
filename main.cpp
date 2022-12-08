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

void all_pokemon(){
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
    std::vector<std::string> pokemon3_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon3_types = {"Electric", ""};
    pokemon pokemon3 = pokemon("Mewtwo", 81, 106,110,90,154,90,130, pokemon3_iv, pokemon3_ev, pokemon3_moves, pokemon3_types);

    std::map<std::string, int> pokemon4_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon4_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon4_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon4_types = {"Electric", ""};
    pokemon pokemon4 = pokemon("Blastoise", 81, 79,83,100,85,105,78, pokemon4_iv,pokemon4_ev, pokemon4_moves, pokemon4_types);

    std::map<std::string, int> pokemon5_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon5_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon5_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon5_types = {"Electric", ""};
    pokemon pokemon5 = pokemon("Bulbasaur", 81,45,49,49,65,65,45, pokemon5_iv, pokemon5_ev,pokemon5_moves, pokemon5_types);

    std::map<std::string, int> pokemon6_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon6_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon6_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon6_types = {"Electric", ""};
    pokemon pokemon6 = pokemon("Charmander", 81, 39,52,43,60,50,65, pokemon6_iv, pokemon6_ev, pokemon6_moves, pokemon6_types);

    std::map<std::string, int> pokemon7_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon7_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon7_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon7_types = {"Electric", ""};
    pokemon pokemon7 = pokemon("Shroomish", 81, 60,40,60,40,60,35, pokemon7_iv, pokemon7_ev, pokemon7_moves, pokemon7_types);


    std::map<std::string, int> pokemon8_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon8_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon8_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon8_types = {"Electric", ""};
    pokemon pokemon8 = pokemon("Snorlax", 81, 160,110,65,65,110,30, pokemon8_iv, pokemon8_ev, pokemon8_moves, pokemon8_types);

    std::map<std::string, int> pokemon9_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon9_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon9_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon9_types = {"Electric", ""};
    pokemon pokemon9 = pokemon("Moltres", 81, 90, 100,90,125,85,90, pokemon9_iv, pokemon9_ev, pokemon9_moves, pokemon9_types);

    std::map<std::string, int> pokemon10_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon10_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon10_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon10_types = {"Electric", ""};
    pokemon pokemon10 = pokemon("quagsire", 81, 95, 85,85,65,65,35, pokemon10_iv, pokemon10_ev, pokemon10_moves, pokemon10_types);

    std::map<std::string, int> pokemon11_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon11_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon11_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon11_types = {"Electric", ""};
    pokemon pokemon11 = pokemon("Lunatone", 81, 70,55,65,95,85,70, pokemon11_iv, pokemon11_ev, pokemon11_moves, pokemon11_types);

    std::map<std::string, int> pokemon12_iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> pokemon12_ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    std::vector<std::string> pokemon12_moves = {"Pound", "Mega Punch", "Psychic"};
    std::vector<std::string> pokemon12_types = {"Electric", ""};
    pokemon pokemon12 = pokemon("Gabite", 81, 68,90,65,50,55,82, pokemon12_iv, pokemon12_ev, pokemon12_moves, pokemon12_types);
}
