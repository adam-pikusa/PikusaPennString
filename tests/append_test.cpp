#include <string.h>
#include <stdio.h>

#include "technikumSTL/string.h"

int append_test(int argc, char* argv[])
{
    technikum::string str_hello("Hello ");
    technikum::string str_world("World!");
    technikum::string str_2nd_comb(" This part was appended later!");

    str_hello.append(str_world);

    printf("combined string:");
    puts(str_hello.c_str());
    printf("size:%d,cap:%d\n", str_hello.size(), str_hello.capacity());

    if (strcmp(
        "Hello World!",
        str_hello.c_str())) return 1;

    str_hello.append(str_2nd_comb);

    printf("second combination:");
    puts(str_hello.c_str());
    printf("size:%d,cap:%d\n", str_hello.size(), str_hello.capacity());

    if (strcmp(
        "Hello World! This part was appended later!",
        str_hello.c_str())) return 1;

    return 0;
}