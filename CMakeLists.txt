cmake_minimum_required(VERSION 3.23)
project(PikusaPennString)

set(CMAKE_CXX_STANDARD 20)

include(CTest)

add_library(PikusaPennStringLib STATIC src/string.cpp src/UniquePtr.cpp)
target_include_directories(PikusaPennStringLib PUBLIC include)

foreach(string_test_name
    len_test 
    reserve_test
    append_test 
    constructors_operators_test
    concat_operators_test
    iterator_test)

    add_executable(${string_test_name} tests/${string_test_name}.cpp)
    target_link_libraries(${string_test_name} PRIVATE PikusaPennStringLib)
    add_test(NAME ${string_test_name} COMMAND ${string_test_name})
endforeach()
