/*
** t_map_cpImplem2.c.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_map_cpImplem2.c.c
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

static PAIR_CP		*loop(THIS)
{
  PAIR_CP		*out;

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


static t_map_cp		*print(THIS, void (*_func)(PAIR_CP *pair))
{
  int			bckpIt;
  PAIR_CP		*bckpP;
  PAIR_CP		*it;

  bckpIt = this->__currentIt;
  bckpP = this->__currentEntry;

  this->start_loop(this);
  while ((it = this->loop(this)) NOT NULL)
    (*_func)(it);

  this->__currentEntry = bckpP;
  this->__currentIt = bckpIt;
  return (this);
}

static t_map_cp		*erase(THIS, int key)
{
  int			bin;
  struct s_entry_cp	*pair;

  if (this->exist(this, key) == false)
    RAISE("Can't erase because don'key exist");

  this->__items -= 1;
  bin = __hash_map_cp(this, key);
  pair = this->__table[bin];

  if (key == pair->key)
    {
      if (pair->__next NOT NULL)
	this->__table[bin] = pair->__next;
      else
	this->__table[bin] = NULL;
      return (this);
    }

  while (pair->__next NOT NULL AND key NOT pair->__next->key)
    pair = pair->__next;

  if (pair->__next NOT NULL)
    pair->__next = pair->__next->__next;

  return (this);
}