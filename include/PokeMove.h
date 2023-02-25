
#ifndef GAME_MOVE_H
#define GAME_MOVE_H
#include <string>
#include <map>
#include <vector>

class PokeMove{
public:
    PokeMove(const std::string& name);
    ~PokeMove();
    std::string move_definition();
    int eval_effect_chance() const;
    int move_stats(const std::string& stat_name);
    std::string move_info(const std::string& stat_name);


private:
    std::string name;
    std::string movetype;
    int power;
    int pp;
    int accuracy;
    std::string priority;
    std::string effect;

};


#endif //GAME_MOVE_H