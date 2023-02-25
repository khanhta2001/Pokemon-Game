#ifndef GAME_POKEMON_H
#define GAME_POKEMON_H
#include <string>
#include <map>
#include <vector>
#include "PokeMove.h"

class pokemon {

public:
    pokemon(const std::string& pokemon_name);
    pokemon();
    ~pokemon();

    int hpCaculation(int poke_hp, int poke_level, std::map<std::string,int> poke_iv, std::map<std::string,int> poke_ev);
    int statsCaculation(const std::string& stat_name, int poke_stat, int poke_level, std::map<std::string,int> poke_iv, std::map<std::string,int> poke_ev);
    void change_stats(const std::string& stat_name, int new_stat_info);
    std::string get_name();
    int get_stats(const std::string& stat_name);
    std::string get_info(const std::string& stat_name);
    PokeMove get_moves();
    std::string poke_status();
    void change_status(std::string status);

private:
    std::string name;
    int level{};
    int hp{};
    int attack{};
    int defense{};
    int special_attack{};
    int special_defense{};
    int speed{};
    std::string status;
    std::vector<PokeMove> moves;
    std::string type1;
    std::string type2;
};


#endif //GAME_POKEMON_H
