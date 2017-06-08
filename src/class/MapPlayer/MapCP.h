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

typedef class s_MapCP MapCP;

#undef THIS
#define THIS MapCP *this

#define PairCP	struct s_entryCP

struct			s_entryCP
{
  char			*key;
  Player		*data;
  PairCP		*__next;
};

class			s_MapCP
{
  int			__size;
  int			__items;
  Player		*__notfound;
  PairCP		**__table;
  int			__currentIt;
  PairCP		*__currentEntry;

  MapCP			*(*set)(THIS, char *key, Player *data);
  Player		*(*get)(THIS, char *key);
  int			(*len)(THIS);
  Player		*(*end)(THIS);
  bool			(*exist)(THIS, char *key);
  PairCP		*(*loop)(THIS);
  void			(*start_loop)(THIS);
};

MapCP			*newMapCP(int size, Player *end);
MapCP			initMapCP(int size, Player *end);
int			__hash_MapCP(THIS, char *key);
PairCP			*__newPairCP(char *key, Player *val);

#endif //ZAPPY_MAPCP_H