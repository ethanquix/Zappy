/*
** MapCPImplem1.c.c for Zappy in /home/wyzlic_a/delivery/Zappy/MapCPImplem1.c.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 01:03:47 2017 Dimitri Wyzlic
** Last update Wed Jun 07 01:03:47 2017 Dimitri Wyzlic
*/

#include "MapCP.h"

static MapCP		*set(THIS, int key, Player *data)
{
  int			bin;
  struct s_entryCP	*newpair;
  struct s_entryCP	*next;

  bin = __hash_MapCP(this, key);
  next = this->__table[bin];

  while (next NOT NULL AND key NOT next->key)
    next = next->__next;
  if (next NOT NULL AND key == next->key)
    next->data = data;
  else
    {
      newpair = __newPairCP(key, data);

      newpair->__next = this->__table[bin];
      this->__table[bin] = newpair;
      this->__items INC 1;
    }
  return (this);
}

static Player		*get(THIS, int key)
{
  int			bin;
  struct s_entryCP	*pair;

  bin = __hash_MapCP(this, key);

  pair = this->__table[bin];
  while (pair NOT NULL AND key NOT pair->key)
    pair = pair->__next;

  if (pair IS NULL OR key NOT pair->key)
      return (this->__notfound);
  return (pair->data);
}

static int	len(THIS)
{
  return (this->__items);
}

static Player	*end(THIS)
{
  return (this->__notfound);
}

static bool		exist(THIS, int key)
{
  int			bin;
  struct s_entryCP	*tmp;

  bin = __hash_MapCP(this, key);
  tmp = this->__table[bin];

  return (tmp NOT NULL);
}