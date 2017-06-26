/*
** Vec2I.c for Zappy in /home/wyzlic_a/delivery/Zappy/Vec2I.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 26 04:20:41 2017 Dimitri Wyzlic
** Last update Mon Jun 26 04:20:41 2017 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "Vec2I.h"

t_vec2I		rand_pos(int minx, int miny, int maxx, int maxy)
{
  t_vec2I	out;

  out.x = (rand() % (maxx + 1 - minx)) + minx;
  out.y = (rand() % (maxy + 1 - miny)) + miny;
  return (out);
}