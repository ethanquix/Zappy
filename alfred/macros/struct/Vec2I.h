/*
** t_vec_ii.h for Zappy in /home/wyzlic_a/delivery/Zappy/t_vec_ii.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 17:38:27 2017 Dimitri Wyzlic
** Last update Wed Jun 07 17:38:27 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_VEC2I_H
#define ZAPPY_VEC2I_H

typedef struct	s_vec2I
{
  int		x;
  int		y;
}		t_vec_ii;

t_vec_ii		rand_pos(int minx, int miny, int maxx, int maxy);

#endif //ZAPPY_VEC2I_H
