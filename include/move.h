//
// Created by ankha on 1/18/2023.
//

#ifndef GAME_MOVE_H
#define GAME_MOVE_H

#endif //GAME_MOVE_H

class PokeMove{
public:
    PokeMove(std::string name, std::string poketype, int power, int pp, int accuracy, std::string priority, int effect, int effect_chance);
    ~PokeMove();
    std::string move_type();
    std::string move_definition();
    int eval_effect_chance();


private:
    std::string name;
    std::string poketype;
    int power;
    int pp;
    int accuracy;
    std::string priority;
    int effect;
    int effect_chance;

};