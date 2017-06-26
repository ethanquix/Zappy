/*
** MapInterface.h for Zappy in /home/wyzlic_a/delivery/Zappy/MapInterface.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Tue Jun 06 22:52:30 2017 Dimitri Wyzlic
** Last update Tue Jun 06 22:52:30 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_MAPCP_H
#define ZAPPY_MAPCP_H

#include "Alfred.h"
#include "Player.h"

typedef CLASS s_map_cp t_map_cp;

#undef THIS
#define THIS t_map_cp *this

#define PAIR_CP	struct s_entry_cp

struct			s_entry_cp
{
  int			key;
  t_player		*data;
  PAIR_CP		*__next;
};

typedef CLASS		s_map_cp
{
  int			__size;
  int			__items;
  t_player		*__notfound;
  PAIR_CP		**__table;
  int			__currentIt;
  PAIR_CP		*__currentEntry;

  t_map_cp		*(*set)(THIS, int key, t_player *data);
  t_player		*(*get)(THIS, int key);
  int			(*len)(THIS);
  t_player		*(*end)(THIS);
  bool			(*exist)(THIS, int key);
  PAIR_CP		*(*loop)(THIS);
  void			(*start_loop)(THIS);
  t_map_cp		*(*print)(THIS, void (*_func)(PAIR_CP *pair));
  void			(*delete)(THIS);
  t_map_cp		*(*erase)(THIS, int key);
}			t_map_cp;

t_map_cp			*new_map_cp(int size, t_player *end);
t_map_cp			init_map_cp(int size, t_player *end);
int			__hash_map_cp(THIS, int key);
PAIR_CP			*__new_pair_cp(int key, t_player *val);

#endif //ZAPPY_MAPCP_H
