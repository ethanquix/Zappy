/*
** t_vec_ii.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_vec_ii.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 26 04:20:41 2017 Dimitri Wyzlic
** Last update Mon Jun 26 04:20:41 2017 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "Vec2I.h"

t_vec_ii		rand_pos(int minx, int miny, int maxx, int maxy)
{
  t_vec_ii	out;

  out.x = (rand() % (maxx + 1 - minx)) + minx;
  out.y = (rand() % (maxy + 1 - miny)) + miny;
  return (out);
}