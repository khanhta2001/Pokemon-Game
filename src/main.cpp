#include "battle.h"
#include <iostream>

int main() {
    battle test1 = battle();
    initialize_team team1 = initialize_team();
    initialize_team team2 = initialize_team();
    test1.simulate_battle(team1, team2);

}