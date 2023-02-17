
#ifndef GAME_IO_FUNCTIONS_H
#define GAME_IO_FUNCTIONS_H
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>
#include <map>
#include <vector>

class io_functions{
public:
    io_functions();
    ~io_functions();
    std::map<std::string,std::map<std::string,std::string>> stats_info(const std::string& file_type);
    std::map<std::string,std::map<std::string,std::string>> moves_info();
private:
    std::string moves_file;
    std::string pokemon_stats;
    std::string type_damage;
    std::string pokemon_moves;

};
#endif //GAME_IO_FUNCTIONS_H
