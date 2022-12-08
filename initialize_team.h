#ifndef GAME_INITIALIZE_TEAM_H
#define GAME_INITIALIZE_TEAM_H
#include "pokemon.h"


class initialize_team {
public:
    initialize_team();
    ~initialize_team();
    void team(pokemon* pokemon);
    void print();
private:
    std::vector<pokemon*> poke_team;
};


#endif //GAME_INITIALIZE_TEAM_H
