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
    static int eval_crit(int base_speed);
    int calc_damage(int level, int power, int attack, int defense, double stab_bonus, double type_bonus, std::string move_effect);
    std::vector<std::string> process_attack(pokemon pokemon1, pokemon pokemon2);
    double get_type_effectiveness(pokemon pokeMove, std::vector<std::string> defense_type);
};


#endif //GAME_BATTLE_H
