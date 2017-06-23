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
static void		delete(THIS);
static MapCI		*erase(THIS, char *key);

MapCI		*newMapCI(int size, int nof)
{
  MapCI		*out;

  MALLOC(out, sizeof(MapCI));
  *out = initMapCI(size, nof);

  return (out);
}

MapCI		initMapCI(int size, int nof)
{
  MapCI		out;
  int		i;

  i = 0;
  if (size <= 0 OR size > USHRT_MAX)
    raise("Size negative or too big");

  (out.__size = size, out.__items = 0, out.__notfound = nof);

  out.set = &set;
  out.get = &get;
  out.len = &len;
  out.end = &end;
  out.exist = &exist;
  out.start_loop = &start_loop;
  out.loop = &loop;
  out.print = &print;
  out.delete = &delete;
  out.erase = &erase;

  MALLOC(out.__table, sizeof(struct s_entryCI *) * size);
  while (i < size)
    (out.__table[i] = NULL, i INC 1);
  return (out);
}

int		__hash_MapCI(THIS, char *key)
{
  unsigned int	hash;
  unsigned int	i;

  hash = 0;
  i = 0;

  while (key[i])
    {
      hash = i;
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

  if((newpair->key = strdup(key)) IS NULL)
      raise("Error during strdup");
  newpair->data = val;
  newpair->__next = NULL;

  return (newpair);
}

static void		delete(THIS)
{
  struct s_entryCI	**tmp;
  struct s_entryCI	*tmp2;
  int			i;

  i = 0;
  tmp = this->__table;
  while (i < this->__size)
    {
      tmp2 = tmp[i];
      while (tmp2)
	{
	  free(tmp2->key);
	  tmp2 = tmp2->__next;
	}
      free(tmp[i]);
      i INC 1;
    }
  free(this->__table);
  free(this);
}

#include "implem/MapCIImplem1.c"
#include "implem/MapCIImplem2.c"