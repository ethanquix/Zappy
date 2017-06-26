/*
** ServerImplem1.c for Zappy in /home/wyzlic_a/delivery/Zappy/ServerImplem1.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Fri Jun 09 01:16:13 2017 Dimitri Wyzlic
** Last update Mon Jun 26 04:28:50 2017 Doom
*/

#include "Server.h"

static Server		*add_team(THIS, t_string *name)
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
  out->eggs = new_vector();
  return (this);
}

static Server		*player_connect(THIS, int fd)
{
  t_player		*new;

  new = new_player();
  new->fd = fd;
  new->team = NULL;
  new->name = new_string("");
  new->name = new->name->random_string(new->name, 20);
  this->players->set(this->players, fd, new);
  return (this);
}

static	t_player		*find_and_delete_egg(t_team *team, t_player *player)
{
  t_egg				*egg;
  int				i;

  i = 0;
  while (i < team->eggs->len(team->eggs))
    {
      VGET(egg, team->eggs, i);
      if (egg->is_hatched == true)
	{
	  player->position = egg->pos;
	  team->current_nb_player += 1;
	  team->eggs->erase(team->eggs, i);
	  return (player);
	}
      i += 1;
    }
  return (NULL);
}

static t_connect_info		*add_player_info(THIS, t_player *player, t_string *team)
{
  int				idx;
  t_connect_info		*out;
  char				*str;

  MALLOC(str, 30);
  MALLOC(out, sizeof(t_connect_info));
  if (strcmp(team->__str, strdup("GUI")) == 0)
    {
      this->gui->fd = player->fd;
      this->players->erase(this->players, player->fd);
      out->remaining = 42;
      out->coord = new_string("GUI");
      return (out);
    }
  idx = this->team_index->get(this->team_index, team->__str);
  if (idx == this->team_index->end(this->team_index))
    return (NULL);
  if (this->teams[idx]->current_nb_player + 1 <= this->maxSlots)
    {
      this->teams[idx]->current_nb_player += 1;
      player->position = rand_pos(0, 0, this->map->width - 1, this->map->height - 1);
    }
  else
    {
      player = find_and_delete_egg(this->teams[idx], player);
      if (player == NULL)
	return (NULL);
    }
  player->team = team;
  out->remaining = ABS(this->maxSlots - this->teams[idx]->current_nb_player) + this->teams[idx]->eggs->__len;
  sprintf(str, "%d %d", player->position.x, player->position.y);
  out->coord = new_string(str);
  return (out);
}

static t_response	*forward(THIS, t_player *player)
{
  t_response		*out;

  MALLOC(out, sizeof(t_response));
  out->name = player->name;
  out->fd = player->fd;
  out->msg = new_string(MSG_OK);
  if (player->direction == NORTH)
    (player->position.y = (player->position.y - 1 + this->map->height) % this->map->height);
  else if (player->direction == SOUTH)
    (player->position.y = (player->position.y + 1 + this->map->height) % this->map->height);
  else if (player->direction == EAST)
    (player->position.x = (player->position.x + 1 + this->map->width) % this->map->width);
  else if (player->direction == WEST)
    (player->position.x = (player->position.x - 1 + this->map->width) % this->map->width);
  printf("x %d y %d\n", player->position.x, player->position.y);
  return (out);
}

static t_response	*rotate_left(THIS, t_player *player)
{
  t_response		*out;

  MALLOC(out, sizeof(t_response));
  out->name = player->name;
  out->fd = player->fd;
  out->msg = new_string(MSG_OK);

  if (player->direction == NORTH)
    player->direction = WEST;
  else if (player->direction == WEST)
    player->direction = SOUTH;
  else if (player->direction == SOUTH)
    player->direction = EAST;
  else if (player->direction == EAST)
    player->direction = NORTH;
  return (out);
}

static t_response	*rotate_right(THIS, t_player *player)
{
  t_response		*out;

  MALLOC(out, sizeof(t_response));
  out->name = player->name;
  out->fd = player->fd;
  out->msg = new_string(MSG_OK);
  if (player->direction == NORTH)
    player->direction = EAST;
  else if (player->direction == EAST)
    player->direction = SOUTH;
  else if (player->direction == SOUTH)
    player->direction = WEST;
  else if (player->direction == WEST)
    player->direction = NORTH;

  return (out);
}

