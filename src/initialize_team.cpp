#include "initialize_team.h"

initialize_team::initialize_team() {
    initialize_team::poke_team = {};
    initialize_team::death = 0;
}

initialize_team::~initialize_team()= default;

int initialize_team::size() {
    return initialize_team::poke_team.size();
}
void initialize_team::add_poke(const pokemon& pokemon){
    initialize_team::poke_team.emplace_back(pokemon);
}
void initialize_team::add_death() {
    initialize_team::death += 1;
}

int initialize_team::total_dead() {

    return initialize_team::death;
}

pokemon initialize_team::poke(const std::string& name){
    for (int i = 0; i < initialize_team::poke_team.size(); i++){
        std::string name_poke = initialize_team::poke_team[i].get_info("Name");
        if (name_poke == name){
            return initialize_team::poke_team[i];
        }
    }
}

int initialize_team::check_poke(const std::string& name) {
    for (int i = 0; i < initialize_team::poke_team.size(); i++){
        std::string name_poke = initialize_team::poke_team[i].get_info("Name");
        if (name_poke == name){
            return true;
        }
    }
    return false;
}

