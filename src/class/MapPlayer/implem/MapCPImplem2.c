/*
** MapCPImplem2.c.c for Zappy in /home/wyzlic_a/delivery/Zappy/MapCPImplem2.c.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 16:17:26 2017 Dimitri Wyzlic
** Last update Wed Jun 07 16:17:26 2017 Dimitri Wyzlic
*/

#include "MapCP.h"

static void		start_loop(THIS)
{
  this->__currentIt = 0;
  this->__currentEntry = NULL;

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

static PairCP		*loop(THIS)
{
  PairCP		*out;

  while (this->__currentIt < this->__size)
    {
      if (this->__currentEntry NOT NULL)
	{
	  out = this->__currentEntry;
	  this->__currentEntry = this->__currentEntry->__next;
	  return (out);
	}
      this->__currentIt INC 1;
      if (this->__currentIt < this->__size)
	this->__currentEntry = this->__table[this->__currentIt];
    }
  return (NULL);
}


static MapCP		*print(THIS, void (*_func)(PairCP *pair))
{
  int			bckpIt;
  PairCP		*bckpP;
  PairCP		*it;

  bckpIt = this->__currentIt;
  bckpP = this->__currentEntry;

  this->start_loop(this);
  while ((it = this->loop(this)) NOT NULL)
    (*_func)(it);

  this->__currentEntry = bckpP;
  this->__currentIt = bckpIt;
  return (this);
}