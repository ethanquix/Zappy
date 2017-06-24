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

static Vector			*wrapper_get_inv(Server *server, Player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->get_inventory(server, player));
  return (out);
}

static Vector			*wrapper_broadcast(Server *server, Player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = server->broadcast(server, player, msg);
  return (out);
}

static Vector			*wrapper_unused(Server *server, Player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->unused_slot(server, player));
  return (out);
}

static Vector			*wrapper_fork(Server *server, Player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->forkPlayer(server, player)); //TODO FINIS FORK LOGIC
  return (out);
}

static Vector			*wrapper_eject(Server *server, Player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = server->eject(server, player);
  return (out);
}
