/*
** Server.c for Zappy in /home/wyzlic_a/delivery/Zappy/Server.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Thu Jun 08 22:44:45 2017 Dimitri Wyzlic
** Last update Thu Jun 08 22:44:45 2017 Dimitri Wyzlic
*/

#include "Server.h"

static Server		*add_team(THIS, String *name); //TODO
static Server		*player_connect(THIS, String *name); //TODO
static t_response	*forward(THIS, Player *player);
static t_response	*rotate_left(THIS, Player *player);
static t_response	*rotate_right(THIS, Player *player);
static t_response	*see(THIS, Player *player);
static t_response	*get_inventory(THIS, Player *player);
static Vector		*broadcast(THIS, Player *player, String *msg);
static Server		*forkPlayer(THIS, Player *player); //TODO
static Vector		*eject(THIS, Player *player);
static Server		*death(THIS, Player *player); //TODO
static t_response	*take_obj(THIS, Player *player, t_mineral mineral);
static t_response	*place_obj(THIS, Player *player, t_mineral mineral);
static Server		*incant(THIS, Player *player); //TODO
static t_response	*unused_slot(THIS, Player *player);

static void		delete(THIS);


Server			*newServer(WorldMap *map, t_arg *arg)
{
  Server		*tmp;

  MALLOC(tmp, sizeof(Server));
  *tmp = initServer(map, arg);

  return (tmp);
}

Server			initServer(WorldMap *map, t_arg *arg)
{
  Server		out;
  int			i;
  void			*it;

  i = 0;
  out.team_index = newMapCI(500, -1);
  out.nb_teams = arg->teamName->len(arg->teamName);
  MALLOC(out.teams, sizeof(t_team *) * out.nb_teams);
  while (i < out.nb_teams)
    out.teams[i++] = NULL;
  out.map = map;
  out.maxSlots = arg->maxPlayers;
  out.freq = arg->freq;
  out.players = newMapCP(500, NULL);

  arg->teamName->start_loop(arg->teamName);
  while ((it = arg->teamName->loop(arg->teamName)) != NULL)
    out.add_team(&out, (String *) it);


  out.delete = &delete;

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

#include "implem/ServerImplem1.c"
#include "implem/ServerImplem2.c"
#include "implem/ServerImplem3.c"
#include "implem/ServerImplem4.c"