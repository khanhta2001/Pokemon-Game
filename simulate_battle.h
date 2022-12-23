#ifndef GAME_SIMULATE_BATTLE_H
#define GAME_SIMULATE_BATTLE_H

#include <vector>

#include "pokemon.h"

class simulate_battle {
public:
    simulate_battle(std::vector<pokemon*> team1, std::vector<pokemon*> team2);
    ~simulate_battle();

    void battle();

private:
    std::vector<pokemon*> team1;
    std::vector<pokemon*> team2;
};


#endif //GAME_SIMULATE_BATTLE_H
