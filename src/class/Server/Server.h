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
  // which will contain the client (way to communicate via tcp or maybe put it here ?)
};

Server			*newServer();
Server			initServer();


#define serverNorme server = NULL
static Server *serverNorme;


static Server		*getServer()
{
  return (server);
}
#endif //ZAPPY_SERVER_H
