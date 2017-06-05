/*
** VectorImplem1.c for Zappy in /home/wyzlic_a/delivery/Zappy/VectorImplem1.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Tue Jun 06 00:29:31 2017 Dimitri Wyzlic
** Last update Tue Jun 06 00:29:31 2017 Dimitri Wyzlic
*/

#include "Vector.h"

static int	len(Vector *this)
{
  return this->__len;
}

static Vector	*add(Vector *this, void *obj)
{
  t_llist	*tmp;

  MALLOC(tmp, sizeof(tmp));

  tmp->__elem = obj;

  if (this->__len == 0)
    {
      this->__obj = tmp;
      tmp->next = tmp;
      tmp->prev = tmp;
    } else
    {
      tmp->next = this->__obj;
      tmp->prev = this->__obj->prev;
      this->__obj->prev->next = tmp;
      this->__obj->prev = tmp;
    }
  this->__len += 1;

  return (this);
}

static void	*get(Vector *this, int pos)
{
  t_llist	*tmp;
  int		i;

  i = 0;
  tmp = this->__obj;

#ifdef DEBUG
  if (pos < 0 || pos >= this->__len || this->__len <= 0)
    raise("Out of bounds");
#endif
  while (i < pos)
    {
      tmp = tmp->next;
      i += 1;
    }
  return (tmp->__elem);
}