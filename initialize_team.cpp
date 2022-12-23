#include <iostream>
#include "initialize_team.h"

initialize_team::initialize_team() {
    initialize_team::poke_team = {};
}

initialize_team::~initialize_team(){
}

void initialize_team::team(pokemon* pokemon) {
    initialize_team::poke_team.push_back(pokemon);
}

void initialize_team::print(){
    for (int i = 0; i < initialize_team::poke_team.size(); i++){
        // initialize_team::poke_team.at(i)->print();
        std::cout << "Pokemon " << i+1 <<" and its stats in the team:"<< std::endl;
        initialize_team::poke_team.at(i)->print();
        std::cout << std::endl;
    }
}

