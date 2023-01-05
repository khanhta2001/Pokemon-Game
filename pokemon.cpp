#include <map>
#include <utility>
#include <vector>
#include <cmath>
#include <iostream>
#include "pokemon.h"

pokemon::pokemon(std::string name,int level, int hp, int attack, int defense, int special_attack, int special_defense, int speed, const std::map<std::string,int>& iv, const std::map<std::string,int>& ev, std::vector<std::string> moves, std::vector<std::string> types){
    pokemon::name = std::move(name);
    pokemon::level = level;
    pokemon::hp = pokemon::hpCaculation(hp, level, iv, ev);
    pokemon::attack = pokemon::statsCaculation("attack", attack, level, iv, ev);
    pokemon::defense = pokemon::statsCaculation("defense", defense, level, iv, ev);
    pokemon::special_attack = pokemon::statsCaculation("special_attack", special_attack, level, iv, ev);
    pokemon::special_defense = pokemon::statsCaculation("special_defense", special_defense, level, iv, ev);
    pokemon::speed = pokemon::statsCaculation("speed", speed, level, iv, ev);;
    pokemon::moves = std::move(moves);
    pokemon::types = std::move(types);
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

pokemon::~pokemon() = default;

void pokemon::print_name () {
    std::cout << pokemon::name << std::endl;
}

std::string pokemon::get_name() {
    return pokemon::name;
}

std::map<std::string,int> pokemon::get_stats() {
    std::map<std::string,int> stats = {{"Level",pokemon::level},{"HP",pokemon::hp},{"Attack",pokemon::attack},{"Defense",pokemon::defense},{"Special Attack",pokemon::special_attack},{"Special Defense",pokemon::special_defense},{"Speed",pokemon::speed}};
    return stats;
}



