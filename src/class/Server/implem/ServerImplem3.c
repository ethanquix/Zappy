/*
** t_serverImplem3.c.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_serverImplem3.c.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Thu Jun 22 22:28:42 2017 Dimitri Wyzlic
** Last update Thu Jun 22 22:28:42 2017 Dimitri Wyzlic
*/

#include "Server.h"

static t_response	*eject_player(THIS, t_player *from, t_player *to)
{
  t_response		*response;

  MALLOC(response, sizeof(t_response));
  response->name = to->name;
  response->fd = to->fd;
  if (from->direction == NORTH)
    to->position.y = (to->position.y - 1 + this->map->height) % this->map->height;
  if (from->direction == SOUTH)
    to->position.y = (to->position.y + 1 + this->map->height) % this->map->height;
  if (from->direction == EAST)
    to->position.x = (to->position.x + 1 + this->map->width) % this->map->width;
  if (from->direction == WEST)
    to->position.x = (to->position.x + 1 + this->map->width) % this->map->width;
  response->msg = new_string("eject: ");
  response->msg->add(response->msg, new_string(direction_name[(from->direction + 2) % 4]));

  return (response);
}

static t_vector		*eject(THIS, t_player *player)
{
  t_vector		*out;
  PAIR_CP		*it;
  t_response		*resp;

  MALLOC(resp, sizeof(t_response));
  resp->name = player->name;
  resp->fd = player->fd;
  out = new_vector();
  resp->msg = new_string(MSG_OK);
  out->add(out, resp);
  this->players->start_loop(this->players);
  while ((it = this->players->loop(this->players)) != NULL)
    if (it->data->fd != player->fd)
      out->add(out, eject_player(this, player, it->data));
  return (out);
}

static t_response	*unused_slot(THIS, t_player *player)
{
  t_response		*out;
  int			idx;
  char			*tmp;

  MALLOC(tmp, 12);
  idx = this->team_index->get(this->team_index, player->team->__str);
  MALLOC(out, sizeof(t_response));
  out->name = player->name;
  out->fd = player->fd;
  sprintf(tmp, "%d", this->maxSlots - this->teams[idx]->current_nb_player);
  out->msg = new_string(tmp);
  return (out);
}

static t_response	*take_obj(THIS, t_player *player, t_mineral mineral)
{
  t_response		*resp;

  MALLOC(resp, sizeof(t_response));
  resp->name = player->name;
  resp->fd = player->fd;
  if (mineral == UNKNOW || mineral >= MAX_MINERAL)
    resp->msg = new_string(MSG_KO);
  else if (this->map->tiles[player->position.y][player->position.x].loot[mineral] > 0)
    {
      resp->msg = new_string(MSG_OK);
      player->inv.loot[mineral] += 1;
      this->map->tiles[player->position.y][player->position.x].loot[mineral] -= 1;
    }
  else
    resp->msg = new_string(MSG_KO);
  return (resp);
}