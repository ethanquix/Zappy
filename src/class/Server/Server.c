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

static Server		*run(THIS);
static void		delete(THIS);


Server			*newServer(WorldMap *map, int port, int maxSlots, int nbTeams)
{
  Server		*tmp;

  MALLOC(tmp, sizeof(Server));
  *tmp = initServer(map, port, maxSlots, nbTeams);

  return (tmp);
}

Server			initServer(WorldMap *map, int port, int maxSlots, int nbTeams)
{
  Server		out;
  int			i;

  i = 0;
  out.team_index = newMapCI(500, -1);
  out.nb_teams = nbTeams;
  MALLOC(out.teams, sizeof(t_team *) * nbTeams);
  while (i < nbTeams)
    out.teams[i++] = NULL;
  out.map = map;
  out.port = port;
  out.maxSlots = maxSlots;
  out.timeLimit = 100;
  out.players = newMapCP(500, NULL);

  out.run = &run; // TODO REMOVE RUN METHOD
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

static Server	*run(THIS)
{
  //1: Ask connect tool to fetch all request
  //2: Execute the command returned by the server
  //3: loop
  //TODO all serv connection, save command etc...
  return (this);
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