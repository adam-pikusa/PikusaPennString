#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "technikumSTL/UniquePtr.h"


using namespace std;

TEST_CASE("Unique Pointer Test") 
{
	struct Entity {
		int id = -1;
	};

	technikum::UniquePtr<Entity> entityPointer(new Entity);
	technikum::UniquePtr<string> stringPointer(new string("Hello World"));
	std::cout << entityPointer->id;
	std::cout << stringPointer->c_str();
}