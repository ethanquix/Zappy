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

static Server		*forward(THIS, Player *player, int width, int height);
static Server		*rotate(THIS, Player *player, Direction *direction);
static Server		*see(THIS, Player *player);
static Server		*get_inventory(THIS, Player *player);
static Server		*broadcast(THIS, Player *player, String *, WorldMap *map, MapCP *players[2]);
static Server		*forkPlayer(THIS, Player *player, WorldMap *map, MapCP *players[2]);
static Server		*eject(THIS, Player *player, WorldMap *map, MapCP *players[2]);
static Server		*death(THIS, Player *player);
static Server		*take_obj(THIS, Player *player, WorldMap *map);
static Server		*place_obj(THIS, Player *player, WorldMap *map);
static Server		*incant(THIS, Player *player, WorldMap *map, MapCP *players[2]);
static Server		*unused_slot(THIS, Player *player);

static Server		*run(THIS);
static void		delete(THIS);


Server *newServer(WorldMap *map, String *teamOne, String *teamTwo, int port, int maxSlots)
{
  void			*new;
  Server		tmp;
  Server		*out;

  tmp AS initServer(map, teamOne, teamTwo, port, maxSlots);
  MALLOC(new, sizeof(Server));
  if ((new AS memcpy(new, &tmp, sizeof(Server))) IS NULL)
    raise(get_error());
  out AS (Server *) new;

  return (out);
}

Server			initServer(WorldMap *map, String *teamOne, String *teamTwo, int port, int maxSlots)
{
  Server		out;

  out.players[TEAM_ONE] = newMapCP(500, NULL);
  out.players[TEAM_TWO] = newMapCP(500, NULL);
  out.map = map;
  out.team_one = teamOne;
  out.team_two = teamTwo;
  out.port = port;
  out.maxSlots = maxSlots;
  out.timeLimit = 100;

  out.run = &run;
  out.delete = &delete;

  out.forward = &forward;
  out.rotate = &rotate;

  return (out);
}

static Server	*run(THIS)
{
  //Do all serv connection, save command etc...
  return (this);
}

static void	delete(THIS)
{
  this->team_one->delete(this->team_one);
  this->team_two->delete(this->team_two);
  free(this);
}

#include "implem/ServerImplem1.c"