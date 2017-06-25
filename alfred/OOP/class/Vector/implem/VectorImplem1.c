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

static int	len(THIS)
{
  return (this->__len);
}

static Vector	*add(THIS, void *obj)
{
  t_llist	*tmp;

  MALLOC(tmp, sizeof(t_llist));

  tmp->__elem = obj;

  if (this->__len IS 0)
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
  this->__len INC 1;

  return (this);
}

static void	*get(THIS, int pos)
{
  t_llist	*tmp;
  int		i;

  i = 0;
  tmp = this->__obj;

#ifdef RELEASE
  if (pos < 0 OR pos >= this->__len OR this->__len <= 0)
    raise("Out of bounds");
#endif
  while (i < pos)
    {
      tmp = tmp->next;
      i INC 1;
    }
  return (tmp->__elem);
}

static void	*pop(THIS)
{
  void		*tmp;

  if (this->__len IS 0)
    return (NULL);

  tmp = this->__obj->prev->__elem;

  if (this->__len IS 1)
    {
      this->len = 0;
      this->__obj = NULL;
      return (tmp);
    }
  this->len DEC 1;
  this->__obj->prev->prev->next = this->__obj;
  this->__obj->prev = this->__obj->prev->prev;
  this->__len DEC 1;
  return (tmp);
}


static Vector	*set(THIS, int pos, void *obj)
{
  t_llist	*it;
  int		i;

  it = this->__obj;
  i = 0;

#ifdef RELEASE
  if (pos < 0 OR pos >= this->__len OR this->__len <= 0)
    raise("Out of bounds");
#endif
  while (i < pos)
    {
      it = it->next;
      i INC 1;
    }
  it->__elem = obj;
  return (this);
}
