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

static t_vector			*wrapper_ko(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;
  t_response		*resp;

  out = new_vector();
  MALLOC(resp, sizeof(t_response));
  resp->name = player->name;
  resp->fd = player->fd;
  resp->msg = new_string(MSG_KO);
  out->add(out, resp);
  return (out);
}

static t_vector			*wrapper_forward(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = new_vector();
  out->add(out, server->forward(server, player));
  return (out);
}

static t_vector			*wrapper_right(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = new_vector();
  out->add(out, server->rotate_right(server, player));
  return (out);
}

static t_vector			*wrapper_left(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = new_vector();
  out->add(out, server->rotate_left(server, player));
  return (out);
}

static t_vector			*wrapper_see(Server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = new_vector();
  out->add(out, server->see(server, player));
  return (out);
}