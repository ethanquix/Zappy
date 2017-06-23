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

typedef CLASS s_MapCI MapCI;

#undef THIS
#define THIS MapCI *this

#define PairCI	struct s_entryCI

struct			s_entryCI
{
  char			*key;
  int			data;
  PairCI		*__next;
};

CLASS			s_MapCI
{
  int			__size;
  int			__items;
  int			__notfound;
  PairCI		**__table;
  int			__currentIt;
  PairCI		*__currentEntry;

  MapCI			*(*set)(THIS, char *key, int data);
  int			(*get)(THIS, char *key);
  int			(*len)(THIS);
  int			(*end)(THIS);
  bool			(*exist)(THIS, char *key);
  PairCI		*(*loop)(THIS);
  void			(*start_loop)(THIS);
  MapCI			*(*print)(THIS, void (*_func)(PairCI *pair));
  void			(*delete)(THIS);
  MapCI			*(*erase)(THIS, char *key);
};

MapCI			*newMapCI(int size, int nof);
MapCI			initMapCI(int size, int nof);
int			__hash_MapCI(THIS, char *key);
PairCI			*__newPairCI(char *key, int val);

#endif //ZAPPY_MAPINTERFACE_H
