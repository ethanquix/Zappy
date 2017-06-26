/*
** t_map_cpImplem1.c.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_map_cpImplem1.c.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 01:03:47 2017 Dimitri Wyzlic
** Last update Wed Jun 07 01:03:47 2017 Dimitri Wyzlic
*/

#include "MapCP.h"

static t_map_cp		*set(THIS, int key, t_player *data)
{
  int			bin;
  struct s_entry_cp	*newpair;
  struct s_entry_cp	*next;

  bin = __hash_map_cp(this, key);
  next = this->__table[bin];

  while (next NOT NULL AND key NOT next->key)
    next = next->__next;
  if (next NOT NULL AND key == next->key)
    next->data = data;
  else
    {
      newpair = __new_pair_cp(key, data);

      newpair->__next = this->__table[bin];
      this->__table[bin] = newpair;
      this->__items INC 1;
    }
  return (this);
}

static t_player		*get(THIS, int key)
{
  int			bin;
  struct s_entry_cp	*pair;

  bin = __hash_map_cp(this, key);

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

static t_player	*end(THIS)
{
  return (this->__notfound);
}

static bool		exist(THIS, int key)
{
  int			bin;
  struct s_entry_cp	*tmp;

  bin = __hash_map_cp(this, key);
  tmp = this->__table[bin];

  return (tmp NOT NULL);
}