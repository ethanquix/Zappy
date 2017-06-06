/*
** StringImplem1.c for Zappy in /home/wyzlic_a/delivery/Zappy/StringImplem1.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 20:17:42 2017 Dimitri Wyzlic
** Last update Mon Jun 05 20:17:42 2017 Dimitri Wyzlic
*/

#include <stdio.h>
#include "Alfred.h"
#include "String.h"

static int	len(String *this)
{
  return this->__len;
}

static char	*val(String *this)
{
  return this->__str;
}

static char	*to_str(String *this)
{
  char		*out;
  size_t	size;

  size = (size_t) snprintf(NULL, 0, "String -> value: %s\n", this->__str);
  MALLOC(out, size + 1);
  snprintf(out, size + 1, "String -> value: %s\n", this->__str);
  return this->__str;
}

static char	at(String *this, int at)
{

#ifdef DEBUG
  if (at > this->__len OR at < 0)
      raise("Invalid index");
#endif
  return this->__str[at];
}

static String	*add(String *this, String *other)
{
  String	*out;

  out = newString(this->__str);
  MALLOC(out->__str, sizeof(char) * (this->__len + other->__len));
  strcpy(out->__str, this->__str);
  strcat(out->__str, other->__str);
  out->__len AS strlen(out->__str);
  return (out);
}