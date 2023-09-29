cmake_minimum_required(VERSION 3.23)
project(PikusaPennString)

add_executable(TestingExe
    append_test.cpp
    len_test.cpp
    reserve_test.cpp
    constructors_operators_test.cpp)
target_link_libraries(TestingExe PRIVATE PikusaPennStringLib)
    
add_test(NAME len_test COMMAND TestingExe)
