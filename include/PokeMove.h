
#ifndef GAME_MOVE_H
#define GAME_MOVE_H
#include <string>
#include <map>
#include <vector>

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


#endif //GAME_MOVE_H