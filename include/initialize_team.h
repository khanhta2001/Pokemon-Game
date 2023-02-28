#ifndef GAME_INITIALIZE_TEAM_H
#define GAME_INITIALIZE_TEAM_H
#include "pokemon.h"


class initialize_team {

public:
    initialize_team();
    ~initialize_team();
    int size();
    void add_poke(const pokemon& pokemon);
    void add_death();
    pokemon poke(const std::string& name);
    int total_dead();
    int check_poke(const std::string& name);

private:
    std::vector<pokemon> poke_team;
    int death;
};


#endif //GAME_INITIALIZE_TEAM_H
