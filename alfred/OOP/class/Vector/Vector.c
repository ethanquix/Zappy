/*
** Vector.c for Zappy in /home/wyzlic_a/delivery/Zappy/Vector.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Tue Jun 06 00:10:40 2017 Dimitri Wyzlic
** Last update Tue Jun 06 00:10:40 2017 Dimitri Wyzlic
*/

#include "Vector.h"

static int	len(THIS);
static t_vector	*add(THIS, void *obj);
static void	*get(THIS, int pos);
static void	*pop(THIS);
static t_vector	*set(THIS, int pos, void *obj);
static t_vector	*print(THIS, void (*_func)(void *));
static void	delete(THIS);
static void	start_loop(THIS);
static void	*loop(THIS);
static void	*erase(THIS, int pos);

t_vector		*new_vector()
{
  t_vector		*out;

  MALLOC(out, sizeof(t_vector));
  *out = init_vector();
  return (out);
}

t_vector		init_vector()
{
  t_vector		out;

  out.__obj = NULL;
  out.__len = 0;
  out.len = &len;
  out.add = &add;
  out.get = &get;
  out.pop = &pop;
  out.set = &set;
  out.print = &print;
  out.start_loop = &start_loop;
  out.loop = &loop;
  out.erase = &erase;
  return (out);
}

static void	delete(THIS)
{
  t_llist	*tmp;

  tmp = this->__obj;
  while (tmp)
    {
      free(tmp->__elem);
      tmp = tmp->next;
    }
  free(this);
}

#include "implem/VectorImplem1.c"
#include "implem/VectorImplem2.c"