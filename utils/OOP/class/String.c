/*
** String.c for Zappy in /home/wyzlic_a/delivery/Zappy/String.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 14:38:17 2017 Dimitri Wyzlic
** Last update Mon Jun 05 14:38:17 2017 Dimitri Wyzlic
*/

#include "error.h"
#include "String.h"

static char *val(String *this);
static char *to_str(String *this);
static int len(String *this);
static char at(String *this, int at);
static String *add(String *this, String *other);

String *newString(char *str)
{
    void *new;
    String tmp;

    tmp = initString(str);
    if ((new = calloc(1, sizeof(String))) == NULL)
        raise(get_error());
    if ((new = memcpy(new, &tmp, sizeof(String))) == NULL)
        raise(get_error());
    String *out = (String *)new;

    return (out);
}

String initString(char *str)
{
    String out;

    out.len = &len;
    out.val = &val;
    out.at = &at;
    out.to_str = &to_str;
    out.add = &add;

    out.__str = str;
    out.__len = strlen(str);

    return (out);
}

#include "implem/StringImplem1.c"