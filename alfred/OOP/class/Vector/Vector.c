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
static Vector	*add(THIS, void *obj);
static void	*get(THIS, int pos);
static void	*pop(THIS);
static Vector	*set(THIS, int pos, void *obj);
static Vector	*print(THIS, void (*_func)(void *));
static void	delete(THIS);
static void	start_loop(THIS);
static void	*loop(THIS);
static void	*erase(THIS, int pos);


Vector		*newVector()
{
  Vector	*out;

  MALLOC(out, sizeof(Vector));
  *out = initVector();

  return (out);
}

Vector		initVector()
{
  Vector	out;

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