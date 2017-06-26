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

typedef CLASS s_MapCP MapCP;

#undef THIS
#define THIS MapCP *this

#define PairCP	struct s_entryCP

struct			s_entryCP
{
  int			key;
  t_player		*data;
  PairCP		*__next;
};

CLASS			s_MapCP
{
  int			__size;
  int			__items;
  t_player		*__notfound;
  PairCP		**__table;
  int			__currentIt;
  PairCP		*__currentEntry;

  MapCP			*(*set)(THIS, int key, t_player *data);
  t_player		*(*get)(THIS, int key);
  int			(*len)(THIS);
  t_player		*(*end)(THIS);
  bool			(*exist)(THIS, int key);
  PairCP		*(*loop)(THIS);
  void			(*start_loop)(THIS);
  MapCP			*(*print)(THIS, void (*_func)(PairCP *pair));
  void			(*delete)(THIS);
  MapCP			*(*erase)(THIS, int key);
};

MapCP			*newMapCP(int size, t_player *end);
MapCP			initMapCP(int size, t_player *end);
int			__hash_MapCP(THIS, int key);
PairCP			*__newPairCP(int key, t_player *val);

#endif //ZAPPY_MAPCP_H
