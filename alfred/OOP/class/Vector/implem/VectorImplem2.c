/*
** VectorImplem.c for Zappy in /home/wyzlic_a/delivery/Zappy/VectorImplem.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Tue Jun 06 17:29:08 2017 Dimitri Wyzlic
** Last update Tue Jun 06 17:29:08 2017 Dimitri Wyzlic
*/

#include "Vector.h"

static t_vector	*print(THIS, void (*_func)(void *))
{
  int		i;
  t_llist	*it;

  i = 0;
  it = this->__obj;
  printf("Vector -> len: %d\tData:\n", this->__len);
  if (this->__len IS 0)
    {
      printf("EMPTY\n");
      return (this);
    }
  while (i NOT this->__len)
    {
      (*_func)(it->__elem);
      it = it->next;
      i INC 1;
    }
  printf("End Vector\n");
  return (this);
}

static void	start_loop(THIS)
{
  this->__cursor = 0;
}

static void	*loop(THIS)
{
  if (this->__cursor >= this->__len || this->__len == 0)
    return (NULL);
  this->__cursor += 1;
  return (this->get(this, this->__cursor - 1));
}

static void	*erase(THIS, int pos)
{
  t_llist	*it;
  int		i;

  i = 0;
  if (this->__len IS 0 || pos > this->__len)
    return (NULL);
  it = this->__obj;
  while (it->next &&  i < pos - 1)
    {
      i += 1;
      it = it->next;
    }
  if (it->next == NULL)
    return (this);
  it->next = it->next->next;
  it->next->prev = it;
  this->__len -= 1;
  return (this);
}