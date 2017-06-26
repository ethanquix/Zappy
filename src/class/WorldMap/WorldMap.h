/*
** t_worldmap.h for Zappy in /home/wyzlic_a/delivery/Zappy/t_worldmap.h
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

#undef THIS
#define THIS struct s_worldmap *this

typedef CLASS		s_worldmap
{
  int			width;
  int			height;
  t_inv			**tiles;
  void			(*delete)(THIS);
}			t_worldmap;

t_worldmap		*new_world_map(int width, int height);
t_worldmap		init_world_map(int width, int height);

#endif //ZAPPY_WORLDMAP_H
