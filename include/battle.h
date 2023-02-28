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
    static int eval_crit(int base_speed);
    double calc_damage(int level, int basePower, double attack, double defense, double stab_bonus, double move_modifier, double move_effect );
    std::vector<std::string> process_attack(pokemon pokemon1, pokemon pokemon2, PokeMove move);
    double get_type_effectiveness(std::string move_type, const std::string& defender_type_one, const std::string& defender_type_two);
};


#endif //GAME_BATTLE_H
