#include <stdio.h>
#include <utility>
#include <string.h>

#include "technikumSTL/string.h"

int constructors_operators_test(int argc, char* argv[]) 
{
	//Copy Constructor - short string
	technikum::string string1("Hello");
	technikum::string copyString1(string1);

	if (strcmp(copyString1.c_str(), "Hello") != 0) return 1;

	//Copy Constructor - long string
	technikum::string string1_long("Hello123456789");
	technikum::string copyString1_long(string1_long);

	if (strcmp(copyString1_long.c_str(), "Hello123456789") != 0) return 1;

	//Copy assignment
	technikum::string string2("Something");

	string1 = string2;
	if (strcmp(string1.c_str(), "Something") != 0) return 1;

	//Move Constructor
	technikum::string string3("No idea long");
	technikum::string movedString(std::move(string3));

	if (strcmp(movedString.c_str(), "No idea long") != 0) return 1;

	//Move assignment
	technikum::string string4("Yoyoyoyoyo");
	technikum::string anotherMovedString("NotYoyoyo");

	anotherMovedString.operator=(std::move(string4));

	if (strcmp(anotherMovedString.c_str(), "Yoyoyoyoyo") != 0) return 1;

	return 0;
}
