/*
** t_worldmap.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_worldmap.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Thu Jun 08 22:45:22 2017 Dimitri Wyzlic
** Last update Thu Jun 08 22:45:22 2017 Dimitri Wyzlic
*/

#include "WorldMap.h"

t_inv	*init_row(int width);

static void	delete(THIS);

t_worldmap		*new_world_map(int width, int height)
{
  t_worldmap		*out;

  MALLOC(out, sizeof(t_worldmap));
  *out = init_world_map(width, height);

  return (out);
}

t_worldmap		init_world_map(int width, int height)
{
  t_worldmap		map;
  int			i;

  map.delete = &delete;

  i = 0;
  map.width = width;
  map.height = height;
  MALLOC(map.tiles, sizeof(t_inv *) * height);
  while (i < height)
    {
      map.tiles[i] = init_row(width);
      i INC 1;
    }
  return (map);
}

t_inv	*init_row(int width)
{
  t_inv	*out;
  int		i;

  i = 0;
  MALLOC(out, sizeof(t_inv) * width);
  while (i < width)
    {
      random_inv(&(out[i]));
      i INC 1;
    }
  return (out);
}

static void	delete(THIS)
{
  int		i;

  i = 0;
  while (i < this->height)
    free(this->tiles[i++]);
  free(this->tiles);
  free(this);
}