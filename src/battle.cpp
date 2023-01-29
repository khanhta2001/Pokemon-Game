#include <iostream>
#include "battle.h"
#include <random>

battle::battle() = default;

battle::~battle() = default;

std::string battle::pick_poke(initialize_team team) {
    if (!team.empty()){
        std::cout << "Pick one of your pokemon below " << std::endl;
        team.print();
        std::string pick_poke;
        std::cin >> pick_poke;
        bool check_poke = team.check_poke(pick_poke);
        while (!check_poke){
            std::cout << "The pokemon you picked is not in the team! Please choose another pokemon" << std::endl;
            std::cin >> pick_poke;
            check_poke = team.check_poke(pick_poke);
        }
        std::cout << "You picked " << pick_poke << std::endl;
        return pick_poke;
    }
    std::cout << "You ran out of pokemon! You lost." << std::endl;
}


int battle::eval_crit(int base_speed) {
    int random = (rand()%512)+1;
    return random < base_speed;
}

int battle::calc_damage(int level, int power, int attack, int defense, double stab_bonus, double type_bonus,
                        std::string move_effect) {
    if (move_effect == "Sleep"){
        return 0;
    }
    double random_modifier = (rand()%100 + 85) / 100;
    int damage = ((2 * level / 5 + 2) * power * attack / defense / 50 + 2) * random_modifier * stab_bonus * type_bonus);
    return damage;
}

std::vector<std::string> battle::process_attack(pokemon attacker, pokemon defender) {
    std::cout << attacker.get_name() << " uses " << "!" << std::endl;
    return std::vector<std::string>();
}

double battle::get_type_effectiveness(pokemon pokeMove, std::vector<std::string> defense_type) {
    double result = 1;
    std::map<std::string, std::map<std::string, double>> type = {};
    type.insert("Normal", {{"Normal", 1}, {"Fire", 1}, {"Water", 1}, {"Eletric", 1}, {"Grass", 1}, {"Ice", 1}, {"Fighting", 1}, {"Poison", 1}, {"Ground", 1}, {"Fly", 1}, {"Psychic", 1}, {"Bug", 1}, {"Rock", 0.5}, {"Ghost", 1}, {"Dragon", 1}, {"Dark", 1}, {"Steel", 0.5}});
    std::map<std::string,double> data = {};
    for (int i = 0; i < defense_type.size(); i++){
        result = result * data[defense_type[i]];
    }
    return result;
}


void battle::simulate_battle(initialize_team team1, initialize_team team2) {
    int round = 1;
    std::string team1_poke;
    std::string team2_poke;
    std::string dead;
    while (true){
        std::cout << "Round " << round << std::endl;
        if (round == 1){
            std::cout << "Team 1! Pick your Pokemon" << std::endl;
            team1_poke = battle::pick_poke(team1);
            std::cout << "Team 2! Pick your pokemon" << std::endl;
            team2_poke = battle::pick_poke(team2);
        }
        else{
            if (dead == "team 1"){
                std::cout << "Team 1! Pick your Pokemon" << std::endl;
                team1_poke = battle::pick_poke(team1);
            }
            else{
                std::cout << "Team 2! Pick your pokemon" << std::endl;
                team2_poke = battle::pick_poke(team2);
            }
        }
        pokemon poke1 = team1.poke(team1_poke);
        pokemon poke2 = team2.poke(team2_poke);
        std::map<std::string,int> poke1_stats = poke1.get_stats();
        std::map<std::string,int> poke2_stats = poke2.get_stats();
        if (poke1_stats["hp"] >0 and poke1_stats["hp"] > 0){

        }

        break;
    }
}