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