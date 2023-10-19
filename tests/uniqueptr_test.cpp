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

TEST_CASE("Unique Pointer Construction test") 
{

	technikum::UniquePtr<Entity, test> entityPointer(new Entity);
	technikum::UniquePtr<string> stringPointer(new string("Hello World"));
	CHECK_EQ(entityPointer->id, -1);
	CHECK_EQ(strcmp(stringPointer->c_str(), "Hello World"), 0);

}

TEST_CASE("Swap Test") 
{
	technikum::UniquePtr<string> stringPointer(new string("Hello World"));
	technikum::UniquePtr<string> anotherStrPointer(new string("Something"));

	anotherStrPointer.Swap(stringPointer);

	CHECK_EQ(strcmp(stringPointer->c_str(), "Something"), 0);
	CHECK_EQ(strcmp(anotherStrPointer->c_str(), "Hello World"), 0);
}

TEST_CASE("Release Test") 
{
	technikum::UniquePtr<Entity, test> entityPointer(new Entity);
	Entity* entity = entityPointer.Release();

	CHECK_EQ(entity->id, -1);
	bool isNull = entityPointer;
	CHECK(!isNull);
}

TEST_CASE("Reset Test") 
{
	technikum::UniquePtr<Entity, test> entityPointer(new Entity);
	entityPointer.Reset();

	bool isNull = entityPointer;
	CHECK(!isNull);
}