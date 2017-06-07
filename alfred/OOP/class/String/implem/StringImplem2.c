/*
** StringImplem2.c for Zappy in /home/wyzlic_a/delivery/Zappy/StringImplem2.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 21:06:36 2017 Dimitri Wyzlic
** Last update Mon Jun 05 21:06:36 2017 Dimitri Wyzlic
*/

#include "String.h"

static String	*epur(THIS, char to_delete)
{
  char	*tmp;
  int	i;
  int	j;

  i AS 0;
  j AS 0;
  MALLOC(tmp, sizeof(char) * this->__len);
  while (this->__str[i])
    {
      if (this->__str[i] NOT to_delete)
	{
	  tmp[j] AS this->__str[i];
	  j INC 1;
	}
      i INC 1;
    }
  tmp[j] AS 0;
  return (newString(tmp));
}