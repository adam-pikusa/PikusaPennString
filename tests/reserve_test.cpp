#include <string.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "technikumSTL/string.h"

TEST_CASE("reserve higher capacity > _small_string_buffer_size")
{
    auto expression_a = "Hello this is a long string!";
    technikum::string str_a(expression_a);
    str_a.reserve(40);
    CHECK_EQ(str_a.size(), strlen(expression_a));
    CHECK_EQ(str_a.capacity(), 40);
}

TEST_CASE("reserve lower capacity > _small_string_buffer_size")
{
    auto expression_a = "Hello this is a long string!";
    technikum::string str_a(expression_a);
    str_a.reserve(20);
    CHECK_EQ(str_a.size(), 20 - 1);
    CHECK_EQ(str_a.capacity(), 20);
    CHECK_EQ(strcmp(str_a.c_str(), "Hello this is a lon"), 0);
}

TEST_CASE("reserve lower capacity < _small_string_buffer_size")
{
    auto expression_b = "Hello World!";
    technikum::string str_b(expression_b);
    str_b.reserve(6);
    CHECK_EQ(str_b.size(), 6 - 1);
    CHECK_EQ(str_b.capacity(), technikum::string::small_string_buffer_size);
    CHECK_EQ(strcmp(str_b.c_str(), "Hello"), 0);
}

TEST_CASE("reserve higher < _small_string_buffer_size")
{
    auto expression_c = "Hey";
    technikum::string str_c(expression_c);
    str_c.reserve(7);
    CHECK_EQ(str_c.size(), strlen(expression_c));
    CHECK_EQ(str_c.capacity(), technikum::string::small_string_buffer_size);
    CHECK_EQ(strcmp(str_c.c_str(), "Hey"), 0);
}

TEST_CASE("reserve lower starting < small buffer size")
{
    auto expression_d = "Hallo";
    technikum::string str_d(expression_d);
    str_d.reserve(3);
    CHECK_EQ(str_d.size(), 3 - 1);
    CHECK_EQ(str_d.capacity(), technikum::string::small_string_buffer_size);
    CHECK_EQ(strcmp(str_d.c_str(), "Ha"), 0);
}