#include <stdio.h>
#include <string.h>

#include "technikumSTL/string.h"

int len_test(int argc, char* argv[])
{
    auto expression_a = "Hello!";
    auto expression_b = "Hello World!";

    technikum::string str_a(expression_a);
    technikum::string str_b(expression_b);

    if (str_a.size() != strlen(expression_a)) return 1;
    if (str_b.size() != strlen(expression_b)) return 1;
    
    return 0;
}