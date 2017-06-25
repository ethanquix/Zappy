/*
** StringImplem2.c for Zappy in /home/wyzlic_a/delivery/Zappy/StringImplem2.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 21:06:36 2017 Dimitri Wyzlic
** Last update Fri Jun 23 15:56:59 2017 Doom
*/

#include <time.h>
#include "String.h"

static String	*epur(THIS, char to_delete)
{
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  MALLOC(tmp, sizeof(char) * this->__len);
  while (this->__str[i])
    {
      if (this->__str[i] NOT to_delete)
	{
	  tmp[j] = this->__str[i];
	  j INC 1;
	}
      i INC 1;
    }
  tmp[j] = 0;
  return (newString(tmp));
}

static String	*random_string(THIS, size_t len)
{
  size_t	i;

  srand(time(NULL));
  i = 0;
  MALLOC(this->__str, sizeof(char) * (len + 1));
  static const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

  while (i < len)
    {

      this->__str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
      i += 1;
    }

  this->__str[len] = 0;
  return (this);
}
