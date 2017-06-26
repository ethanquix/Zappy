/*
** ServerImplem2.c for Zappy in /home/wyzlic_a/delivery/Zappy/ServerImplem2.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 21 15:31:38 2017 Dimitri Wyzlic
** Last update Wed Jun 21 15:31:38 2017 Dimitri Wyzlic
*/

#include "Server.h"

static int     check_direction_for_broadcast(int dir1, int dir2)
{
  if (dir1 == dir2)
    return 1;
  if (dir2 > dir1)
    return (dir2 - dir1 + 1);
  return (dir2 + 9) - dir1;
}

static int	search_dir(int dest_x, int dest_y)
{
  float	angle;

  if (dest_x == 0 && dest_y == 0)
    return (0);
  if (dest_x == 0)
    return ((dest_y > 0 ? 1 : 5));
  if (dest_y == 0)
      return ((dest_x > 0 ? 3 : 7));
  angle = atanf((float)ABS(dest_y) / (float)ABS(dest_x));
  if (angle < M_PI / 8.0f)
    return ((dest_x > 0) ? (3) : (7));
  if (angle < (3.0f * M_PI) / 8.0f)
    {
      if (dest_x > 0)
	return ((dest_y > 0) ? (2) : (4));
      return ((dest_y > 0) ? (8) : (6));
    }
  return ((dest_y > 0) ? (1) : (5));
}

static void	calc_coord(THIS, t_player *from, t_player *to, int *new_x, int *new_y)
{
  if (ABS(to->position.x - from->position.x) <
      ABS((to->position.x + this->map->width) - from->position.x))
    (*new_x) = to->position.x - from->position.x;
  else
    (*new_x) = (to->position.x + this->map->width) - from->position.x;
  if (ABS(to->position.y - from->position.y) <
      ABS((to->position.y + this->map->height) - from->position.y))
    (*new_y) = to->position.y - from->position.y;
  else
    (*new_y) = (to->position.y + this->map->height) - from->position.y;
}

static int	calc_coo(THIS, t_player *player, t_player *current)
{
  int     dir;
  int     x;
  int     y;

  calc_coord(this, player, current, &x, &y);
  dir = search_dir(x, y);
  return (check_direction_for_broadcast(current->direction, dir));
}

static t_response		*calc_sound(THIS, t_player *from, t_player *to, t_string *msg)
{
  t_response			*out;
  int				orientation;
  t_string			*orientation_str;
  char				*tmp;

  MALLOC(out, sizeof(t_response));
  MALLOC(tmp, 2);
  out->name = to->name;
  out->fd = to->fd;
  orientation = calc_coo(this, from, to);
  tmp[0] = (char) (orientation + '0');
  tmp[1] = 0;
  orientation_str = new_string(tmp);
  orientation_str->add(orientation_str, msg);
  out->msg = orientation_str;
  out->msg = msg;
}

static t_vector		*broadcast(THIS, t_player *player, t_string *msg)
{
  t_vector		*out;
  PairCP		*it;

  out = new_vector();
  this->players->start_loop(this->players);
  while ((it = this->players->loop(this->players)) != NULL)
    out->add(out, calc_sound(this, player, it->data, msg));
  return (out);
}