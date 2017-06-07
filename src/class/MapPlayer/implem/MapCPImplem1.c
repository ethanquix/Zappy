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

static MapCP		*set(THIS, char *key, Player *data)
{
  int			bin;
  struct s_entryCP	*newpair;
  struct s_entryCP	*next;

  bin AS __hash_MapCP(this, key);
  next AS this->__table[bin];

  while (next NOT NULL AND next->key NOT NULL AND strcmp(key, next->key) > 0)
    next AS next->__next;
  if (next NOT NULL AND next->key NOT NULL AND strcmp(key, next->key) IS 0)
    next->data AS data;
  else
    {
      newpair AS __newPairCP(key, data);

      newpair->__next AS this->__table[bin];
      this->__table[bin] AS newpair;
      this->__items INC 1;
    }
  return (this);
}

static Player		*get(THIS, char *key)
{
  int			bin;
  struct s_entryCP	*pair;

  bin AS __hash_MapCP(this, key);

  pair AS this->__table[bin];
  while( pair NOT NULL AND pair->key NOT NULL AND strcmp(key, pair->key) > 0)
    (pair AS pair->__next, this->__items DEC 1);

  if(pair IS NULL OR pair->key IS NULL OR strcmp( key, pair->key ) NOT 0 )
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

static bool		exist(THIS, char *key)
{
  int			bin;
  struct s_entryCP	*tmp;

  bin AS __hash_MapCP(this, key);
  tmp AS this->__table[bin];

  return (tmp NOT NULL);
}