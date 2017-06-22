/*
** MapCIImplem1.c.c for Zappy in /home/wyzlic_a/delivery/Zappy/MapCIImplem1.c.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 01:03:47 2017 Dimitri Wyzlic
** Last update Wed Jun 07 01:03:47 2017 Dimitri Wyzlic
*/

#include "MapCI.h"

static MapCI		*set(THIS, char *key, int data)
{
  int			bin;
  struct s_entryCI	*newpair;
  struct s_entryCI	*next;

  bin = __hash_MapCI(this, key);
  next = this->__table[bin];

  while (next NOT NULL AND next->key NOT NULL AND strcmp(key, next->key) > 0)
    next = next->__next;
  if (next NOT NULL AND next->key NOT NULL AND strcmp(key, next->key) IS 0)
    next->data = data;
  else
    {
      newpair = __newPairCI(key, data);

      newpair->__next = this->__table[bin];
      this->__table[bin] = newpair;
      this->__items INC 1;
    }
  return (this);
}

static int		get(THIS, char *key)
{
  int			bin;
  struct s_entryCI	*pair;

  bin = __hash_MapCI(this, key);

  pair = this->__table[bin];
  while (pair NOT NULL AND pair->key NOT NULL AND strcmp(key, pair->key) > 0)
    pair = pair->__next;

  if (pair IS NULL OR pair->key IS NULL OR strcmp( key, pair->key) NOT 0 )
      return (this->__notfound);
  return (pair->data);
}

static int	len(THIS)
{
  return (this->__items);
}

static int	end(THIS)
{
  return (this->__notfound);
}

static bool		exist(THIS, char *key)
{
  int			bin;
  struct s_entryCI	*tmp;

  bin = __hash_MapCI(this, key);
  tmp = this->__table[bin];

  return (tmp NOT NULL);
}