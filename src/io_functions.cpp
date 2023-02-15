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

}

io_functions::~io_functions() {

}


int max(){
    std::ifstream ifs("../../data/moves.json");
    if ( !ifs.is_open() )
    {
        std::cerr << "Could not open file for reading!\n";
        return EXIT_FAILURE;
    }
    rapidjson::IStreamWrapper isw(ifs);
    rapidjson::Document sd;
    sd.ParseStream(isw);

    rapidjson::StringBuffer buffer {};
    rapidjson::Writer<rapidjson::StringBuffer> writer { buffer };

    sd.Accept(writer);

    if (sd.HasParseError()) {
        std::cout << "Problems" << std::endl;
    }
    if ( sd.HasParseError() )
    {
        std::cout << "Error  : " << sd.GetParseError()  << '\n'
                  << "Offset : " << sd.GetErrorOffset() << '\n';
        return EXIT_FAILURE;
    }

    const std::string jsonStr { buffer.GetString() };

    std::cout << jsonStr << '\n';
    return 1;
}
