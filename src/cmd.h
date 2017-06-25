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
#include "config.h"

enum e_gui_cmd
{
  C_GET_TILEINFO
};

typedef struct			s_gui
{
  const char			*name;
  enum e_gui_cmd		action;
}				t_gui;

typedef struct			s_cmd
{
  const char			*name;
  enum e_cmd_nb			action;
  int				time;
}				t_cmd;

void			loop_todo(Server *server);

void			check_cmd_client(Server *srv, t_socket *socket);

#endif //ZAPPY_CMD_H
