/*
** WorldMap.h for Zappy in /home/wyzlic_a/delivery/Zappy/WorldMap.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Thu Jun 08 19:38:06 2017 Dimitri Wyzlic
** Last update Thu Jun 08 19:38:06 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_WORLDMAP_H
#define ZAPPY_WORLDMAP_H

#include "inventory.h"
#include "String.h"
#include "MapCI.h"
#include "Alfred.h"

typedef CLASS s_WorldMap WorldMap;

#undef THIS
#define THIS WorldMap *this

CLASS			s_WorldMap
{
  int			width;
  int			height;
  Inventory		**tiles;

  void			(*delete)(THIS);
};

WorldMap		*newWorldMap(int width, int height);
WorldMap		initWorldMap(int width, int height);

#endif //ZAPPY_WORLDMAP_H
