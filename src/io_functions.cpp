#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include "pokemon.h"
#include "io_functions.h"

io_functions::io_functions() {
    io_functions::moves_file = "../../data/moves.json";
    io_functions::pokemon_stats = "../../data/pokemon_stats.json";
    io_functions::type_damage = "../../data/type_damage.json";
    io_functions::pokemon_moves = "../../data/pokemon_moves.json";
}

io_functions::~io_functions() = default;

std::map<std::string,std::map<std::string,std::string>> io_functions::stats_info(const std::string& file_type) {
    std::string file;
    if (file_type == "type_damage"){
        file = io_functions::type_damage;
    }
    else if (file_type == "poke_stats"){
        file = io_functions::pokemon_stats;
    }
    else if (file_type == "moves_stats"){
        file = io_functions::moves_file;
    }

    std::ifstream inputFile(file);
    // Read the contents of the file into a string
    std::string jsonStr((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    rapidjson::Document sd;
    sd.Parse(jsonStr.c_str());

    std::map<std::string,std::map<std::string,std::string>> HashMap;

    for (rapidjson::Value::ConstMemberIterator itr = sd.MemberBegin(); itr != sd.MemberEnd(); ++itr) {
        const rapidjson::Value& val = itr->value;
        std::map<std::string,std::string> map2;
        for (rapidjson::Value::ConstMemberIterator ptr = val.MemberBegin(); ptr != val.MemberEnd(); ++ptr) {
            if (!ptr->value.IsInt()){
                map2[ptr->name.GetString()] = ptr->value.GetString();
            }
            else{
                map2[ptr->name.GetString()] = std::to_string(ptr->value.GetInt());
            }
        }
        HashMap[itr->name.GetString()] = map2;
    }

    return HashMap;
}

std::map<std::string, std::map<std::string, std::string>> io_functions::moves_info() {
    std::string file = io_functions::pokemon_moves;


    std::ifstream inputFile(file);
    // Read the contents of the file into a string
    std::string jsonStr((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    rapidjson::Document sd;
    sd.Parse(jsonStr.c_str());

    std::map<std::string,std::map<std::string,std::string>> HashMap;

    for (rapidjson::Value::ConstMemberIterator itr = sd.MemberBegin(); itr != sd.MemberEnd(); ++itr) {
        const rapidjson::Value& val = itr->value;
        std::map<std::string,std::string> map2;
        rapidjson::Value::ConstMemberIterator ptr = val.MemberBegin();
        auto test1 = ptr->name.GetString();
        //std::cout << test1 << std::endl;
        auto test2 = ptr->value.GetArray();

        HashMap[itr->name.GetString()] = map2;
    }

    return HashMap;
}
