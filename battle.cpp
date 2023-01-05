//
// Created by ankha on 1/4/2023.
//

#include <iostream>
#include "battle.h"

battle::battle() {

}

battle::~battle() {

}

std::string battle::pick_poke(initialize_team team) {
    if (!team.empty()){
        std::cout << "Pick one of your pokemon below " << std::endl;
        team.print();
        std::string pick_poke;
        std::cin >> pick_poke;
        std::cout << "You picked " << pick_poke << std::endl;
        return pick_poke;
    }
    std::cout << "You ran out of pokemon! You lost." << std::endl;
}

void battle::simulate_battle(initialize_team team1, initialize_team team2) {
    int round = 1;
    std::string team1_poke;
    std::string team2_poke;
    std::string dead;
    while (true){
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

        break;
    }
}
