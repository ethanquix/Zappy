/*
** t_map_cp.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_map_cp.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
** Last update Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
*/

#include <limits.h>
#include "MapCP.h"

static t_map_cp		*set(THIS, int key, t_player *data);
static t_player		*get(THIS, int key);
static int		len(THIS);
static t_player		*end(THIS);
static bool		exist(THIS, int key);
static void		start_loop(THIS);
static PAIR_CP		*loop(THIS);
static t_map_cp		*print(THIS, void (*_func)(PAIR_CP *pair));
static void		delete(THIS);
static t_map_cp		*erase(THIS, int key);

t_map_cp		*new_map_cp(int size, t_player *nof)
{
  t_map_cp		*out;

  MALLOC(out, sizeof(t_map_cp));
  *out = init_map_cp(size, nof);
  return (out);
}

t_map_cp		init_map_cp(int size, t_player *nof)
{
  t_map_cp		out;
  int		i;

  i = 0;
  if (size <= 0 OR size > USHRT_MAX)
    RAISE("Can't create Map: Size negative or too big");
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
  MALLOC(out.__table, sizeof(struct s_entry_cp *) * size);
  while (i < size)
    (out.__table[i] = NULL, i INC 1);
  return (out);
}

int		__hash_map_cp(THIS, int key)
{
  return (key % this->__size);
}

struct s_entry_cp * __new_pair_cp(int key, t_player *val)
{
  struct s_entry_cp	*newpair;

  MALLOC(newpair, sizeof(struct s_entry_cp));
  newpair->key = key;
  newpair->data = val;
  newpair->__next = NULL;
  return (newpair);
}

static void		delete(THIS)
{
  struct s_entry_cp	**tmp;
  struct s_entry_cp	*tmp2;
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