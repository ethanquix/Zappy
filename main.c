/*
** main.c for Zappy in /home/wyzlic_a/delivery/Zappy/main.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
** Last update Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
*/

#include "arg_parser.h"
#include "Alfred.h"
#include "WorldMap.h"
#include "Server.h"


THE_BEST
ZAPPY_EVER

//TODO PLAYER CONNECT A REVOIR, IL PRENDS RIEN OU JUSTE LE FD ET C AU SOCKET DE LUI CREER UN NOM RANDOM ET TOUSSA
int	start(t_arg *args);

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



int		zappy(int ac, char *av[])
{
  start(parse_arg(ac, av));
  return (0);
}

// EXAMPLE TO CALL GET INVENTORY METHOD
//server->get_inventory(server, server->players->get(server->players, "joueur 1");
//and then send the result of this function to the client (yeah it currently return a server * but soon a String *

//TODO NORME ","