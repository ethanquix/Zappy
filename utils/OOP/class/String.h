/*
** String.h for Zappy in /home/wyzlic_a/delivery/Zappy/String.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 14:38:22 2017 Dimitri Wyzlic
** Last update Mon Jun 05 14:38:22 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_STRING_H
#define ZAPPY_STRING_H

#include <stdlib.h>
#include <memory.h>
#include <Alfred.h>

typedef class s_String String;

class s_String{
    char *__str;
    int __len;
    int (*len)(String *this);
    char *(*val)(String *this); // = to_str
    char *(*to_str)(String *this); // == val
    String *(*add)(String *this, String *other);
    char (*at)(String *this, int emp);
//    String (plus)
};

String *newString(char *str);
String initString(char *str);

#endif //ZAPPY_STRING_H
