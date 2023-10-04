cmake_minimum_required(VERSION 3.23)
project(PikusaPennString)

foreach(string_test_name
    len_test 
    reserve_test
    append_test 
    constructors_operators_test)

    add_executable(${string_test_name} ${string_test_name}.cpp)
    target_link_libraries(${string_test_name} PRIVATE PikusaPennStringLib)
    add_test(NAME ${string_test_name} COMMAND ${string_test_name})
endforeach()

