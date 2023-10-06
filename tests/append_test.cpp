#include <string.h>
#include <stdio.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "technikumSTL/string.h"

TEST_CASE("append test")
{
    technikum::string str_hello("Hello ");
    technikum::string str_world("World!");
    technikum::string str_2nd_comb(" This part was appended later!");

    str_hello.append(str_world);

    printf("combined string:");
    puts(str_hello.c_str());
    printf("size:%d,cap:%d\n", str_hello.size(), str_hello.capacity());

    CHECK_EQ(strcmp(
        "Hello World!",
        str_hello.c_str()), 0);

    str_hello.append(str_2nd_comb);

    printf("second combination:");
    puts(str_hello.c_str());
    printf("size:%d,cap:%d\n", str_hello.size(), str_hello.capacity());

    CHECK_EQ(strcmp(
        "Hello World! This part was appended later!",
        str_hello.c_str()), 0);
}