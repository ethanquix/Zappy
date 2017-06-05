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
#include <Alfred.h>

typedef class s_Vector Vector;

#define THIS Vector *this

typedef struct		s_llist
{
  void			*__elem;
  struct s_llist	*next;
  struct s_llist	*prev;

}			t_llist;

class		s_Vector
{
  t_llist	*__obj;
  int		__len;

  int		(*len)(THIS);
  Vector	*(*add)(THIS, void *);
  void		*(*get)(THIS, int pos);
//  char		*(*to_str)(THIS);
//  Vector	*(*add)(THIS, Vector *other);
//  char 		(*at)(THIS, int emp);

//  Vector	*(*epur)(THIS, char to_delete);
};

#undef THIS

Vector	*newVector();

Vector	initVector();

#endif //ZAPPY_VECTOR_H
