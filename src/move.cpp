#include <map>
#include <utility>
#include <vector>
#include <cmath>
#include <iostream>
#include "pokemon.h"
#include "move.h"

PokeMove::PokeMove(std::string name, std::string poketype, int power, int pp, int accuracy, std::string priority, int effect, int effect_chance) {
    PokeMove::name = std::move(name);
    PokeMove::poketype = std::move(poketype);
    PokeMove::power = power;
    PokeMove::pp = pp;
    PokeMove::accuracy = accuracy;
    PokeMove::priority = std::move(priority);
    PokeMove::effect = std::move(effect);
    PokeMove::effect_chance = effect_chance
}

PokeMove::~PokeMove() {

}

std::string PokeMove::move_type() {
    return PokeMove::poketype;
}

std::string PokeMove::move_definition() {
    std::string def = "Name: " + PokeMove::name + ", pokeType: " + PokeMove::poketype;
    return def;
}

int PokeMove::eval_effect_chance() {
    if (PokeMove::effect == 0){
        return 0;
    }
    else if (PokeMove::effect_chance == 0){
        return 0;
    }
    else{
        if ((rand()%100 + 1) > PokeMove::effect_chance){
            return 0;
        }
        else{
            return 1;
        }
    }
}
