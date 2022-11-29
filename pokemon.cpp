//
// Created by An Khanh Tran on 11/25/22.
//

#include <map>
#include <utility>
#include <vector>
#include "pokemon.h"

pokemon::pokemon(std::string name, int level, int hp, int attack, int defense, int special_attack, int special_defense, int speed, std::vector<std::string> moves){
    pokemon::name = std::move(name);
    pokemon::level = level;
    pokemon::hp = hp;
    pokemon::attack = attack;
    pokemon::defense = special_attack;
    pokemon::special_defense = special_defense;
    pokemon::special_attack = special_attack;
    pokemon::speed = speed;
    pokemon::moves = std::move(moves);
}

pokemon::~pokemon() {

}

pokemon::calculation() {

}

pokemon::move_exp() {

}

void pokemon::ev_caculation() {

}

