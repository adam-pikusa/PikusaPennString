cmake_minimum_required(VERSION 3.23)
project(PikusaPennString)

include(CTest)

add_library(PikusaPennStringLib STATIC src/string.cpp)
target_include_directories(PikusaPennStringLib PUBLIC include)

add_subdirectory(tests)

