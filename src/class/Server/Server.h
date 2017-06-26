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

#define TIME_SERVER_FORK 600
#define TIME_SERVER_INCANT 300

typedef CLASS s_server Server;

#undef THIS
#define THIS Server *this

enum e_cmd_serv_nb
{
  CMD_SERVER_INCANT,
};

typedef struct		s_serv_todo
{
  enum e_cmd_serv_nb	action;
  int			time;
  int			player_fd;
}			t_serv_todo;

typedef struct	s_response
{
  t_string	*name; //TODO mostly here to debug
  int		fd;
  t_string	*msg;
}		t_response;

typedef struct	s_connect_info
{
  int		remaining;
  t_string	*coord;
}		t_connect_info;

typedef CLASS		s_server
{
  t_map_ci		*team_index;
  t_team		**teams;
  t_worldmap		*map;
  t_map_cp		*players;
  int			maxSlots;
  int			nb_teams;
  int			freq;
  t_player		*gui;
  t_vector		*todo;
  void			(*delete)(THIS);
  Server		*(*add_team)(THIS, t_string *name);
  Server		*(*player_connect)(THIS, int fd);
  t_connect_info	*(*add_player_info)(THIS, t_player *player, t_string *team);
  t_response		*(*forward)(Server *this, t_player *player);
  t_response		*(*rotate_left)(THIS, t_player *player);
  t_response		*(*rotate_right)(THIS, t_player *player);
  t_response		*(*see)(THIS, t_player *player);
  t_response		*(*get_inventory)(THIS, t_player *player);
  t_vector		*(*broadcast)(Server *this, t_player *player, t_string *msg);
  t_response		*(*fork_player)(THIS, t_player *player);
  t_vector		*(*eject)(THIS, t_player *player);
  t_response		*(*take_obj)(THIS, t_player *player, t_mineral mineral);
  t_response		*(*place_obj)(THIS, t_player *player, t_mineral mineral);
  t_response		*(*incant)(THIS, t_player *player);
  t_response		*(*unused_slot)(THIS, t_player *player);
  t_string		*(*__get_tile_inv)(THIS, int x, int y);
  Server		*(*death)(THIS, t_player *player);
  Server		*(*loop)(THIS);
}			t_server;

Server			*new_server(t_worldmap *map, t_arg *arg);
Server			init_server(t_worldmap *map, t_arg *arg);

#endif //ZAPPY_SERVER_H
