/*
** cmd.c for
**
** Made by Raphael Chriqui
** Login   <raphael.chriqui@epitech.net>
**
** Started on  Fri May 12 09:35:57 2017 Raphael Chriqui
** Last update Fri Jun  9 14:11:49 2017 Lheen Teck
*/

#include <string.h>
#include <stdio.h>
#include <Vector.h>
#include "cmd.h"

static const t_cmd	client_cmd[] =
  {
    { NULL, NULL }
  };

void			check_cmd_client(char *cmd, Server *srv)
{
  Vector		*resp;
  int			i;

  i = 0;
  if (cmd == NULL)
    return ;
  while (client_cmd[i].ptr != NULL &&
	  strcasecmp(client_cmd[i].cmd_name, cmd) != 0)
    i++;
  if (client_cmd[i].ptr && client_cmd[i].cmd_name)
    {
      resp = client_cmd[i].ptr();
      i = 0;
      while (i < resp->len(resp))
	srv->players->get(srv->players, ((t_response*)resp->get(resp, i))->name->__str);
    }
  else
    dprintf(get_socketi()->fd_client, "Command not found !\n");
}
