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

static void		get_team_list(t_server *server)
{
  t_string		*out;
  int			i;

  out = new_string("");
  i = 0;
  while (i < server->nb_teams)
    {
      if (i != 0)
	out->add(out, new_string(" "));
      out->add(out, server->teams[i]->name);
      i += 1;
    }
  dprintf(server->gui->fd, "TEAML %s\n", out->__str);
}

static void		get_player_info(t_server *server)
{
  char		*cmd;
  PAIR_CP	*it;

  cmd = strtok(NULL, " \n");
  server->players->start_loop(server->players);
  while (cmd != NULL && (it = server->players->loop(server->players)) != NULL)
    {
      if (strcmp(cmd, it->data->name->__str) == 0)
	{
	  dprintf(server->gui->fd, "PINFO %s %d %d %d %d %d %d %d %d %d\n", it->data->name->__str,
		  it->data->position.x, it->data->position.y, it->data->inv.loot[0],
		  it->data->inv.loot[1], it->data->inv.loot[2], it->data->inv.loot[3],
		  it->data->inv.loot[4], it->data->inv.loot[5], it->data->inv.loot[6]);
	  return ;
	}
    }
}

static void		set_ressource(t_server *server)
{
  RAISE("Not done yet");
}