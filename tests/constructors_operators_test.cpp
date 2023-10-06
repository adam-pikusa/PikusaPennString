#include <stdio.h>
#include <utility>
#include <string.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "technikumSTL/string.h"

TEST_CASE("Copy Constructor - short string")
{
	technikum::string string1("Hello");
	technikum::string copyString1(string1);

	CHECK_EQ(strcmp(copyString1.c_str(), "Hello"), 0);
}

TEST_CASE("Copy Constructor - long string")
{
	technikum::string string1_long("Hello123456789");
	technikum::string copyString1_long(string1_long);

	CHECK_EQ(strcmp(copyString1_long.c_str(), "Hello123456789"), 0);
}

TEST_CASE("Copy assignment")
{
	technikum::string string2("Something");

	technikum::string string1 = string2;
	CHECK_EQ(strcmp(string1.c_str(), "Something"), 0);
}

TEST_CASE("Move Constructor")
{
	technikum::string string3("No idea long");
	technikum::string movedString(std::move(string3));

	CHECK_EQ(strcmp(movedString.c_str(), "No idea long"), 0);
}

TEST_CASE("Move assignment")
{
	technikum::string string4("Yoyoyoyoyo");
	technikum::string anotherMovedString("NotYoyoyo");

	anotherMovedString.operator=(std::move(string4));

	CHECK_EQ(strcmp(anotherMovedString.c_str(), "Yoyoyoyoyo"), 0);
}
