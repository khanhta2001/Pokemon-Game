//
// Created by An Khanh Tran on 11/24/22.
//

#include "move.h"

#include <utility>

move::move(std::string name, std::string poketype, std::string power, std::string pp, std::string accuracy, std::string priority, std::string effect, std::string effect_chance){
    move::name = std::move(name);
    move::poketype = std::move(poketype);
    move::power = std::stoi(power);
    move::powerPoint = std::stoi(pp);
    move::accuracy = std::stoi(accuracy);
    move::priority = std::move(priority);
    move::effect = std::stoi(effect);
    move::effect_chance = std::stoi(effect_chance);
}


move::~move(){

}

bool move::eval_effect_chance() {
    if (move::effect == 0){
        return false;
    }
    else if (move::effect_chance == 0){
        return true;
    }
    else{
        if (move::effect_chance < rand() % 100 + 1){
            return false;
        }
        else{
            return true;
        }
    }
}
