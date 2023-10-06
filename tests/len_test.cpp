#include <stdio.h>
#include <string.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "technikumSTL/string.h"

TEST_CASE("size of long string")
{
    auto expression_a = "Hello!";
    technikum::string str_a(expression_a);
    CHECK_EQ(str_a.size(), strlen(expression_a));
}

TEST_CASE("size of short string")
{
    auto expression_b = "Hello World!";
    technikum::string str_b(expression_b);
    CHECK_EQ(str_b.size(), strlen(expression_b));
}