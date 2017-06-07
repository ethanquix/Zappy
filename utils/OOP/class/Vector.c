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

static int	len(Vector *this);
static Vector	*add(Vector *this, void *obj);
static void	*get(Vector *this, int pos);
static void	*pop(Vector *this);
static Vector	*set(Vector *this, int pos, void *obj);
static Vector	*print(Vector *this, void (*_func)(void *));


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

#include "implem/VectorImplem1.c"
#include "implem/VectorImplem2.c"