cmake_minimum_required(VERSION 3.23)
project(PikusaPennString)

create_test_sourcelist(TestList
    TestingExe.cpp
    append_test.cpp
    len_test.cpp
    reserve_test.cpp
    constructors_operators_test.cpp)

add_executable(TestingExe ${TestList})
target_link_libraries(TestingExe PRIVATE PikusaPennStringLib)
    
add_test(NAME append_test COMMAND TestingExe append_test)
add_test(NAME len_test COMMAND TestingExe len_test)
add_test(NAME reserve_test COMMAND TestingExe reserve_test)
add_test(NAME constructors_operators_test COMMAND TestingExe constructors_operators_test)