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

#define String struct s_String

typedef struct s_String{
    char *__str;
    int __len;
    int (*getLen)(String *this);
    char *(*c_str)(String *this);
} t_String;

String *newString(char *str);
String initString(char *str);

#endif //ZAPPY_STRING_H
