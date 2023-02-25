#include <iostream>
#include "battle.h"
#include "io_functions.h"

battle::battle() = default;

battle::~battle() = default;

std::string battle::pick_poke(initialize_team team) {
    if (!team.empty()){
        std::cout << "Pick one of your pokemon below " << std::endl;
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

    return "bruh";
}

double type_modifier(std::string type1, std::string type2){
    io_functions stats = io_functions();
    std::map<std::string,std::map<std::string,std::string>> move_stats = stats.stats_info("type_damage");
    double modifier = std::stoi(move_stats[type1][type2]);
    return modifier;
}


int battle::eval_crit(int base_speed) {
    int random = (rand()%512)+1;
    return random < base_speed;
}

double battle::get_type_effectiveness(std::string move_type, const std::string& defender_type_one, const std::string& defender_type_two) {
    double result = 1;
    io_functions stats = io_functions();
    std::map<std::string,std::map<std::string,std::string>> move_stats = stats.stats_info("type_damage");
    result *= std::stoi(move_stats[move_type][defender_type_one]);
    if (!defender_type_two.empty()){
        result *= std::stoi(move_stats[move_type][defender_type_two]);
    }
    return result;
}

double battle::calc_damage(int level, int basePower, double attack, double defense, double stab_bonus, double move_modifier, double move_effect ) {
    double random_modifier = (rand()%100 + 85) / 100;
    double damage = ((((((2 * level) / 5) + 2) * basePower * attack) / defense) / 50) + 2;
    damage *= random_modifier;
    damage *= move_modifier;
    damage *= stab_bonus;
    damage *= move_effect;
    return damage;
}

std::vector<std::string> battle::process_attack(pokemon attacker, pokemon defender, PokeMove move) {
    std::string move_attacker = attacker.get_name() + " uses " + move.move_info("Name") + "!";
    std::vector<std::string> output = {move_attacker};
    if (move.move_stats("Accuracy") != -1){
        if ((rand()%100 +1) >= move.move_stats("Accuracy")){
            output.emplace_back("It missed!");
            return output;
        }
    }
    int level = attacker.get_stats("Level");
    if (eval_crit(attacker.get_stats("Speed"))){
        level *= 2;
        output.emplace_back("Critical hit!");
    }
    double attacker_attack = 0;
    double defender_defense = 0;
    double stab_bonus = 0;
    if (attacker.get_info("Type") != "Water" || attacker.get_info("Type") != "Grass" || attacker.get_info("Type") != "Fire" || attacker.get_info("Type") != "Ice" || attacker.get_info("Type") != "Electric" ||attacker.get_info("Type") != "Dragon" || attacker.get_info("Type") != "Dragon" || attacker.get_info("Type") != "Psychic" || attacker.get_info("Type") != "Poison") {
        if (attacker.poke_status() == "Burning"){
            attacker_attack = attacker.get_stats("Attack") / 2;
        }
        else{
            attacker_attack = attacker.get_stats("Attack");
        }
        defender_defense = defender.get_stats("Defense");
    }
    else{
        attacker_attack = attacker.get_stats("Special Attack");
        defender_defense = defender.get_stats("Special Defense");
    }
    if (move.move_info("Type") == attacker.get_info("Type1") || move.move_info("Type") == attacker.get_info("Type2")){
        stab_bonus = 1.5;
    }
    else{
        stab_bonus = 1;
    }
    double type_effectiveness = get_type_effectiveness(move.move_info("Type"), defender.get_info("Type 1"), defender.get_info("Type 2"));
    double damage = calc_damage(level, move.move_stats("Power"), attacker_attack, defender_defense, stab_bonus, type_effectiveness, 1);
    int hp = std::max(defender.get_stats("HP") - damage, 0.0);
    defender.change_stats("HP", hp);

    if (move.move_info("Type") == "Fire" and defender.poke_status() == "Frozen"){
        output.emplace_back(defender.get_info("Name") + "was thawed! It's no longer frozen!");
        defender.change_status("None");
    }
    return output;
}


void battle::simulate_battle(initialize_team team1, initialize_team team2) {
    int round = 1;
    std::string team1_poke;
    std::string team2_poke;
    std::string dead;
    int sleep_counter = 0;
    pokemon first_pokemon = pokemon();
    pokemon second_pokemon = pokemon();
    int counter = rand()%7 + 1;
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
        int poke1_hp = poke1.get_stats("HP");
        int poke2_hp = poke1.get_stats("HP");
        if (poke1_hp > 0 and poke2_hp > 0){
            if (poke1.poke_status() == "Paralyzed"){
                int new_speed = poke1.get_stats("Speed") / 4;
                poke1.change_stats("Speed", new_speed);
            }
            if (poke2.poke_status() == "Paralyzed"){
                int new_speed = poke2.get_stats("Speed") / 4;
                poke2.change_stats("Speed", new_speed);
            }
            bool poke_first = (poke2.get_stats("Speed") < poke1.get_stats("Speed")) or (poke2.get_stats("Speed") == poke1.get_stats("Speed") and (rand()%1) == 0);
            if (poke_first){
                pokemon first_pokemon = poke1;
                pokemon second_pokemon = poke2;
            }
            else{
                pokemon first_pokemon = poke2;
                pokemon second_pokemon = poke1;
            }
            if (poke1.poke_status() != "Sleeping"){
                sleep_counter = counter;
            }
            if (poke1.poke_status() == "Paralyzed" and (rand()%4 + 1) == 1){
                std::cout << poke1.get_info("Name") << " is paralyzed! It cannot move!" << std::endl;
            }
            else if (poke1.poke_status() == "Frozen"){
                std::cout << poke1.get_info("Name") << " is frozen solid" << std::endl;
            }
            else if (poke1.poke_status() == "Sleeping"){
                sleep_counter -= 1;
                if (sleep_counter > 0){
                    std::cout << poke1.get_info("Name") << " is fast asleep" << std::endl;
                }
                else{
                    std::cout << poke1.get_info("Name") << " woke up!" << std::endl;
                    poke1.poke_status() == "None";
                    sleep_counter = counter;
                }
            }
            else{
                PokeMove move = first_pokemon.get_moves();
                std::vector<std::string> results = process_attack(first_pokemon, second_pokemon, move);
            }


        }


        break;
    }
}