/*
** Server.h for Zappy in /home/wyzlic_a/delivery/Zappy/Server.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Thu Jun 08 19:42:08 2017 Dimitri Wyzlic
** Last update Thu Jun 08 19:42:08 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_SERVER_H
#define ZAPPY_SERVER_H

#include "Alfred.h"
#include "MapCP.h"
#include "String.h"
#include "WorldMap.h"
#include "team.h"

typedef class s_server Server;

#undef THIS
#define THIS Server *this

class			s_server
{
  t_team		**teams;
  WorldMap		*map;
  MapCP			*players;
  int			maxSlots;
  int			nb_teams;
  int			port;
  int			timeLimit;

  Server		*(*run)(THIS);
  void			(*delete)(THIS);

  Server		*(*add_team)(THIS, String *name);
  Server		*(*player_connect)(THIS, Player *player);
  Server		*(*forward)(Server *this, Player *player);
  Server		*(*rotate)(THIS, Player *player, Direction *direction);
  Server		*(*see)(THIS, Player *player);
  Server		*(*get_inventory)(THIS, Player *player);
  Server		*(*broadcast)(Server *this, Player *player, String *msg);
  Server		*(*forkPlayer)(THIS, Player *player);
  Server		*(*eject)(THIS, Player *player);
  Server		*(*death)(THIS, Player *player);
  Server		*(*take_obj)(THIS, Player *player);
  Server		*(*place_obj)(THIS, Player *player); // et l'obj a placer
  Server		*(*incant)(THIS, Player *player);
  Server		*(*unused_slot)(THIS, Player *player);
  // which will contain the client (way to communicate via tcp or maybe put it here ?)
};

Server			*newServer(WorldMap *map, int port, int maxSlots, int nbTeams);
Server			initServer(WorldMap *map, int port, int maxSlots, int nbTeams);

#endif //ZAPPY_SERVER_H
