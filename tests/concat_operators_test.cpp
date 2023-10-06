#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "technikumSTL/string.h"

TEST_CASE("concat operators")
{
    technikum::string s1("Hello");
    const technikum::string s2("World");
    s1 += s2;

    CHECK_EQ(strcmp(s1, "HelloWorld"), 0);

    technikum::string s3 = s1 + s2;

    CHECK_EQ(strcmp(s3, "HelloWorldWorld"), 0);

    s3 += "Hello";

    CHECK_EQ(strcmp(s3, "HelloWorldWorldHello"), 0);

    const technikum::string s4 = s3 + "World";

    CHECK_EQ(strcmp(s4, "HelloWorldWorldHelloWorld"), 0);
}