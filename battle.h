//
// Created by An Khanh Tran on 12/6/22.
//

#ifndef GAME_BATTLE_H
#define GAME_BATTLE_H
#include "pokemon.h"


class battle {
public:
    battle(pokemon* pokemon1, pokemon* pokemon2);
    ~battle();

    void simulate_battle();
private:
    pokemon* pokemon1;
    pokemon* pokemon2;
};


#endif //GAME_BATTLE_H
