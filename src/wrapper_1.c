/*
** wrapper_1.c for Zappy in /home/wyzlic_a/delivery/Zappy/wrapper_1.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Sat Jun 24 19:30:43 2017 Dimitri Wyzlic
** Last update Sat Jun 24 19:30:43 2017 Dimitri Wyzlic
*/

#include "cmd.h"

static Vector			*wrapper_ko(Server *server, Player *player, t_mineral mineral, String *msg)
{
  Vector		*out;
  t_response		*resp;

  out = newVector();
  MALLOC(resp, sizeof(t_response));
  resp->name = player->name;
  resp->fd = player->fd;
  resp->msg = newString("ko");
  out->add(out, resp);
  return (out);
}

static Vector			*wrapper_forward(Server *server, Player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->forward(server, player));
  return (out);
}

static Vector			*wrapper_right(Server *server, Player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->rotate_right(server, player));
  return (out);
}

static Vector			*wrapper_left(Server *server, Player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->rotate_left(server, player));
  return (out);
}

static Vector			*wrapper_see(Server *server, Player *player, t_mineral mineral, String *msg)
{
  Vector		*out;

  out = newVector();
  out->add(out, server->see(server, player));
  return (out);
}