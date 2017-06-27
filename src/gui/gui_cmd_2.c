/*
** gui_cmd_2.c for Zappy in /home/wyzlic_a/delivery/Zappy/gui_cmd_2.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 26 19:09:53 2017 Dimitri Wyzlic
** Last update Mon Jun 26 19:09:53 2017 Dimitri Wyzlic
*/

#include "Server.h"
#include "cmd.h"

static void		get_team_list(t_server *server, t_string *cmd)
{
  t_string		*out;
  int			i;

  UNUSED(cmd);
  out = new_string("");
  i = 0;
  while (i < server->nb_teams)
    {
      if (i != 0)
	out->add(out, new_string(" "));
      out->add(out, server->teams[i]->name);
      i += 1;
    }
  dprintf(server->gui->fd, "%s\n", out->__str);
}

static void		get_player_info(t_server *server, t_string *cmd)
{
  RAISE("Not done yet");
}

static void		set_ressource(t_server *server, t_string *cmd)
{
  RAISE("Not done yet");
}