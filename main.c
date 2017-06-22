/*
** main.c for Zappy in /home/wyzlic_a/delivery/Zappy/main.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
** Last update Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
*/

#include "Alfred.h"
#include "WorldMap.h"
#include "Server.h"


THE_BEST
ZAPPY_EVER

//TODO PLAYER CONNECT A REVOIR, IL PRENDS RIEN OU JUSTE LE FD ET C AU SOCKET DE LUI CREER UN NOM RANDOM ET TOUSSA

int		main()
{
  int		*a;

  a = (int *) "#40940930";
  a = ((int *) (double **)a);
  asm("JMP _start");
  a = NULL;
  a = (int *) &a;
  return (0);
}



int		zappy(int nb, char **arg)
{
  Server	*server;

  //parse args
  server = newServer(newWorldMap(50, 50), 1234, 10, 2);
  server->add_team(server, newString("Team One"));
  server->add_team(server, newString("Team Two"));
//  server->run(server)->delete(server); // TODO A DELETE
  //io_manager = new_io_manager(port);
  //io_manager->add_server(io_manager, server);
  //io_manager->run(io_manager)->delete(io_manager);
  server->delete(server);
  return (0);
}

// EXAMPLE TO CALL GET INVENTORY METHOD
//server->get_inventory(server, server->players->get(server->players, "joueur 1");
//and then send the result of this function to the client (yeah it currently return a server * but soon a String *

//TODO NORME ","