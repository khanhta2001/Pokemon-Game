//
// Created by An Khanh Tran on 11/24/22.
//

#ifndef GAME_MOVE_H
#define GAME_MOVE_H


#include <string>

class move {
public:
    move(std::string name, std::string poketype, std::string power, std::string pp, std::string accuracy, std::string priority, std::string effect, std::string effect_chance);
    ~move();

    bool eval_effect_chance();

private:
    std::string name;
    std::string poketype;
    int power;
    int powerPoint;
    int accuracy;
    std::string priority;
    int effect;
    int effect_chance;



};


#endif //GAME_MOVE_H
