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


Vector		*newVector()
{
  void		*new;
  Vector	tmp;
  Vector	*out;

  tmp = initVector();
  if ((new = calloc(1, sizeof(Vector))) == NULL)
    raise(get_error());
  if ((new = memcpy(new, &tmp, sizeof(Vector))) == NULL)
    raise(get_error());
  out = (Vector *) new;

  return (out);
}

Vector		initVector()
{
  Vector	out;
//  t_llist	*l;

//  MALLOC(l, sizeof(t_llist));
  out.__obj = NULL;
  out.__len = 0;

  out.len = &len;
  out.add = &add;
  out.get = &get;
//  out.at = &at;
//  out.to_str = &to_str;
//  out.add = &add;
//  out.epur = &epur;
//
//  out.__str = str;
//  out.__len = strlen(str);

  return (out);
}

#include "implem/VectorImplem1.c"