#include <map>
#include <utility>
#include <vector>
#include <cmath>
#include <iostream>
#include "pokemon.h"

pokemon::pokemon(std::string name,int level, int hp, int attack, int defense, int special_attack, int special_defense, int speed, const std::map<std::string,int>& iv, const std::map<std::string,int>& ev, std::vector<std::string> moves, std::vector<std::string> types){
    pokemon::name = std::move(name);
    pokemon::level = level;
    pokemon::hp = pokemon::hp_caculation(hp, level, iv, ev);
    pokemon::attack = pokemon::stats_caculation("attack", attack, level, iv, ev);
    pokemon::defense = pokemon::stats_caculation("defense", defense, level, iv, ev);
    pokemon::special_attack = pokemon::stats_caculation("special_attack", special_attack, level, iv, ev);
    pokemon::special_defense = pokemon::stats_caculation("special_defense", special_defense, level, iv, ev);
    pokemon::speed = pokemon::stats_caculation("speed", speed, level, iv, ev);;
    pokemon::moves = std::move(moves);
    pokemon::types = std::move(types);
}
int pokemon::hp_caculation(int poke_hp, int poke_level, std::map<std::string,int> poke_iv, std::map<std::string,int> poke_ev) {
    int hp_iv = poke_iv["hp"];
    int hp_ev = poke_ev["hp"];
    int new_hp = (((poke_hp * 2 + hp_iv + (hp_ev / 4)) * poke_level) / 100) + poke_level + 10;
    return new_hp;
}

int pokemon::stats_caculation(const std::string& stat_name, int poke_stat, int poke_level, std::map<std::string,int> poke_iv, std::map<std::string,int> poke_ev){
    int stat_iv = poke_iv[stat_name];
    int stat_ev = poke_ev[stat_name];
    int new_stat = (((2 * poke_stat + stat_iv + (stat_ev /4)) * poke_level)/100) + 5;
    return new_stat;
}

pokemon::~pokemon() = default;

void pokemon::print() {
    std::cout << pokemon::name << std::endl;
    std::cout << "level:" << pokemon::level << std::endl;
    std::cout << "HP:" << pokemon::hp << std::endl;
    std::cout << "attack:" << pokemon::attack << std::endl;
    std::cout << "defense:" << pokemon::defense << std::endl;
    std::cout << "special attack:" << pokemon::special_attack << std::endl;
    std::cout << "special defense:" << pokemon::special_defense << std::endl;
    std::cout << "speed:" << pokemon::speed << std::endl;

}

