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

static t_response	*place_obj(THIS, Player *player, t_mineral mineral)
{
  t_response		*out;

  MALLOC(out, sizeof(t_response));
  out->name = player->name;
  if (player->inv.loot[mineral] > 0)
    {
      out->msg = newString("ok");
      this->map->tiles[player->position.y][player->position.x].loot[mineral] = player->inv.loot[mineral];
      player->inv.loot[mineral] = 0;
    }
  else
    out->msg = newString("ko");
  return (out);
}
