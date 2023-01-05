//
// Created by ankha on 1/4/2023.
//

#ifndef GAME_BATTLE_H
#define GAME_BATTLE_H


#include "pokemon.h"
#include "initialize_team.h"

class battle {

public:
    battle();
    ~battle();
    void simulate_battle(initialize_team team1, initialize_team team2);

private:
    std::string pick_poke(initialize_team team);
    initialize_team team1;
    initialize_team team2;

};


#endif //GAME_BATTLE_H
