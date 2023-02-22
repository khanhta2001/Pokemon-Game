#include <map>
#include "pokemon.h"
#include "PokeMove.h"
#include "io_functions.h"

PokeMove::PokeMove(const std::string& move_name) {
    io_functions stats = io_functions();
    std::map<std::string,std::map<std::string,std::string>> move_stats = stats.stats_info("moves_stats");
    std::map<std::string,std::string> moves = move_stats[move_name];
    PokeMove::name = moves["Name"];
    PokeMove::movetype = moves["Type"];
    PokeMove::power = stoi(moves["Power"]);
    PokeMove::pp = stoi(moves["PP"]);
    PokeMove::accuracy = stoi(moves["Accuracy"]);
    PokeMove::effect = moves["Effect"];
}

PokeMove::~PokeMove() = default;

std::string PokeMove::move_type() {
    return PokeMove::movetype;
}

std::string PokeMove::move_definition() {
    std::string def = "Name: " + PokeMove::name + ", pokeType: " + PokeMove::movetype;
    return def;
}

std::map<std::string,int> PokeMove::move_stats() {
    std::map<std::string, int> stats = {{"Power",          PokeMove::power},
                                        {"PP",         PokeMove::pp},
                                        {"Accuracy",  PokeMove::accuracy}};
    return stats;
}

std::map<std::string,std::string> PokeMove::move_info() {
    std::map<std::string, std::string> stats = {{"Name",          PokeMove::name},
                                                {"Type",         PokeMove::movetype},
                                                {"Effect",         PokeMove::effect}};
    return stats;
}


