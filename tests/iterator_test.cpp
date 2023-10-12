#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "technikumSTL/string.h"

TEST_CASE("iterators")
{
	const technikum::string test("Hello World");

	for (technikum::string::Iterator it = test.begin<const char*>();
		it != test.end<const char*>(); ++it)
	{ 
		std::cout << *it << '\n'; 
	}

	std::cout << (std::find(test.begin<const char*>(), test.end<const char*>(), 'W') != test.end<const char*>()) << '\n';
}