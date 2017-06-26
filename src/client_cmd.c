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
		{ "Left", C_LEFT, TIME_LEFT },
		{ "Right", C_RIGHT, TIME_RIGHT },
		{ "Look", C_LOOK, TIME_LOOK },
		{ "t_inv", C_INVENTORY, TIME_INVENTORY },
		{ "Broadcast", C_BROADCAST, TIME_BROADCAST },
		{ "Connect_nbr", C_UNUSED, TIME_UNUSED },
		{ "Fork", C_FORK, TIME_FORK },
		{ "Eject", C_EJECT, TIME_EJECT },
		{ "Take", C_TAKE, TIME_TAKE },
		{ "Set", C_SET, TIME_SET },
		{ "Incantation", C_INCANT, TIME_INCANT },
		{ NULL, C_NOTHING, 0 }
	};

static t_player		*get_player(Server *server, int fd)
{
  return (server->players->get(server->players, fd));
}

int			check_team(t_player *player, Server *server, char *cmd)
{
  t_connect_info	*cinfo;

  if (!player->team)
    {
      if ((cinfo = server->add_player_info(server, player, new_string(cmd))) !=
	  NULL)
	{
	  dprintf(player->fd, "%d\n%s\n", cinfo->remaining,
		  cinfo->coord->__str);
	} else
	{
	  dprintf(player->fd, "ko\r\n");
	}
      return (1);
    }
  return (0);
}

void			second_tick(Server *server, t_player *player)
{
//  Vector		*resp;
//  int			index;

//  resp = client_cmd[index].ptr(server, player);
//  index = 0;

  //TODO A REFAIRE TA FOIRE TES DPRINTF MDR
//  while (index < resp->len(resp))
//    dprintf(server->players->get(server->players, ((t_response*)resp->get(resp, index))->name->__str)->fd,
//	    ((t_response*)resp->get(resp, index))->msg->__str);
//
//
//  dprintf(server->players->get(server->players,
//			       ((t_response*)resp->get(resp, index))->name->get(((t_response*)resp->get(resp, index))->name))->fd,
//	  ((t_response*)resp->get(resp, index))->msg->get(((t_response*)resp->get(resp, index))->msg));
}

static void		action_setup(Server *server, t_player *player, char *cmd, int index)
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
      player->todo[todo_index].time = (client_cmd[index].time / server->freq) * player->todo_time;
      player->todo_time = player->todo[todo_index].time;
      cmd = strtok(NULL, " \n"); //TODO DAFUQ ??????
      mineraln = -1; //TODO ERROR HERE MINERAL DONT NOT HAVE -1
      while (mineraln < MAX_MINERAL && (cmd != mineral_name[++mineraln]));
      player->todo[todo_index].mineral = mineraln;
      player->todo[todo_index].msg = new_string(cmd);
    }
  else
    {
      player->todo[todo_index].action = C_KO;
      player->todo[todo_index].time = player->todo_time;
    }
}

void			check_cmd_client(Server *server, t_socket *socket)
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