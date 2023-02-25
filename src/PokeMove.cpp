#include <map>
#include "PokeMove.h"
#include "io_functions.h"

PokeMove::PokeMove(const std::string& move_name) {
    io_functions stats = io_functions();
    std::map<std::string,std::map<std::string,std::string>> move_stats = stats.stats_info("moves_stats");
    std::map<std::string,std::string> moves = move_stats[move_name];
    PokeMove::name = moves["Name"];
    PokeMove::movetype = moves["Type"];
    if (moves["Power"] == "-"){
        PokeMove::power = -1;
    }
    else{
        PokeMove::power = std::stoi(moves["Power"]);
    }
    if (moves["PP"] == "-"){
        PokeMove::pp = -1;
    }
    else{
        PokeMove::pp = std::stoi(moves["PP"]);
    }
    if (moves["Accuracy"] == "-"){
        PokeMove::accuracy = -1;
    }
    else{
        PokeMove::accuracy = std::stoi(moves["Accuracy"]);
    }
    PokeMove::effect = moves["Effect"];
}

PokeMove::~PokeMove() = default;

std::string PokeMove::move_definition() {
    std::string def = "Name: " + PokeMove::name + ", pokeType: " + PokeMove::movetype;
    return def;
}

int PokeMove::move_stats(const std::string& stat_name) {
    std::map<std::string, int> stats = {{"Power",          PokeMove::power},
                                        {"PP",         PokeMove::pp},
                                        {"Accuracy",  PokeMove::accuracy}};
    return stats[stat_name];
}

std::string PokeMove::move_info(const std::string& stat_name) {
    std::map<std::string, std::string> stats = {{"Name",          PokeMove::name},
                                                {"Type",         PokeMove::movetype},
                                                {"Effect",         PokeMove::effect}};
    return stats[stat_name];
}


