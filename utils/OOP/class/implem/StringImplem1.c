/*
** StringImplem1.c for Zappy in /home/wyzlic_a/delivery/Zappy/StringImplem1.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 20:17:42 2017 Dimitri Wyzlic
** Last update Mon Jun 05 20:17:42 2017 Dimitri Wyzlic
*/

#include <error.h>
#include "String.h"

static int len(String *this)
{
    return this->__len;
}

static char *val(String *this)
{
    return this->__str;
}

static char *to_str(String *this)
{
    return this->__str;
}

static char at(String *this, int at)
{

#ifdef DEBUG
    if (at > this->__len || at < 0)
        raise("Invalid index");
#endif
    return this->__str[at];
}

static String *add(String *this, String *other)
{
    String *out;

    out = newString(this->__str);
    out->__str = malloc(sizeof(char) * (this->__len + other->__len));
    if (out->__str == NULL)
        raise("Malloc fail");
    strcpy(out->__str, this->__str);
    strcat(out->__str, other->__str);
    out->__len = strlen(out->__str);
    return (out);
}