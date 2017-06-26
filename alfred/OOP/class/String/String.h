/*
** String.h for Zappy in /home/wyzlic_a/delivery/Zappy/String.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 14:38:22 2017 Dimitri Wyzlic
** Last update Mon Jun 05 14:38:22 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_STRING_H
#define ZAPPY_STRING_H

#include <stdlib.h>
#include <memory.h>
#include "Alfred.h"

#undef THIS
#define THIS struct s_string *this

typedef CLASS		s_string
{
  char			*__str;
  int			__len;
  int			(*len)(THIS);
  char			*(*get)(THIS);
  struct s_string	*(*print)(THIS);
  struct s_string	*(*add)(THIS, struct s_string *other);
  char 			(*at)(THIS, int emp);
  struct s_string	*(*epur)(THIS, char to_delete);
  struct s_string	*(*random_string)(THIS, size_t);
  void			(*delete)(THIS);
}			t_string;

t_string	*new_string(char *str);
t_string	init_string(char *str);

#endif //ZAPPY_STRING_H
