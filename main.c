#include <stdio.h>

#include "utils/OOP/class/String.h"

int main()
{
    String *str;
    String test;

    test = initString("Hey !");
    str = newString("string");

    printf("SUCCESS\n");

    printf("Hello, World!\nsize= %d -> __str= %s\n", str->getLen(str), str->c_str(str));
    printf("Hello, World!\nsize= %d -> __str= %s\n", test.getLen(&test), test.c_str(&test));
    return 0;
}