#ifndef GAME_INITIALIZE_TEAM_H
#define GAME_INITIALIZE_TEAM_H
#include "pokemon.h"


class initialize_team {

public:
    initialize_team();
    ~initialize_team();
    void team(pokemon* pokemon);
    bool empty();
    void report_dead(pokemon* pokemon);
    pokemon poke(const std::string& name);
    int total_dead();
    int check_poke(const std::string& name);

private:
    std::map<pokemon*,std::string> poke_team;
};


#endif //GAME_INITIALIZE_TEAM_H
