/*
** t_map_ci.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_map_ci.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
** Last update Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
*/

#include <limits.h>
#include "MapCI.h"

static t_map_ci		*set(THIS, char *key, int data);
static int		get(THIS, char *key);
static int		len(THIS);
static int		end(THIS);
static bool		exist(THIS, char *key);
static void		start_loop(THIS);
static PAIR_CI		*loop(THIS);
static t_map_ci		*print(THIS, void (*_func)(PAIR_CI *pair));
static void		delete(THIS);
static t_map_ci		*erase(THIS, char *key);

t_map_ci		*new_map_ci(int size, int nof)
{
  t_map_ci		*out;

  MALLOC(out, sizeof(t_map_ci));
  *out = init_map_ci(size, nof);
  return (out);
}

t_map_ci		init_map_ci(int size, int nof)
{
  t_map_ci		out;
  int		i;

  i = 0;
  if (size <= 0 OR size > USHRT_MAX)
    RAISE("Size negative or too big");
  out.__size = size;
  out.__items = 0;
  out.__notfound = nof;
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
  MALLOC(out.__table, sizeof(struct s_entry_ci *) * size);
  while (i < size)
    out.__table[i++] = NULL;
  return (out);
}

int		__hash_map_ci(THIS, char *key)
{
  unsigned int	hash;
  unsigned int	i;

  hash = 0;
  i = 0;
  while (key[i])
    {
      hash = i;
      hash INC key[i];
      hash INC ( hash << 10 );
      hash ^= ( hash >> 6 );
      i INC 1;
    }
  hash INC ( hash << 3 );
  hash ^= ( hash >> 11 );
  hash INC ( hash << 15 );
  return (hash % this->__size);
}

struct s_entry_ci	*__new_pair_ci(char *key, int val)
{
  struct s_entry_ci	*newpair;

  MALLOC(newpair, sizeof(struct s_entry_ci));
  if((newpair->key = strdup(key)) IS NULL)
      RAISE("Error during strdup");
  newpair->data = val;
  newpair->__next = NULL;
  return (newpair);
}

static void		delete(THIS)
{
  struct s_entry_ci	**tmp;
  struct s_entry_ci	*tmp2;
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