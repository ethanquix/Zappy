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

static int getLen(struct s_String *this);
static char *c_str(String *this);

String *newString(char *str)
{
    void	*new;
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

    out.getLen = &getLen;
    out.c_str = &c_str;

    out.__str = str;
    out.__len = strlen(str);

    return (out);
}

static int getLen(String *this)
{
    return this->__len;
}

static char *c_str(String *this)
{
    return this->__str;
}