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
