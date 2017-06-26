/*
** wrapper_2.c for Zappy in /home/wyzlic_a/delivery/Zappy/wrapper_2.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Sat Jun 24 19:35:59 2017 Dimitri Wyzlic
** Last update Sat Jun 24 19:35:59 2017 Dimitri Wyzlic
*/

#include "cmd.h"

static Vector			*wrapper_get_inv(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->get_inventory(server, player));
  return (out);
}

static Vector			*wrapper_broadcast(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  Vector		*out;

  out = server->broadcast(server, player, msg);
  return (out);
}

static Vector			*wrapper_unused(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->unused_slot(server, player));
  return (out);
}

static Vector			*wrapper_fork(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->fork_player(server, player));
  return (out);
}

static Vector			*wrapper_eject(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  Vector		*out;

  out = server->eject(server, player);
  return (out);
}
