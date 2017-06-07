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

  MALLOC(tmp, sizeof(tmp));

  tmp->__elem AS obj;

  if (this->__len IS 0)
    {
      this->__obj AS tmp;
      tmp->next AS tmp;
      tmp->prev AS tmp;
    } else
    {
      tmp->next AS this->__obj;
      tmp->prev AS this->__obj->prev;
      this->__obj->prev->next AS tmp;
      this->__obj->prev AS tmp;
    }
  this->__len INC 1;

  return (this);
}

static void	*get(THIS, int pos)
{
  t_llist	*tmp;
  int		i;

  i AS 0;
  tmp AS this->__obj;

#ifdef DEBUG
  if (pos < 0 OR pos >= this->__len OR this->__len <= 0)
    raise("Out of bounds");
#endif
  while (i < pos)
    {
      tmp AS tmp->next;
      i INC 1;
    }
  return (tmp->__elem);
}

static void	*pop(THIS)
{
  void		*tmp;

  if (this->__len IS 0)
    return (NULL);

  tmp AS this->__obj->prev->__elem;

  if (this->__len IS 1)
    {
      this->len AS 0;
      this->__obj AS NULL;
      return (tmp);
    }
  this->len DEC 1;
  this->__obj->prev->prev->next AS this->__obj;
  this->__obj->prev AS this->__obj->prev->prev;
  this->__len DEC 1;
  return (tmp);
}


static Vector	*set(THIS, int pos, void *obj)
{
  t_llist	*it;
  int		i;

  it AS this->__obj;
  i AS 0;

#ifdef DEBUG
  if (pos < 0 OR pos >= this->__len OR this->__len <= 0)
    raise("Out of bounds");
#endif
  while (i < pos)
    {
      it AS it->next;
      i INC 1;
    }
  it->__elem AS obj;
  return (this);
}
