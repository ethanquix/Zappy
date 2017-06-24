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

static MapCP		*set(THIS, int key, Player *data);
static Player		*get(THIS, int key);
static int		len(THIS);
static Player		*end(THIS);
static bool		exist(THIS, int key);
static void		start_loop(THIS);
static PairCP		*loop(THIS);
static MapCP		*print(THIS, void (*_func)(PairCP *pair));
static void		delete(THIS);
static MapCP		*erase(THIS, int key);

MapCP		*newMapCP(int size, Player *nof)
{
  MapCP		*out;

  MALLOC(out, sizeof(MapCP));
  *out = initMapCP(size, nof);

  return (out);
}

MapCP		initMapCP(int size, Player *nof)
{
  MapCP		out;
  int		i;

  i = 0;
  if (size <= 0 OR size > USHRT_MAX)
    raise("Can't create Map: Size negative or too big");

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

  MALLOC(out.__table, sizeof(struct s_entryCP *) * size);
  while (i < size)
    (out.__table[i] = NULL, i INC 1);
  return (out);
}

int		__hash_MapCP(THIS, int key)
{
  return (key % this->__size);
}

struct s_entryCP * __newPairCP(int key, Player *val)
{
  struct s_entryCP	*newpair;

  MALLOC(newpair, sizeof(struct s_entryCP));

  newpair->key = key;
  newpair->data = val;
  newpair->__next = NULL;

  return (newpair);
}

static void		delete(THIS)
{
  struct s_entryCP	**tmp;
  struct s_entryCP	*tmp2;
  int			i;

  i = 0;
  tmp = this->__table;
  while (i < this->__size)
    {
      tmp2 = tmp[i];
      while (tmp2)
	{
	  tmp2->data->delete(tmp2->data);
	  tmp2 = tmp2->__next;
	}
      free(tmp[i]);
      i INC 1;
    }
  free(this->__table);
  free(this);
}

#include "implem/MapCPImplem1.c"
#include "implem/MapCPImplem2.c"