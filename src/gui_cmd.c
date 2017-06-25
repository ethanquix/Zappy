/*
** gui_cmd.c for Zappy
**
** Made by chriqu_r
** Login    <raphael.chriqui@epitech.net>
**
** Started on Sun Jun 25 18:21:00 2017 Raphael Chriqui
** Last update Sun Jun 25 18:21:00 2017 Raphael Chriqui
*/

#include <Server.h>
#include "cmd.h"

static const t_gui	client_cmd[] =
	{
		{ NULL, 0, }
	};

void			check_cmd_gui(Server *server, t_socket *socket)
{
  Player		*player;
  char			*cmd;
  int			index;

  if ((cmd = socket->socket_receive(socket)) == NULL)
    return (void)(server->gui->fd = -1);
  index = 0;
  while (client_cmd[index].name != NULL && cmd &&
	 strcasecmp(client_cmd[index].name, cmd) != 0)
    index++;
  //TODO call gondor
}