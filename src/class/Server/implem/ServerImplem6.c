/*
** t_serverImplem6.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_serverImplem6.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 26 13:05:50 2017 Dimitri Wyzlic
** Last update Mon Jun 26 13:55:56 2017 Doom
*/

#include "Server.h"

typedef struct	s_levelup
{
  int		player;
  int		mineral[7];
}		t_levelup;

static const t_levelup	levelup_need[] =
  {
    {1, {1, 0, 0, 0, 0, 0}},
    {2, {1, 1, 1, 0, 0, 0}},
    {2, {2, 0, 1, 0, 2, 0}},
    {4, {1, 1, 2, 0, 1, 0}},
    {4, {1, 2, 1, 3, 0, 0}},
    {6, {1, 2, 3, 0, 1, 0}},
    {6, {2, 2, 2, 2, 2, 1}},
  };

static int	count_player_on_tile(THIS, t_vec_ii pos)
{
  int		out;
  PAIR_CP	*it;

  out = 0;
  this->players->start_loop(this->players);
  while ((it = this->players->loop(this->players)) != NULL)
    {
      if (((t_player *)it)->position.x == pos.x && ((t_player *)it)->position.y == pos.y)
	out += 1;
    }
  return (out);
}

static bool	check_levelup(THIS, t_player *player)
{
  int		i;

  i = 0;
  if (player->level > 7)
    return (false);
  if (count_player_on_tile(this, player->position) != levelup_need[player->level - 1].player)
    return (false);
  while (i < MAX_MINERAL)
    {
      if (this->map->tiles[player->position.y][player->position.x].loot[i] != levelup_need[player->level - 1].mineral[i])
	return (false);
	  i += 1;
    }
  return (true);
}

static bool		check_time(THIS)
{
  double		current_ms;
  struct timespec	spec;
  double		diff;
  double		current_s;

  clock_gettime(CLOCK_REALTIME, &spec);
  current_s = spec.tv_sec;
  current_ms = ((round(spec.tv_nsec / 1.0e6) + (current_s * 1000))) / 1000;
  diff = (current_ms - this->ms) * 1000;
  if (diff != 0 && diff >= this->cur_div)
    {
      this->ms = current_ms;
      return (true);
    }
  return (false);
}

static bool		calc_food(THIS, t_player *player)
{
  if (DISABLE_FOOD)
    return (false);
  if (player->team == NULL)
    return (false);
  if (player->cur_food_loss -= 1 <= 0)
    {
      player->inv.loot[FOOD] -= 1;
      player->cur_food_loss = FOOD_LOSS;
    }
  if (player->inv.loot[FOOD] <= 0)
    return (true);
  return (false);
}

static t_server		*death(THIS, t_player *player)
{
  int			ti;

  if (player->team != NULL)
    {
      ti = this->team_index->get(this->team_index, player->team->__str);
      this->teams[ti]->current_nb_player -= 1;
    }
  dprintf(player->fd, "death\n");
  this->players->erase(this->players, player->fd);
  player->delete(player);
  return (this);
}