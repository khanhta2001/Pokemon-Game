//
// Created by An Khanh Tran on 11/25/22.
//

#ifndef GAME_POKEMON_H
#define GAME_POKEMON_H
#include <string>
#include <map>
#include <vector>

class pokemon {
public:
    pokemon(std::string name, int level, int hp, int attack, int defense, int special_attack, int special_defense, int speed, const std::map<std::string,int>& iv, const std::map<std::string,int>& ev, std::vector<std::string> moves);
    ~pokemon();

    int hp_caculation(int poke_hp, int poke_level, std::map<std::string,int> poke_iv, std::map<std::string,int> poke_ev);
    int stats_caculation(const std::string& stat_name, int poke_stat, int poke_level, std::map<std::string,int> poke_iv, std::map<std::string,int> poke_ev);
    int hp_stats();
    void print();

private:
    std::string name;
    int level;
    int hp;
    int attack;
    int defense;
    int special_attack;
    int special_defense;
    int speed;
    std::vector<std::string> moves;
};


#endif //GAME_POKEMON_H
