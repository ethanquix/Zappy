/*
** Vector.h for Zappy in /home/wyzlic_a/delivery/Zappy/Vector.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 23:48:43 2017 Dimitri Wyzlic
** Last update Mon Jun 05 23:48:43 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_VECTOR_H
#define ZAPPY_VECTOR_H

#include <stdlib.h>
#include <memory.h>
#include "Alfred.h"

#undef THIS
#define THIS struct s_vector *this

typedef struct		s_llist
{
  void			*__elem;
  struct s_llist	*next;
  struct s_llist	*prev;
}			t_llist;

typedef CLASS		s_vector
{
  t_llist		*__obj;
  int			__len;
  int			__cursor;
  int			(*len)(THIS);
  struct s_vector	*(*add)(THIS, void *);
  void			*(*get)(THIS, int pos);
  void			*(*pop)(THIS);
  struct s_vector	*(*set)(THIS, int pos, void *obj);
  struct s_vector	*(*print)(THIS, void (*_func)(void *));
  void			(*delete)(THIS);
  void			(*start_loop)(THIS);
  void			*(*loop)(THIS);
  void			*(*erase)(THIS, int pos);
}			t_vector;

t_vector	*new_vector();
t_vector	init_vector();

#endif //ZAPPY_VECTOR_H
