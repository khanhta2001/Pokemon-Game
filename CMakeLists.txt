cmake_minimum_required(VERSION 3.23)
project(game)

set(CMAKE_CXX_STANDARD 20)

add_executable(game main.cpp move.cpp move.h pokemon.cpp pokemon.h)
