#include <map>
#include <utility>
#include <vector>
#include "pokemon.h"
#include "io_functions.h"
#include "PokeMove.h"

pokemon::pokemon(const std::string& pokemon_name){
    std::map<std::string, int> iv = {{"attack",8}, {"defense", 13}, {"speed", 90}, {"special_attack", 9}, {"special_defense",9}, {"hp",7}};
    std::map<std::string, int> ev = {{"attack",0}, {"defense", 0}, {"speed", 0}, {"special_attack", 0}, {"special_defense",0}, {"hp",0}};
    io_functions stats = io_functions();
    std::map<std::string,std::map<std::string,std::string>> poke_stats = stats.stats_info("poke_stats");
    std::vector<std::string> poke_moves = stats.moves_info()[pokemon_name];
    std::map<std::string,std::string> poke = poke_stats[pokemon_name];
    auto HP = std::stoi(poke["HP"]);
    auto Level = std::stoi(poke["Level"]);
    auto Attack = std::stoi(poke["Attack"]);
    auto Defense = std::stoi(poke["Defense"]);
    auto Special_Attack = std::stoi(poke["Special Attack"]);
    auto Special_Defense = std::stoi(poke["Special Defense"]);
    auto Speed = std::stoi(poke["Speed"]);
    pokemon::name = poke["name"];
    pokemon::hp = pokemon::hpCaculation(HP, Level, iv, ev);
    pokemon::attack = pokemon::statsCaculation("attack", Attack, Level, iv, ev);
    pokemon::defense = pokemon::statsCaculation("defense", Defense, Level, iv, ev);
    pokemon::special_attack = pokemon::statsCaculation("special_attack", Special_Attack, Level, iv, ev);
    pokemon::special_defense = pokemon::statsCaculation("special_defense", Special_Defense, Level, iv, ev);
    pokemon::speed = pokemon::statsCaculation("speed", Speed, Level, iv, ev);;
    pokemon::moves = {}; // poke_moves["Moves"]
    pokemon::type1 = poke["Type 1"];
    pokemon::type2 = poke["Type 2"];
    pokemon::status = "None";

    for (int i = 0; i < poke_moves.size(); i++){
        PokeMove move = PokeMove(poke_moves[i]);
        pokemon::moves.emplace_back(move);
    }
}

pokemon::pokemon(){

}


pokemon::~pokemon() = default;


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

void pokemon::change_stats(const std::string& stat_name, int new_stat_info){
    if (stat_name == "HP"){
        pokemon::hp = new_stat_info;
    }
    if (stat_name == "Speed"){
        pokemon::speed = new_stat_info;
    }
}

std::string pokemon::poke_status(){
    return pokemon::status;
}

void pokemon::change_status(std::string new_status){
    pokemon::status = std::move(new_status);
}

std::string pokemon::get_name() {
    return pokemon::name;
}

int pokemon::get_stats(const std::string& stat_name) {
    std::map<std::string, int> stats = {{"Level",           pokemon::level},
                                        {"HP",              pokemon::hp},
                                        {"Attack",          pokemon::attack},
                                        {"Defense",         pokemon::defense},
                                        {"Special Attack",  pokemon::special_attack},
                                        {"Special Defense", pokemon::special_defense},
                                        {"Speed",           pokemon::speed}};
    return stats[stat_name];
}

std::string pokemon::get_info(const std::string& stat_name) {
    std::map<std::string, std::string> stats = {{"Name",           pokemon::name},
                                        {"Type 1",              pokemon::type1},
                                        {"Type 2",          pokemon::type2},
                                        {"Status",         pokemon::status}};
    return stats[stat_name];
}

PokeMove pokemon::get_moves() {
    std::vector<PokeMove> stats = std::move(pokemon::moves);
    int x = rand() % (stats.size());
    return stats[x];
}




