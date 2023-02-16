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
}

io_functions::~io_functions() {

}

std::map<std::string,std::map<std::string,std::string>> io_functions::MovesData() {
    std::ifstream inputFile(io_functions::moves_file);

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


std::map<std::string,std::map<std::string,std::string>> io_functions::PokeStats() {
    std::ifstream inputFile(io_functions::pokemon_stats);

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

std::map<std::string,std::map<std::string,std::string>> io_functions::TypeDamage() {
    std::ifstream inputFile(io_functions::type_damage);

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
