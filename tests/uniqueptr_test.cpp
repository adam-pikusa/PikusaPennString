#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "technikumSTL/UniquePtr.h"


using namespace std;

struct Entity {
	int id = -1;
};

void test(Entity*) 
{
	puts("custom deleter");
}

TEST_CASE("Unique Pointer Test") 
{

	technikum::UniquePtr<Entity, test> entityPointer(new Entity);
	technikum::UniquePtr<string> stringPointer(new string("Hello World"));
	CHECK_EQ(entityPointer->id, -1);
	CHECK_EQ(strcmp(stringPointer->c_str(), "Hello World"), 0);
}