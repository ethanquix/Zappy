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
static t_connect_info	*add_player_info(THIS, t_player *player,
					      t_string *team);
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
static t_response	*incant(THIS, t_player *player);
static t_response	*unused_slot(THIS, t_player *player);
static t_server		*loop(THIS);
static t_string		*get_tile_inv(THIS, int x, int y);
static void		delete(THIS);
static t_server		*apply_fork(THIS);
static t_server		*apply_incant(THIS, t_serv_todo *todo);
static bool		check_time(THIS);
static bool		calc_food(THIS, t_player *player);

static t_server	*(*wrapper_function_server[])(THIS, t_serv_todo *src) =
{
	&apply_incant
};

static void	init_server_fnc(t_server *server)
{
  server->delete = &delete;
  server->player_connect = &player_connect;
  server->add_player_info = &add_player_info;
  server->add_team = &add_team;
  server->forward = &forward;
  server->rotate_left = &rotate_left;
  server->rotate_right = &rotate_right;
  server->see = &see;
  server->get_inventory = &get_inventory;
  server->broadcast = &broadcast;
  server->eject = &eject;
  server->unused_slot = &unused_slot;
  server->take_obj = &take_obj;
  server->place_obj = &place_obj;
  server->fork_player = &fork_player;
  server->incant = &incant;
  server->death = &death;
  server->loop = &loop;
  server->__get_tile_inv = &get_tile_inv;
  server->check_time = &check_time;
  server->calc_food = &calc_food;
}

t_server	*init_server(t_worldmap *map, t_arg *arg)
{
  t_server	*out;
  int		i;
  void		*it;

  MALLOC(out, sizeof(t_server));
  memset(out, 0, sizeof(t_server));
  init_server_fnc(out);
  i = 0;
  out->gui = new_player();
  out->gui->fd = -1;
  out->todo = new_vector();
  out->team_index = new_map_ci(MAP_CI_MAX, -1);
  out->nb_teams = arg->teamName->len(arg->teamName);
  MALLOC(out->teams, sizeof(t_team *) * out->nb_teams);
  while (i < out->nb_teams)
    out->teams[i++] = NULL;
  out->map = map;
  out->maxSlots = arg->maxt_players;
  out->freq = arg->freq;
  out->players = new_map_cp(MAP_IP_MAX, NULL);
  arg->teamName->start_loop(arg->teamName);
  while ((it = arg->teamName->loop(arg->teamName)) != NULL)
      out->add_team(out, (t_string *) it);
  out->ms = 0;
  out->cur_div = 1000 / out->freq;
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

static t_server		*loop(THIS)
{
  t_serv_todo		*cur;
  int			i;
  PAIR_CP		*it;

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
  this->players->start_loop(this->players);
  while ((it = this->players->loop(this->players)) != NULL)
    if (this->calc_food(this, it->data) == true)
      this->death(this, it->data);
  return (this);
}

#include "implem/ServerImplem1.c"
#include "implem/ServerImplem2.c"
#include "implem/ServerImplem3.c"
#include "implem/ServerImplem4.c"
#include "implem/ServerImplem5.c"