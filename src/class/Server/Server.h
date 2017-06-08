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

typedef class s_Server Server;

#undef THIS
#define THIS Server *this

#define TEAM_ONE 0
#define TEAM_TWO 1


class			s_Server
{
  WorldMap		*map;
  String		*team_one;
  String		*team_two;
  MapCP			*players[2];
  int			maxSlots;
  int			port;
  int			timeLimit;

  Server		*(*run)(THIS);
  void			(*delete)(THIS);

  Server		*(*forward)(THIS, Player *player, int width, int height);
  Server		*(*rotate)(THIS, Player *player, Direction *direction);
  Server		*(*see)(THIS, Player *player);
  Server		*(*get_inventory)(THIS, Player *player);
  Server		*(*broadcast)(THIS, Player *player, String *, WorldMap *map, MapCP *players[2]);
  Server		*(*forkPlayer)(THIS, Player *player, WorldMap *map, MapCP *players[2]);
  Server		*(*eject)(THIS, Player *player, WorldMap *map, MapCP *players[2]);
  Server		*(*death)(THIS, Player *player);
  Server		*(*take_obj)(THIS, Player *player, WorldMap *map);
  Server		*(*place_obj)(THIS, Player *player, WorldMap *map);
  Server		*(*incant)(THIS, Player *player, WorldMap *map, MapCP *players[2]);
  Server		*(*unused_slot)(THIS, Player *player);
  // which will contain the client (way to communicate via tcp or maybe put it here ?)
};

Server			*newServer(WorldMap *map, String *teamOne, String *teamTwo, int port, int maxSlots);
Server			initServer(WorldMap *map, String *teamOne, String *teamTwo, int port, int maxSlots);

#endif //ZAPPY_SERVER_H
