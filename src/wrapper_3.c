/*
** wrapper_3.c for Zappy in /home/wyzlic_a/delivery/Zappy/wrapper_3.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Sat Jun 24 19:45:26 2017 Dimitri Wyzlic
** Last update Sat Jun 24 19:45:26 2017 Dimitri Wyzlic
*/

#include "cmd.h"

static Vector			*wrapper_take(Server *server, t_player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->take_obj(server, player, mineral));
  return (out);
}

static Vector			*wrapper_place(Server *server, t_player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->place_obj(server, player, mineral));
  return (out);
}

static Vector			*wrapper_incant(Server *server, t_player *player, t_mineral mineral, String *msg)
{
  //TODO FINISH INCANT
  Vector			*out;

  out = newVector();
  return (out);
}