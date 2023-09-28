#include <stdio.h>
#include <string.h>

#include "technikumSTL/string.h"

int reserve_test(int argc, char* argv[])
{
    auto expression_a = "Hello this is a long string!";
    auto expression_b = "Hello World!";
    auto expression_c = "Hey";
    auto expression_d = "Hallo";

    technikum::string str_a(expression_a);
    technikum::string str_b(expression_b);
    technikum::string str_c(expression_c);
    technikum::string str_d(expression_d);

    //reserve higher capacity > _small_string_buffer_size
    str_a.reserve(40);
    if (str_a.size() != strlen(expression_a)) return 1;
    if (str_a.capacity() != 40) return 1;

    //reserve lower capacity > _small_string_buffer_size
    str_a.reserve(20);
    if (str_a.size() != 20 - 1) return 1;
    if (str_a.capacity() != 20) return 1;
    if (strcmp(str_a.c_str(), "Hello this is a lon") != 0) return 1;

    //reserve lower capacity < _small_string_buffer_size
    str_b.reserve(6);
    if (str_b.size() != 6 - 1) return 1;
    if (str_b.capacity() != technikum::string::small_string_buffer_size) return 1;
    if (strcmp(str_b.c_str(), "Hello") != 0) return 1;

    //reserve higher < _small_string_buffer_size
    str_c.reserve(7);
    if (str_c.size() != strlen(expression_c)) return 1;
    if (str_c.capacity() != technikum::string::small_string_buffer_size) return 1;
    if (strcmp(str_c.c_str(), "Hey") != 0) return 1;

    //reserve lower starting < small buffer size
    str_d.reserve(3);
    if (str_d.size() != 3 - 1) return 1;
    if (str_d.capacity() != technikum::string::small_string_buffer_size) return 1;
    if (strcmp(str_d.c_str(), "Ha") != 0) return 1;

    printf(str_a.c_str());
    printf(str_b.c_str());
    printf(str_c.c_str());
    printf(str_d.c_str());

    return 0;
}