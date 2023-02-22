
#ifndef GAME_MOVE_H
#define GAME_MOVE_H
#include <string>
#include <map>
#include <vector>

class PokeMove{
public:
    PokeMove(const std::string& name);
    ~PokeMove();
    std::string move_type();
    std::string move_definition();
    int eval_effect_chance() const;
    std::map<std::string,int> move_stats();
    std::map<std::string,std::string> move_info();


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