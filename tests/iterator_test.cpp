#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "technikumSTL/string.h"

TEST_CASE("iterators")
{
	const technikum::string test("Hello World");

	for (auto it = test.cbegin();
		it != test.cend(); ++it)
	{ 
		std::cout << *it << '\n'; 
	}

	std::cout << (std::find(test.cbegin(), test.cend(), 'W') != test.cend()) << '\n';
}

TEST_CASE("subscript iterator")
{
	const technikum::string test("Hello World");
	CHECK_EQ(test.cbegin()[4], 'o');
}

TEST_CASE("iterator and int addition")
{
	const technikum::string test("Hello World");
	CHECK_EQ(&*test.cend(), test.cbegin() + 11); 
}

TEST_CASE("iterator and int subtraction")
{
	const technikum::string test("Hello World");
	CHECK_EQ(&*test.cbegin(), test.cend() - 11); 
}

TEST_CASE("iterator add assign")
{
	const technikum::string test("Hello World");
	auto it = test.cbegin();
	it += 3;
	CHECK_EQ(&*it, test.cbegin() + 3);
}