#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "technikumSTL/string.h"

TEST_CASE("concat operators")
{
    technikum::string s1("Hello");
    const technikum::string s2("World");
    s1 += s2;
    technikum::string s3 = s1 + s2;
    s3 += "Hello";
    const technikum::string s4 = s3 + "World";
    CHECK_EQ(strcmp(s4, "HelloWorldWorldHelloWorld"), 0);
}