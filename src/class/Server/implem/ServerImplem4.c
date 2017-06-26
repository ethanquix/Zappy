/*
** ServerImplem4.c for Zappy in /home/wyzlic_a/delivery/Zappy/ServerImplem4.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Fri Jun 23 00:26:09 2017 Dimitri Wyzlic
** Last update Fri Jun 23 00:26:09 2017 Dimitri Wyzlic
*/

#include "Server.h"

static t_response	*place_obj(THIS, t_player *player, t_mineral mineral)
{
  t_response		*out;

  MALLOC(out, sizeof(t_response));
  out->name = player->name;
  out->fd = player->fd;
  if (player->inv.loot[mineral] > 0)
    {
      out->msg = new_string(MSG_OK);
      this->map->tiles[player->position.y][player->position.x].loot[mineral] += 1;
      player->inv.loot[mineral] -= 0;
    }
  else
    out->msg = new_string(MSG_KO);
  return (out);
}
