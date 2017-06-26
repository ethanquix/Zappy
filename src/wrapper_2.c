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

static t_vector			*wrapper_get_inv(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = new_vector();
  out->add(out, server->get_inventory(server, player));
  return (out);
}

static t_vector			*wrapper_broadcast(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = server->broadcast(server, player, msg);
  return (out);
}

static t_vector			*wrapper_unused(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = new_vector();
  out->add(out, server->unused_slot(server, player));
  return (out);
}

static t_vector			*wrapper_fork(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = new_vector();
  out->add(out, server->fork_player(server, player));
  return (out);
}

static t_vector			*wrapper_eject(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = server->eject(server, player);
  return (out);
}
