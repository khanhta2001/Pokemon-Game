#include <iostream>
#include "initialize_team.h"
#include <vector>

initialize_team::initialize_team() {
    initialize_team::poke_team = {};
}

initialize_team::~initialize_team()= default;

void initialize_team::team(pokemon* pokemon) {
    initialize_team::poke_team.insert({pokemon,"Alive"});
}

void initialize_team::report_dead(pokemon* pokemon) {
    initialize_team::poke_team[pokemon] = "Dead";
}

bool initialize_team::empty(){
    if (initialize_team::poke_team.empty()){
        return true;
    }
    return false;
}
void initialize_team::print(){
    for (auto i = initialize_team::poke_team.begin(); i != initialize_team::poke_team.end(); i++){
        i->first->print_name();
    }
    std::cout << std::endl;
}

pokemon initialize_team::poke(const std::string& name){
    for (auto i = initialize_team::poke_team.begin(); i != initialize_team::poke_team.end(); i++){
        std::string name_poke = i->first->get_name();
        if (name_poke == name){
            return *i->first;
        }
    }
}

int initialize_team::total_dead() {
    int total = 0;
    for (auto i = initialize_team::poke_team.begin(); i != initialize_team::poke_team.end(); i++){
        if (i->second == "Dead"){
            total += 1;
        }
    }
    return total;
}

int initialize_team::check_poke(const std::string& name) {
    for (auto i = initialize_team::poke_team.begin(); i != initialize_team::poke_team.end(); i++){
        std::string name_poke = i->first->get_name();
        if (name_poke == name){
            return true;
        }
    }
    return false;
}

