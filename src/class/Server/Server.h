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

#include "arg_parser.h"
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
  String	*name; //TODO mostly here to debug
  int		fd;
  String	*msg;
}		t_response;

typedef struct	s_connect_info
{
  String	*name;
  String	*coord;
}		t_connect_info;

CLASS			s_server
{
  MapCI			*team_index;
  t_team		**teams;
  WorldMap		*map;
  MapCP			*players;
  int			maxSlots;
  int			nb_teams;
  int			freq;
  Player		*gui;

  void			(*delete)(THIS);

  Server		*(*add_team)(THIS, String *name);
  Server		*(*player_connect)(THIS, int fd);
  t_connect_info	*(*add_player_info)(THIS, Player *player, String *team);

  t_response		*(*forward)(Server *this, Player *player);
  t_response		*(*rotate_left)(THIS, Player *player);
  t_response		*(*rotate_right)(THIS, Player *player);
  t_response		*(*see)(THIS, Player *player);
  t_response		*(*get_inventory)(THIS, Player *player);
  Vector		*(*broadcast)(Server *this, Player *player, String *msg);
  Server		*(*forkPlayer)(THIS, Player *player); //TODO DO FORK PLAYER
  Vector		*(*eject)(THIS, Player *player);
  t_response		*(*take_obj)(THIS, Player *player, t_mineral mineral);
  t_response		*(*place_obj)(THIS, Player *player, t_mineral mineral);
  Server		*(*incant)(THIS, Player *player); //TODO FINISH INCANT
  t_response		*(*unused_slot)(THIS, Player *player);

  Server		*(*hatch_egg)(THIS); //TODO HATCH EGG AND WHAT TO DO HEN EGG PLACED
  //TODO ADD INCANT DONE
  Server		*(*death)(THIS, Player *player); //TODO DEATH
};

Server			*newServer(WorldMap *map, t_arg *arg);
Server			initServer(WorldMap *map, t_arg *arg);

#endif //ZAPPY_SERVER_H
