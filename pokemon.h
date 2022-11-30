//
// Created by An Khanh Tran on 11/25/22.
//

#ifndef GAME_POKEMON_H
#define GAME_POKEMON_H
#include <string>
#include <map>
#include <vector>

class pokemon {
public:
    pokemon(std::string name, int level, std::map<std::string,int> iv, std::map<std::string,int> ev, std::vector<std::string> moves);
    ~pokemon();

    int hp_caculation(int hp, std::map<std::string,int> iv, std::map<std::string,int> ev, int level,  );

private:
    std::string name;
    std::map<std::string,int> iv;
    std::map<std::string,int> ev;
    std::vector<std::string> moves;
};


#endif //GAME_POKEMON_H
