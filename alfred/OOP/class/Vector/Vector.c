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


Vector		*newVector()
{
  void		*new;
  Vector	tmp;
  Vector	*out;

  tmp = initVector();
  MALLOC(new, sizeof(Vector));
  if ((new = memcpy(new, &tmp, sizeof(Vector))) IS NULL)
    raise(get_error());
  out = (Vector *) new;

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