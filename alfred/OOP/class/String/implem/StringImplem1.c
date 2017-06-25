/*
** StringImplem1.c for Zappy in /home/wyzlic_a/delivery/Zappy/StringImplem1.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 20:17:42 2017 Dimitri Wyzlic
** Last update Mon Jun 05 20:17:42 2017 Dimitri Wyzlic
*/

#include "String.h"

static int	len(THIS)
{
  return (this->__len);
}

static char	*val(THIS)
{
  return (this->__str);
}

static String	*print(THIS)
{
  printf("String -> value: %s\n", this->__str);
  return (this);
}

static char	at(THIS, int at)
{

#ifdef RELEASE
  if (at > this->__len OR at < 0)
      raise("Invalid index");
#endif
  return (this->__str[at]);
}

static String	*add(THIS, String *other)
{
  char		*tmp;

  MALLOC(tmp, sizeof(char) * (this->__len + other->__len + 1));
  printf("Other [%s]%d, this [%s]%d\n", other->__str, other->__len, this->__str, this->__len);
  strcpy(tmp, this->__str);
  strcat(tmp, other->__str);
  this->__str = tmp;
  this->__len = (int)strlen(this->__str);
  return (this);
}