static t_string		*get_tile_inv(THIS, int x, int y)
{
  t_string		*out;
  int			i;
  int			tmp;
  PAIR_CP		*it;

  i = 0;
  printf("x %d y %d\n", x, y);
  out = new_string("");
  while (i < MAX_MINERAL)
    {
      tmp = this->map->tiles[y][x].loot[i];
      while (tmp > 0)
	{
	  if (out->len(out) > 0)
	    out->add(out, new_string(" "));
	  out->add(out, new_string(mineral_name[i]));
	  tmp -= 1;
	}
      i INC 1;
    }
  this->players->start_loop(this->players);
  while ((it = this->players->loop(this->players)) != NULL)
    {
      if (it->data->position.x == x && it->data->position.y == y)
	{
	  if (out->len > 0)
	    out->add(out, new_string(" "));
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

static t_string		*get_line_from_map(THIS, int x1, int y1, int x2, int y2)
{
  t_string		*out;
  t_string		*comma;
  t_string		*tmp;

  out = new_string("");
  comma = new_string(",");

  x1 = (x1 + this->map->width) % this->map->width;
  y1 = (y1 + this->map->height) % this->map->height;
  x2 = (x2 + this->map->width) % this->map->width;
  y2 = (y2 + this->map->width) % this->map->height;
  while (x1 != x2 && y1 == y2)
    {
      out->add(out, get_tile_inv(this, x1, y1))->add(out, comma);
      x1 = (x1 + 1) % this->map->width;
    }
  while (y1 != y2 && x1 == x2)
    {
      out->add(out, get_tile_inv(this, x1, y1))->add(out, comma);
      y1 = (y1 + 1) % this->map->height;
    }
  if (x1 == x2 && y1 == y2)
    {
      tmp = get_tile_inv(this, x1, y1);
      out = out->add(out, tmp)->add(out, comma);
      comma->delete(comma);
      return (out);
    }
  comma->delete(comma);
  return (out);
}

static t_response	*see(THIS, t_player *player)
{
  t_string		*out;
  int			i;
  t_vec_ii			a;
  t_vec_ii			b;
  t_response		*resp;

  MALLOC(resp, sizeof(t_response));
  resp->name = player->name;
  resp->fd = player->fd;
  a.x = player->position.x;
  a.y = player->position.y;
  b = a;
  out = new_string("");
  i = 1;

  out->add(out, get_line_from_map(this, a.x, a.y, b.x, b.y));
  while (i <= player->level)
    {
      if (player->direction == NORTH)
	{
	  a.x -= 1;
	  b.x += 1;
	  a.y -= 1;
	  b.y -= 1;
	  out->add(out, get_line_from_map(this, a.x, a.y, b.x, b.y));
	}
      if (player->direction == SOUTH)
	{
	  a.x += 1;
	  b.x -= 1;
	  a.y += 1;
	  b.y += 1;
	  out->add(out, get_line_from_map(this, b.x, b.y, a.x, a.y));
	}
      if (player->direction == WEST)
	{
	  a.x -= 1;
	  b.x -= 1;
	  a.y += 1;
	  b.y -= 1;
	  out->add(out, get_line_from_map(this, a.x, a.y, b.x, b.y));
	}
      if (player->direction == EAST)
	{
	  a.x += 1;
	  b.x += 1;
	  a.y -= 1;
	  b.y += 1;
	  out->add(out, get_line_from_map(this, b.x, b.y, a.x, a.y));
	}
      i += 1;
    }
  // TODO NORME
  resp->msg = out;
  if (resp->msg->__len > 1 && resp->msg->__str[resp->msg->__len - 1] == ',' || resp->msg->__str[0] == ',')
    resp->msg->__str[resp->msg->__len - 1] = 0;
  return (resp);
}

static t_response	*get_inventory(THIS, t_player *player)
{
  t_response		*resp;
  int			i;
  char			*tmp;

  MALLOC(resp, sizeof(t_response));
  MALLOC(tmp, 1000);
  resp->name = player->name;
  resp->fd = player->fd;
  resp->msg = new_string("");
  i = 0;
  while (i < MAX_MINERAL)
    {
      free(tmp);
      MALLOC(tmp, 1000);
      RESET(tmp, '\0');
      sprintf(tmp, "%d", player->inv.loot[i]);
      resp->msg->add(resp->msg, new_string(mineral_name[i]))->add(resp->msg, new_string(" "));
      resp->msg->add(resp->msg, new_string(tmp))->add(resp->msg, new_string(","));
      i INC 1;
    }
  return (resp);
}
