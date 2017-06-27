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

static t_vector			*wrapper_take(t_server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = new_vector();
  out->add(out, server->take_obj(server, player, mineral));
  return (out);
}

static t_vector			*wrapper_place(t_server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  t_vector		*out;

  out = new_vector();
  out->add(out, server->place_obj(server, player, mineral));
  return (out);
}

static t_vector			*wrapper_incant(t_server *server, t_player *player, t_mineral mineral, t_string *msg)
{
  //TODO FINISH INCANT
  t_vector			*out;

  out = new_vector();
  return (out);
}