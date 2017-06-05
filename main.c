#include <stdio.h>

#include "utils/OOP/class/String.h"

int ZAPPY() asm("main");

int ZAPPY()
{
    String *str;
    String test;

    test = initString("Hey !");
    str = newString("string");

    printf("SUCCESS\n");

    printf("Hello, World!\nsize= %d -> __str= %s\n", str->len(str), str->val(str));
    printf("Hello, World!\nsize= %d -> __str= %s\n", test.len(&test), test.val(&test));
    return 0;
}
