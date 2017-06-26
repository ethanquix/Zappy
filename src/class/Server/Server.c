/*
** t_server.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_server.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Thu Jun 08 22:44:45 2017 Dimitri Wyzlic
** Last update Mon Jun 26 14:06:10 2017 Doom
*/

#include "Server.h"

static t_server		*add_team(THIS, t_string *name);
static t_server		*player_connect(THIS, int fd); //TODO
static t_connect_info	*add_player_info(THIS, t_player *player, t_string *team);
static t_response	*forward(THIS, t_player *player);
static t_response	*rotate_left(THIS, t_player *player);
static t_response	*rotate_right(THIS, t_player *player);
static t_response	*see(THIS, t_player *player);
static t_response	*get_inventory(THIS, t_player *player);
static t_vector		*broadcast(THIS, t_player *player, t_string *msg);
static t_response	*fork_player(THIS, t_player *player);
static t_vector		*eject(THIS, t_player *player);
static t_server		*death(THIS, t_player *player);
static t_response	*take_obj(THIS, t_player *player, t_mineral mineral);
static t_response	*place_obj(THIS, t_player *player, t_mineral mineral);
static t_response	*incant(THIS, t_player *player); //TODO
static t_response	*unused_slot(THIS, t_player *player);
static t_server		*loop(THIS);
static t_string		*get_tile_inv(THIS, int x, int y);
static void		delete(THIS);
static t_server		*apply_fork(THIS);
static t_server		*apply_incant(THIS, t_serv_todo *todo);

static t_server	*(*wrapper_function_server[])(THIS, t_serv_todo *src) =
{
  &apply_incant
};


t_server			*new_server(t_worldmap *map, t_arg *arg)
{
  t_server		*tmp;

  MALLOC(tmp, sizeof(t_server));
  *tmp = init_server(map, arg);
  return (tmp);
}

t_server			init_server(t_worldmap *map, t_arg *arg)
{
  t_server		out;
  int			i;
  void			*it;

  i = 0;
  out.gui = new_player();
  out.gui->fd = -1;
  out.todo = new_vector();
  out.delete = &delete;
  out.player_connect = &player_connect;
  out.add_player_info = &add_player_info;
  out.add_team = &add_team;
  out.forward = &forward;
  out.rotate_left = &rotate_left;
  out.rotate_right = &rotate_right;
  out.see = &see;
  out.get_inventory = &get_inventory;
  out.broadcast = &broadcast;
  out.eject = &eject;
  out.unused_slot = &unused_slot;
  out.take_obj = &take_obj;
  out.place_obj = &place_obj;
  out.team_index = new_map_ci(MAP_CI_MAX, -1);
  out.nb_teams = arg->teamName->len(arg->teamName);
  MALLOC(out.teams, sizeof(t_team *) * out.nb_teams);
  while (i < out.nb_teams)
    out.teams[i++] = NULL;
  out.map = map;
  out.maxSlots = arg->maxt_players;
  out.freq = arg->freq;
  out.players = new_map_cp(MAP_IP_MAX, NULL);
  arg->teamName->start_loop(arg->teamName);
  while ((it = arg->teamName->loop(arg->teamName)) != NULL)
      out.add_team(&out, (t_string *) it);
  out.fork_player = &fork_player;
  out.incant = &incant;
  out.death = &death;
  out.loop = &loop;
  out.__get_tile_inv = &get_tile_inv;

  return (out);
}

static void	delete(THIS)
{
  int		i;

  i = -1;
  while (i++ != this->nb_teams - 1)
    {
      this->teams[i]->name->delete(this->teams[i]->name);
      free(this->teams[i]);
    }
  this->team_index->delete(this->team_index);
  free(this->teams);
  this->players->delete(this->players);
  this->map->delete(this->map);
  free(this);
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

static t_server		*loop(THIS)
{
  t_serv_todo		*cur;
  int			i;

  apply_fork(this);
  i = 0;
  while (i > 0 && i < this->todo->len(this->todo))
    {
      VGET(cur, this->todo, i);
      if (cur->time <= 0)
	{
	  wrapper_function_server[cur->action](this, cur);
	  this->todo->erase(this->todo, i);
	  i -= 1;
	}
      cur->time -= 1;
    }
  return (this);
}

#include "implem/ServerImplem1.c"
#include "implem/ServerImplem2.c"
#include "implem/ServerImplem3.c"
#include "implem/ServerImplem4.c"
#include "implem/ServerImplem5.c"
