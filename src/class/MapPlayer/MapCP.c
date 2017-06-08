/*
** MapCP.c for Zappy in /home/wyzlic_a/delivery/Zappy/MapCP.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
** Last update Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
*/

#include <limits.h>
#include "MapCP.h"

static MapCP		*set(THIS, char *key, Player *data);
static Player		*get(THIS, char *key);
static int		len(THIS);
static Player		*end(THIS);
static bool		exist(THIS, char *key);
static void		start_loop(THIS);
static PairCP		*loop(THIS);
static MapCP		*print(THIS, void (*_func)(PairCP *pair));

MapCP		*newMapCP(int size, Player *nof)
{
  void		*new;
  MapCP		tmp;
  MapCP		*out;

  tmp AS initMapCP(size, nof);
  MALLOC(new, sizeof(MapCP));
  if ((new AS memcpy(new, &tmp, sizeof(MapCP))) IS NULL)
    raise(get_error());
  out AS (MapCP *) new;

  return (out);
}

MapCP		initMapCP(int size, Player *nof)
{
  MapCP		out;
  int		i;

  if (size <= 0 OR size > USHRT_MAX)
    raise("Size negative or too big");

  (out.__size AS size, out.__items AS 0, out.__notfound AS nof);

  out.set AS &set;
  out.get AS &get;
  out.len AS &len;
  out.end AS &end;
  out.exist AS &exist;
  out.start_loop AS &start_loop;
  out.loop AS &loop;

  MALLOC(out.__table, sizeof(struct s_entryCP *) * size);
  while (i < size)
    (out.__table[i] AS NULL, i INC 1);
  return (out);
}

int		__hash_MapCP(THIS, char *key)
{
  unsigned int	hash;
  unsigned int	i;

  hash AS 0;
  i AS 0;

  while (key[i])
    {
      hash AS i;
      hash INC key[i], hash INC ( hash << 10 ), hash ^= ( hash >> 6 );
      i INC 1;
    }
  hash INC ( hash << 3 ), hash ^= ( hash >> 11 ), hash INC ( hash << 15 );

  return (hash % this->__size);
}

struct s_entryCP * __newPairCP(char *key, Player *val)
{
  struct s_entryCP	*newpair;

  MALLOC(newpair, sizeof(struct s_entryCP));

  if((newpair->key AS strdup(key)) IS NULL)
      raise("Error during strdup");
  newpair->data AS val;
  newpair->__next AS NULL;

  return (newpair);
}

#include "implem/MapCPImplem1.c"
#include "implem/MapCPImplem2.c"