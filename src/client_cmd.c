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
#include "Vector.h"
#include "cmd.h"

static const t_cmd	client_cmd[] =
	{
		{ "Forward", C_FORWARD, TIME_FORWARD },
		{ "Left", C_LEFT, TIME_LEFT },
		{ "Right", C_RIGHT, TIME_RIGHT },
		{ "Look", C_LOOK, TIME_LOOK },
		{ "Inventory", C_INVENTORY, TIME_INVENTORY },
		{ "Broadcast", C_BROADCAST, TIME_BROADCAST },
		{ "Connect_nbr", C_UNUSED, TIME_UNUSED },
		{ "Fork", C_FORK, TIME_FORK },
		{ "Eject", C_EJECT, TIME_EJECT },
		{ "Take", C_TAKE, TIME_TAKE },
		{ "Set", C_SET, TIME_SET },
		{ "Incantation", C_INCANT, TIME_INCANT },
		{ NULL, C_NOTHING, 0 }
	};

static t_player		*get_player(t_server *server, int fd)
{
  return (server->players->get(server->players, fd));
}

int			check_team(t_player *player, t_server *server, char *cmd)
{
  t_connect_info	*cinfo;

  if (!player->team)
    {
      if ((cinfo = server->add_player_info(server, player, new_string(cmd))) !=
	  NULL)
	{
	  dprintf(player->fd, "%d\n%d %d\n", cinfo->remaining,
		  server->map->width, server->map->height);
	  if (server->gui->fd != -1 && player->fd != server->gui->fd)
	    dprintf(server->gui->fd, "PINFO %s %d %d 0 0 0 0 0 0 10\n",
		    player->name->__str, player->position.x, player->position.y);

	} else
	{
	  dprintf(player->fd, "ko\r\n");
	}
      return (1);
    }
  return (0);
}

static void		action_setup(t_server *server, t_player *player, char *cmd, int index)
{
  enum e_mineral	mineraln;
  int			todo_index;

  todo_index = -1;
  while (player->todo[++todo_index].action != C_NOTHING && todo_index < 10);
  if (todo_index >= 10)
    return ;
  if (client_cmd[index].name)
    {
      player->todo[todo_index].action = client_cmd[index].action;
      player->todo[todo_index].time = (client_cmd[index].time) + player->todo_time;
      player->todo_time = player->todo[todo_index].time;
      cmd = strtok(NULL, " \n");
      mineraln = UNKNOW;
      while (cmd != NULL && mineraln < MAX_MINERAL &&
	     strcmp(cmd, mineral_name[++mineraln]) > 0);
      player->todo[todo_index].mineral = mineraln;
      player->todo[todo_index].msg = new_string(cmd);
    }
  else
    {
      player->todo[todo_index].action = C_KO;
      player->todo[todo_index].time = player->todo_time;
    }
}

void			check_cmd_client(t_server *server, t_socket *socket)
{
  t_player		*player;
  char			*cmd;
  int			index;

  player = get_player(server, socket->fd_client);
  if ((cmd = socket->socket_receive(socket)) == NULL)
    return (void)server->death(server, player);
  if (check_team(player, server, (cmd = strtok(cmd, " \r\n"))))
    return ;
  index = 0;
  while (client_cmd[index].name != NULL && cmd &&
	 strcmp(client_cmd[index].name, cmd) != 0)
    index++;
  action_setup(server, player, cmd, index);
}