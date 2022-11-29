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
    pokemon(std::string name, int level, int hp, int attack, int defense, int special_attack, int special_defense, int speed, std::vector<std::string> moves);
    ~pokemon();

    void calculation();

    void experience();

    void ev_caculation();

    void move_exp();

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
