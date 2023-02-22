#ifndef GAME_POKEMON_H
#define GAME_POKEMON_H
#include <string>
#include <map>
#include <vector>

class pokemon {

public:
    pokemon(const std::string& pokemon_name);
    ~pokemon();

    int hpCaculation(int poke_hp, int poke_level, std::map<std::string,int> poke_iv, std::map<std::string,int> poke_ev);
    int statsCaculation(const std::string& stat_name, int poke_stat, int poke_level, std::map<std::string,int> poke_iv, std::map<std::string,int> poke_ev);
    void print_name();
    std::string get_name();
    void print_stats();
    void print_moves();
    std::map<std::string,int> get_stats();
    std::vector<std::string> get_moves();
    std::string poke_status();
    void change_status(std::string status);

private:
    std::string name;
    int level;
    int hp;
    int attack;
    int defense;
    int special_attack;
    int special_defense;
    int speed;
    std::string status;
    std::vector<std::string> moves;
    std::string type1;
    std::string type2;
};


#endif //GAME_POKEMON_H
