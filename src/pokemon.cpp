#include <map>
#include <utility>
#include <vector>
#include <iostream>
#include "pokemon.h"
#include "io_functions.h"

pokemon::pokemon(const std::string& pokemon_name){
    std::map<std::string, int> iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    io_functions stats = io_functions();
    std::map<std::string,std::map<std::string,std::string>> poke_stats = stats.stats_info("poke_stats");
    std::map<std::string, std::vector<std::string>> poke_moves = stats.moves_info();
    std::map<std::string,std::string> poke = poke_stats[pokemon_name];
    pokemon::name = poke["name"];
    pokemon::hp = pokemon::hpCaculation(stoi(poke["HP"]), stoi(poke["Level"]), iv, ev);
    pokemon::attack = pokemon::statsCaculation("attack", stoi(poke["Attack"]), stoi(poke["Level"]), iv, ev);
    pokemon::defense = pokemon::statsCaculation("defense", stoi(poke["Defense"]), stoi(poke["Level"]), iv, ev);
    pokemon::special_attack = pokemon::statsCaculation("special_attack", stoi(poke["Special Attack"]), stoi(poke["Level"]), iv, ev);
    pokemon::special_defense = pokemon::statsCaculation("special_defense", stoi(poke["Special Defense"]), stoi(poke["Level"]), iv, ev);
    pokemon::speed = pokemon::statsCaculation("speed", stoi(poke["Speed"]), stoi(poke["Level"]), iv, ev);;
    pokemon::moves = std::move(poke_moves["Moves"]);
    pokemon::type1 = poke["Type 1"];
    pokemon::type2 = poke["Type 2"];
    pokemon::status = "None";
}
int pokemon::hpCaculation(int poke_hp, int poke_level, std::map<std::string,int> poke_iv, std::map<std::string,int> poke_ev) {
    int hp_iv = poke_iv["hp"];
    int hp_ev = poke_ev["hp"];
    int new_hp = (((poke_hp * 2 + hp_iv + (hp_ev / 4)) * poke_level) / 100) + poke_level + 10;
    return new_hp;
}

int pokemon::statsCaculation(const std::string& stat_name, int poke_stat, int poke_level, std::map<std::string,int> poke_iv, std::map<std::string,int> poke_ev){
    int stat_iv = poke_iv[stat_name];
    int stat_ev = poke_ev[stat_name];
    int new_stat = (((2 * poke_stat + stat_iv + (stat_ev /4)) * poke_level)/100) + 5;
    return new_stat;
}

std::string pokemon::poke_status(){
    return pokemon::status;
}

void pokemon::change_status(std::string new_status){
    pokemon::status = std::move(new_status);
}

pokemon::~pokemon() = default;

void pokemon::print_name() {
    std::cout << pokemon::name << std::endl;
}

std::string pokemon::get_name() {
    return pokemon::name;
}

std::map<std::string,int> pokemon::get_stats() {
    std::map<std::string, int> stats = {{"Level",           pokemon::level},
                                        {"HP",              pokemon::hp},
                                        {"Attack",          pokemon::attack},
                                        {"Defense",         pokemon::defense},
                                        {"Special Attack",  pokemon::special_attack},
                                        {"Special Defense", pokemon::special_defense},
                                        {"Speed",           pokemon::speed}};
    return stats;
}

std::vector<std::string> pokemon::get_moves() {
    std::vector<std::string> stats = std::move(pokemon::moves);
    return stats;
}

void pokemon::print_moves() {
    for (int i = 0; i < pokemon::moves.size();i++){
        std::cout << pokemon::moves[i] << std::endl;
    }
}

void pokemon::print_stats() {
    std::cout << "Pokemon name: " << pokemon::name << std::endl;
    std::cout << "Level: " << pokemon::level << std::endl;
    std::cout << "HP: " << pokemon::hp << std::endl;
    std::cout << "Attack: " << pokemon::attack << std::endl;
    std::cout << "Defense: " << pokemon::defense << std::endl;
    std::cout << "Special Attack: " << pokemon::special_attack << std::endl;
    std::cout << "Special Defense: " << pokemon::special_defense << std::endl;
    std::cout << "Speed: " << pokemon::speed << std::endl;
}





