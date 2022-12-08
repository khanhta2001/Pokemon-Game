cmake_minimum_required(VERSION 3.23)
project(game)

set(CMAKE_CXX_STANDARD 20)

add_executable(game main.cpp pokemon.cpp pokemon.h initialize_team.cpp initialize_team.h simulate_battle.cpp simulate_battle.h)
