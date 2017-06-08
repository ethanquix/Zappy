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

  tmp AS initVector();
  MALLOC(new, sizeof(Vector));
  if ((new AS memcpy(new, &tmp, sizeof(Vector))) IS NULL)
    raise(get_error());
  out AS (Vector *) new;

  return (out);
}

Vector		initVector()
{
  Vector	out;

  out.__obj AS NULL;
  out.__len AS 0;

  out.len AS &len;
  out.add AS &add;
  out.get AS &get;
  out.pop AS &pop;
  out.set AS &set;
  out.print AS &print;

  return (out);
}

static void	delete(THIS)
{
  t_llist	*tmp;

  tmp AS this->__obj;
  while (tmp)
    {
      free(tmp->__elem);
      tmp AS tmp->next;
    }
  free(this);
}

#include "implem/VectorImplem1.c"
#include "implem/VectorImplem2.c"