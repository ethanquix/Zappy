/*
** cmd.c for
**
** Made by Raphael Chriqui
** Login   <raphael.chriqui@epitech.net>
**
** Started on  Fri May 12 09:35:57 2017 Raphael Chriqui
** Last update Fri Jun  9 14:11:49 2017 Lheen Teck
*/

#include <stdio.h>
#include <Vector.h>
#include "cmd.h"

static const t_cmd	client_cmd[] =
  {
	  { "Forward", C_FORWARD, TIME_FORWARD },
	  { NULL, 0, 0 }
  };

static Player		*get_player(Server *server, int fd)
{
  PairCP		*it;

  server->players->start_loop(server->players);
  while ((it = server->players->loop(server->players)))
    {
      if (fd == it->data->fd)
	return (it->data);
    }
  return (NULL);
}

int			check_team(Player *player, Server *server, char *cmd)
{
  t_connect_info	*cinfo;

  if (!player->team)
    {
      if ((cinfo = server->add_player_info(server, player, newString(cmd))) ==
	  NULL)
	{
	  dprintf(player->fd, "%s\n%s\n", cinfo->name->__str,
		  cinfo->coord->__str);
	} else
	{
	  dprintf(player->fd, "Ko\r\n");
	}
      return (1);
    }
  else
    return (0);
}

void			second_tick(Server *server, Player *player)
{
  Vector		*resp;
  int			index;

  resp = client_cmd[index].ptr(server, player);
  index = 0;
  while (index < resp->len(resp))
    dprintf(server->players->get(server->players, ((t_response*)resp->get(resp, index))->name->__str)->fd,
	    ((t_response*)resp->get(resp, index))->msg->__str);
}

void			check_cmd_client(Server *server, t_socket *socket)
{
  Player		*player;
  char			*cmd;
  int			index;
  enum e_mineral	mineraln;

  player = get_player(server, socket->fd_client);
  if ((cmd = socket->socket_receive(socket)) == NULL)
    return (void)server->death(server, player);
  if (check_team(player, server, (cmd = strtok(cmd, " \r\n"))))
    return ;
  index = 0;
  while (client_cmd[index].cmd_name != NULL &&
	 strcasecmp(client_cmd[index].cmd_name, cmd) != 0)
    index++;
  if (client_cmd[index].cmd_name)
    {
      index = -1;
      while (player->todo[++index].time != -1);
      player->todo[index].action = client_cmd[index].action;
      player->todo[index].time = client_cmd[index].time / server->freq;
      cmd = strtok(NULL, " \n");
      mineraln = -1;
      while ((cmd != mineral_name[++mineraln]) || cmd == NULL);
      player->todo[index].mineral = mineraln;
      player->todo[index].msg = newString(cmd);
    }
  else
    {
    }
}