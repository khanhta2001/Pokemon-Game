//
// Created by An Khanh Tran on 12/8/22.
//

#include "simulate_battle.h"

#include <iostream>
#include <utility>

simulate_battle::simulate_battle(std::vector<pokemon*> team1, std::vector<pokemon*> team2) {
    simulate_battle::team1 = std::move(team1);
    simulate_battle::team2 = std::move(team2);
}

simulate_battle::~simulate_battle() {

}

void simulate_battle::battle() {

}
