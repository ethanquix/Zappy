/*
** ServerImplem1.c for Zappy in /home/wyzlic_a/delivery/Zappy/ServerImplem1.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Fri Jun 09 01:16:13 2017 Dimitri Wyzlic
** Last update Fri Jun 23 01:53:12 2017 Doom
*/

#include "Server.h"

static Server		*add_team(THIS, String *name)
{
  int			i;
  t_team		*out;

  MALLOC(out, sizeof(t_team));
  out->name = name;
  out->current_nb_player = 0;

  i = 0;
  while (this->teams[i] != NULL)
    i += 1;
  this->teams[i] = out;
  this->team_index->set(this->team_index, name->__str, i);
  return (this);
}

static Server		*player_connect(THIS, String *name)
{
  Player		*new;

  new = newPlayer();
  if (this->players->exist(this->players, name->get(name)) == true)
    {
      //TODO ERROR PLAYER EXIST
    }
  else
    {
      this->players->set(this->players, name->get(name), new);
      //TODO CONTACT CLIENT OK AND PLACE PLAYER ON MAP
    }
  return (this);
}

static t_response	*forward(THIS, Player *player, int width, int height)
{
  t_response		*out;

  MALLOC(out, sizeof(t_response));
  out->name = player->name;
  out->msg = newString("ok");
  if (player->direction == NORTH && player->position.y - 1 >= 0)
    (player->position.y = player->position.y - 1);
  else if (player->direction == SOUTH && player->position.y + 1 < height)
    (player->position.y = player->position.y + 1);
  else if (player->direction == EAST && player->position.x + 1 < width)
    (player->position.x = player->position.x + 1);
  else if (player->direction == WEST && player->position.x - 1 >= 0)
    (player->position.x = player->position.x - 1);
  else
    out->msg = newString("ko");
  return (out);
}

static Server		*rotate(THIS, Player *player, Direction *direction)
{
  if (*direction == EAST)
    {
      if (player->direction == NORTH)
	player->direction = EAST;
      else if (player->direction == EAST)
	player->direction = SOUTH;
      else if (player->direction == SOUTH)
	player->direction = WEST;
      else if (player->direction == WEST)
	player->direction = NORTH;
    }
  else
    {
      if (player->direction == NORTH)
	player->direction = WEST;
      else if (player->direction == WEST)
	player->direction = SOUTH;
      else if (player->direction == SOUTH)
	player->direction = EAST;
      else if (player->direction == EAST)
	player->direction = NORTH;
    }
  return (this);
}

static String		*get_tile_inv(THIS, int x, int y)
{
  String		*out;
  int			i;
  int			tmp;
  PairCP		*it;

  i = 0;
  out = newString("");
  while (i < MAX_MINERAL)
    {
      tmp = this->map->tiles[x][y].loot[i];
      if (tmp > 0)
	{
	  if (out->len(out) > 0)
	    out->add(out, newString(" "));
	  out->add(out, newString(mineral_name[i]));
	}
      i INC 1;
    }
  this->players->start_loop(this->players);
  while ((it = this->players->loop(this->players)) != NULL)
    {
      if (it->data->position.x == x && it->data->position.y == y)
	{
	  if (out->len > 0)
	    out->add(out, newString(" "));
	  out->add(out, it->data->name);
	}
    }
  return (out);
}

static void		my_swap(int *a, int *b)
{
  int			c;

  c = *a;

  *a = *b;
  *b = c;
}

static String		*get_line_from_map(THIS, int x1, int y1, int x2, int y2)
{
  String		*out;
  String		*comma;

  out = newString("");
  comma = newString(",");

  if (x2 > x1)
    my_swap(&x1, &x2);
  if (y2 > y1)
    my_swap(&y1, &y2);
  if (x1 == x2 && y1 == y2)
    return (out->add(out, get_tile_inv(this, x1, y1))->add(out, comma));
  while (x1 < x2 && y1 == y2)
    {
      out->add(out, get_tile_inv(this, x1, y1))->add(out, comma);
      x1 INC 1;
    }
  while (y1 < y2 && x1 == x2)
    {
      out->add(out, get_tile_inv(this, x1, y1))->add(out, comma);
      y1 INC 1;
    }
  comma->delete(comma);
  return (out);
}

static Server		*see(THIS, Player *player)
{
  String		*out;
  int			i;
  Vec2I			a;
  Vec2I			b;


  a.x = player->position.x;
  a.y = player->position.y;
  b = a;
  out = newString("");
  i = 0;
  while (i < player->level)
    {
      out->add(out, get_line_from_map(this, a.x, a.y, a.x, a.y));
      if (player->direction == NORTH)
	{
	  a.x -= 1;
	  b.x += 1;
	  a.y -= 1;
	  b.y -= 1;
	}
      if (player->direction == SOUTH)
	{
	  a.x += 1;
	  b.x -= 1;
	  a.y += 1;
	  b.y += 1;
	}
      if (player->direction == WEST)
	{
	  a.x -= 1;
	  b.x -= 1;
	  a.y += 1;
	  b.y -= 1;
	}
      if (player->direction == EAST)
	{
	  a.x += 1;
	  b.x += 1;
	  a.y -= 1;
	  b.y += 1;
	}
      i INC 1;
    }
  // TODO replace by return out;
  return (this);
}

static Server	*get_inventory(THIS, Player *player)
{
  String	*out;
  int		i;
  char		*tmp;

  MALLOC(tmp, 1000);
  out = newString("");
  i = 0;
  while (i < MAX_MINERAL)
    {
      free(tmp);
      MALLOC(tmp, 1000);
      RESET(tmp, '\0');
      sprintf(tmp, "%d", player->inv.loot[i]);
      out->add(out, newString(mineral_name[i]))->add(out, newString(" "));
      out->add(out, newString(tmp))->add(out, newString(","));
      i INC 1;
    }
  return (this); //TODO RETURN OUT
}
