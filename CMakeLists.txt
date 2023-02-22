cmake_minimum_required(VERSION 3.23)
project(game CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(BEFORE ${CMAKE_SOURCE_DIR}/include)
include_directories(BEFORE ${CMAKE_SOURCE_DIR}/rapidjson/include)
include_directories(BEFORE ${CMAKE_SOURCE_DIR}/data)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
