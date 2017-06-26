/*
** MapInterface.h for Zappy in /home/wyzlic_a/delivery/Zappy/MapInterface.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Tue Jun 06 22:52:30 2017 Dimitri Wyzlic
** Last update Tue Jun 06 22:52:30 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_MAPINTERFACE_H
#define ZAPPY_MAPINTERFACE_H

#include "Alfred.h"

typedef CLASS s_map_ci t_map_ci;

#undef THIS
#define THIS t_map_ci *this

#define PAIR_CI	struct s_entry_ci

struct			s_entry_ci
{
  char			*key;
  int			data;
  PAIR_CI		*__next;
};

typedef CLASS		s_map_ci
{
  int			__size;
  int			__items;
  int			__notfound;
  PAIR_CI		**__table;
  int			__currentIt;
  PAIR_CI		*__currentEntry;

  t_map_ci			*(*set)(THIS, char *key, int data);
  int			(*get)(THIS, char *key);
  int			(*len)(THIS);
  int			(*end)(THIS);
  bool			(*exist)(THIS, char *key);
  PAIR_CI		*(*loop)(THIS);
  void			(*start_loop)(THIS);
  t_map_ci			*(*print)(THIS, void (*_func)(PAIR_CI *pair));
  void			(*delete)(THIS);
  t_map_ci			*(*erase)(THIS, char *key);
}			t_map_ci;

t_map_ci			*new_map_ci(int size, int nof);
t_map_ci			init_map_ci(int size, int nof);
int			__hash_map_ci(THIS, char *key);
PAIR_CI			*__new_pair_ci(char *key, int val);

#endif //ZAPPY_MAPINTERFACE_H
