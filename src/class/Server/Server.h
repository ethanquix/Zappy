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

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "Alfred.h"
#include "Vector.h"
#include "MapCP.h"
#include "String.h"
#include "WorldMap.h"
#include "team.h"
#include "Socket.h"

typedef CLASS s_server Server;

#undef THIS
#define THIS Server *this

typedef struct	s_responsse
{
  String	*name;
  String	*msg;
}		t_response;

CLASS			s_server
{
  MapCI			*team_index;
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
  t_response		*(*forward)(Server *this, Player *player);
  t_response		*(*rotate_left)(THIS, Player *player);
  t_response		*(*rotate_right)(THIS, Player *player);
  t_response		*(*see)(THIS, Player *player);
  t_response		*(*get_inventory)(THIS, Player *player);
  Vector		*(*broadcast)(Server *this, Player *player, String *msg);
  Server		*(*forkPlayer)(THIS, Player *player);
  Vector		*(*eject)(THIS, Player *player);
  Server		*(*death)(THIS, Player *player);
  t_response		*(*take_obj)(THIS, Player *player, t_mineral mineral);
  t_response		*(*place_obj)(THIS, Player *player, t_mineral mineral);
  Server		*(*incant)(THIS, Player *player);
  t_response		*(*unused_slot)(THIS, Player *player);
  // which will contain the client (way to communicate via tcp or maybe put it here ?)
};

Server			*newServer(WorldMap *map, int port, int maxSlots, int nbTeams);
Server			initServer(WorldMap *map, int port, int maxSlots, int nbTeams);

#endif //ZAPPY_SERVER_H
