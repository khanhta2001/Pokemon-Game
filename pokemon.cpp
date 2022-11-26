//
// Created by An Khanh Tran on 11/25/22.
//

#include <map>
#include <utility>
#include <vector>
#include "pokemon.h"
pokemon::pokemon(std::string name, int level, std::map<std::string,int> iv, std::map<std::string,int> ev, std::vector<std::string> moves){
    pokemon::name = std::move(name);
    pokemon::level = level;
    pokemon::iv = std::move(iv);
    pokemon::ev = std::move(ev);
    pokemon::moves = std::move(moves);
}

pokemon::~pokemon(){

}