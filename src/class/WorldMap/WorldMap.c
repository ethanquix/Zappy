/*
** WorldMap.c for Zappy in /home/wyzlic_a/delivery/Zappy/WorldMap.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Thu Jun 08 22:45:22 2017 Dimitri Wyzlic
** Last update Thu Jun 08 22:45:22 2017 Dimitri Wyzlic
*/

#include "WorldMap.h"

Inventory	*init_row(int width);

static void	delete(THIS);

WorldMap		*newWorldMap(int width, int height)
{
  WorldMap		*out;

  MALLOC(out, sizeof(WorldMap));
  *out = initWorldMap(width, height);

  return (out);
}

WorldMap		initWorldMap(int width, int height)
{
  WorldMap		map;
  int			i;

  map.delete = &delete;

  i = 0;
  map.width = width;
  map.height = height;
  MALLOC(map.tiles, sizeof(Inventory *) * height);
  while (i < height)
    {
      map.tiles[i] = init_row(width);
      i INC 1;
    }
  return (map);
}

Inventory	*init_row(int width)
{
  Inventory	*out;
  int		i;

  i = 0;
  MALLOC(out, sizeof(Inventory) * width);
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