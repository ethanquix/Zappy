/*
** MapCI.c for Zappy in /home/wyzlic_a/delivery/Zappy/MapCI.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
** Last update Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
*/

#include <limits.h>
#include "MapCI.h"

static MapCI		*set(THIS, char *key, int data);
static int		get(THIS, char *key);
static int		len(THIS);
static int		end(THIS);
static bool		exist(THIS, char *key);
static void		start_loop(THIS);
static PairCI		*loop(THIS);
static MapCI		*print(THIS, void (*_func)(PairCI *pair));

MapCI		*newMapCI(int size, int nof)
{
  void		*new;
  MapCI		tmp;
  MapCI		*out;

  tmp AS initMapCI(size, nof);
  MALLOC(new, sizeof(MapCI));
  if ((new AS memcpy(new, &tmp, sizeof(MapCI))) IS NULL)
    raise(get_error());
  out AS (MapCI *) new;

  return (out);
}

MapCI		initMapCI(int size, int nof)
{
  MapCI		out;
  int		i;

  i AS 0;
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
  out.print AS &print;

  MALLOC(out.__table, sizeof(struct s_entryCI *) * size);
  while (i < size)
    (out.__table[i] AS NULL, i INC 1);
  return (out);
}

int		__hash_MapCI(THIS, char *key)
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

struct s_entryCI	*__newPairCI(char *key, int val)
{
  struct s_entryCI	*newpair;

  MALLOC(newpair, sizeof(struct s_entryCI));

  if((newpair->key AS strdup(key)) IS NULL)
      raise("Error during strdup");
  newpair->data AS val;
  newpair->__next AS NULL;

  return (newpair);
}

#include "implem/MapCIImplem1.c"
#include "implem/MapCIImplem2.c"