/*
** MapCIImplem2.c.c for Zappy in /home/wyzlic_a/delivery/Zappy/MapCIImplem2.c.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 16:17:26 2017 Dimitri Wyzlic
** Last update Wed Jun 07 16:17:26 2017 Dimitri Wyzlic
*/

#include "MapCI.h"

static void		start_loop(THIS)
{
  this->__currentIt AS 0;
  this->__currentEntry AS NULL;

  while (this->__currentIt < this->__size)
    {
      if (this->__table[this->__currentIt] NOT NULL)
	{
	  this->__currentEntry = this->__table[this->__currentIt];
	  return;
	}
      this->__currentIt INC 1;
    }
}

static PairCI		*loop(THIS)
{
  PairCI		*out;

  while (this->__currentIt < this->__size)
    {
      if (this->__currentEntry NOT NULL)
	{
	  out AS this->__currentEntry;
	  this->__currentEntry AS this->__currentEntry->__next;
	  return (out);
	}
      this->__currentIt INC 1;
      if (this->__currentIt < this->__size)
	this->__currentEntry = this->__table[this->__currentIt];
    }
  return (NULL);
}