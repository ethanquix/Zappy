/*
** cmd.h for Zappy
**
** Made by chriqu_r
** Login    <raphael.chriqui@epitech.net>
**
** Started on Wed Jun 21 12:54:00 2017 Raphael Chriqui
** Last update Wed Jun 21 12:54:00 2017 Raphael Chriqui
*/

#ifndef ZAPPY_CMD_H
#define ZAPPY_CMD_H

#include "Server.h"

typedef struct			s_cmd
{
  char				*cmd_name;
  Vector			*(*ptr)();
}				t_cmd;

void			check_cmd_client(char *cmd, Server *srv);

#endif //ZAPPY_CMD_H
